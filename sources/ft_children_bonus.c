/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_children_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:53:24 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/16 17:29:28 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


void	ft_execmd_b(char	*argv, t_pipex *pipex)
{
	char	*path;
	int		flag;

	ft_getcmd(argv, pipex);
	path = ft_checkaccess(pipex);
	flag = execve(path, pipex->cmd, pipex->env);
	ft_errormsg(flag);
}

void	ft_createchildren_b(t_pipex *pipex, char *argv)
{
	int		status;
	int		flag;
	pid_t	pid;

	flag = pipe(pipex->fd);
	ft_errormsg(flag);
	pid = fork();
	ft_errormsg(flag);
	if(pid == 0)
	{
		close(pipex->fd[READ_END]);
		flag = dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
		ft_errormsg(flag);
		close(pipex->fd[WRITE_END]);
		ft_execmd_b(argv, pipex);
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

void	ft_createchildren_b2(t_pipex *pipex, char *argv)
{
	int		status;
	int		flag;
	pid_t	pid;

	flag = pipe(pipex->fd);
	ft_errormsg(flag);
	pid = fork();
	ft_errormsg(flag);
	if(pid == 0)
	{
		system("lsof -c pipex");
		printf("--------------\n");
		close(pipex->fd2[READ_END]);
		flag = dup2(pipex->fd[READ_END], STDIN_FILENO);
		ft_errormsg(flag);
		close(pipex->fd2[READ_END]);
		dup2(pipex->fd2[WRITE_END], STDOUT_FILENO);
		close(pipex->fd2[WRITE_END]);
		ft_execmd_b(argv, pipex);
	}
	waitpid(pid, &status, 0);

}

void	ft_exepipes_b(int argc, char **argv, t_pipex *pipex)
{
	int	i;

	i = 2;
	if(argc >= 5)
	{
		pipex->fd[F_IN] = open(pipex->infile, O_RDONLY);
		if(pipex->fd[F_IN] == -1)
			ft_errormsg(-1);
		dup2(pipex->fd[F_IN], STDIN_FILENO);
		close(pipex->fd[F_IN]);
		while(i < argc - 2)
		{
			if(argc == 2)
			{
				ft_createchildren_b(pipex, argv[i]);
				i++;
			}
			else
			{
				ft_createchildren_b2(pipex, argv[i]);
				i++;
				close(pipex->fd[READ_END]);
				close(pipex->fd2[WRITE_END]);
				pipex->fd[F_IN] = pipex->fd2[F_IN];
				pipex->fd[F_OUT] = pipex->fd2[F_OUT];	
			}
		}
		pipex->fd[F_OUT] = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if(pipex->fd[F_OUT] == -1)
			ft_errormsg(-1);
		dup2(pipex->fd[F_OUT], STDOUT_FILENO);
		ft_execmd_b(argv[i], pipex);
	}
}
