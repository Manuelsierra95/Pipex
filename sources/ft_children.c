/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_children.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:15:47 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/16 17:50:47 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_execmd(char	*argv, t_pipex *pipex)
{
	char	*path;
	int		flag;

	ft_getcmd(argv, pipex);
	path = ft_checkaccess(pipex);
	flag = execve(path, pipex->cmd, pipex->env);
	ft_errormsg(flag);
}

void	ft_createchildren(t_pipex *pipex, char *argv)
{
	int		status;
	int		flag;
	pid_t	pid;

	flag = pipe(pipex->fd);
	ft_errormsg(flag);
	pid = fork();
	ft_errormsg(flag);
	if (pid == 0)
	{
		close(pipex->fd[READ_END]);
		flag = dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
		ft_errormsg(flag);
		close(pipex->fd[WRITE_END]);
		ft_execmd(argv, pipex);
	}
	else
	{
		close(pipex->fd[WRITE_END]);
		flag = dup2(pipex->fd[READ_END], STDIN_FILENO);
		ft_errormsg(flag);
		close(pipex->fd[READ_END]);
		waitpid(pid, &status, 0);
	}
}

void	ft_openfd(t_pipex *pipex)
{
	pipex->fd[F_OUT] = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (pipex->fd[F_OUT] == -1)
		ft_errormsg(-1);
}

void	ft_exepipes(int argc, char **argv, t_pipex *pipex)
{
	int	i;

	i = 2;
	if (argc >= 5)
	{
		pipex->fd[F_IN] = open(pipex->infile, O_RDONLY);
		if (pipex->fd[F_IN] == -1)
			ft_errormsg(-1);
		dup2(pipex->fd[F_IN], STDIN_FILENO);
		close(pipex->fd[F_IN]);
		while (i < argc - 2)
		{
			ft_createchildren(pipex, argv[i]);
			i++;
		}
		ft_openfd(pipex);
		dup2(pipex->fd[F_OUT], STDOUT_FILENO);
		ft_execmd(argv[i], pipex);
	}
}
