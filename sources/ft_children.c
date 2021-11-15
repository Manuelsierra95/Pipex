/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_children.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:15:47 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/15 18:49:18 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


//Para el bonus, hacer un array tridimensional (***array) y meter los bloques de pipes
//antes haciendo un ft_countpipe()

//Controlar la ruta si me la dan por argumento


void	ft_execmd(char	*argv, t_pipex *pipex)
{
	char	*path;

	ft_getcmd(argv, pipex);
	path = ft_checkaccess(pipex);
	execve(path, pipex->cmd, pipex->env);
	perror("pipex");
	exit(errno);
}

void	ft_createchildren(t_pipex *pipex, char *argv)
{
	int		status;
	pid_t	pid;

	pipe(pipex->fd); //TODO: si devuelve -1 devolver error
	pid = fork();
	if(pid == 0)
	{
		close(pipex->fd[READ_END]);
		dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
		close(pipex->fd[WRITE_END]);
		ft_execmd(argv, pipex);
	}
	else
	{
		close(pipex->fd[WRITE_END]);
		dup2(pipex->fd[READ_END], STDIN_FILENO);
		close(pipex->fd[READ_END]);
		waitpid(pid, &status, 0);
	}
}

void	ft_exepipes(int argc, char **argv, t_pipex *pipex)
{
	int	i;

	i = 2;
	if(argc >= 5)
	{
		pipex->fd[F_IN] = open(pipex->infile, O_RDONLY);
		dup2(pipex->fd[F_IN], STDIN_FILENO);
		close(pipex->fd[F_IN]);
		while(i < argc - 2)
		{
			ft_createchildren(pipex, argv[i]);
			i++;
		}
		pipex->fd[F_OUT] = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		dup2(pipex->fd[F_OUT], STDOUT_FILENO);
		ft_execmd(argv[i], pipex);
	}
}
