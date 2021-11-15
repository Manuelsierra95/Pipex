/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_children_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:53:24 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/13 15:21:41 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


void	ft_execmd(char	*argv, t_pipex *pipex)
{
	char	*path;

	ft_getcmd(argv, pipex);
	path = ft_checkaccess(pipex);

	// write(1, path, ft_strlen(path));
	// write(1, "\n", 1);
	// write(2, path, ft_strlen(path));
	// write(2, "\n", 1);
	// write(2, pipex->cmd[1], 1);
	// write(2, "\n", 1);


	execve(path, pipex->cmd, pipex->env);
	// perror("pipex");
	// exit(errno);
}

void	ft_createchildren(t_pipex *pipex, char *argv)
{
	int		status;
	pid_t	pid;
	int fd[2];

	// char	buf[20];

		// read(STDIN_FILENO, buf, 20);
		// write(1, "Tiene: ", 8);
		// write(1, buf, strlen(buf));
		// write(1, "\n", 1);

	pipe(fd); //TODO: si devuelve -1 devolver error
	pid = fork();
	// printf("Valor de pid: %d\n", pid);
	if(pid == 0)//hijo 1
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);

		// write(2, "Hijo: ", 7);
		// read(STDIN_FILENO, buf, 20);
		// write(2, buf, strlen(buf));
		// write(2, "\n", 1);
		
		ft_execmd(argv, pipex);
	}
	// else if(pid < 0)
	// 	ft_error();
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		
		// read(STDIN_FILENO, buf, 20);
		// write(2, "Sale: ", 7);
		// write(2, buf, strlen(buf));
		// write(2, "\n", 1);
		
		
		waitpid(pid, &status, WNOHANG);
	}
}

void	ft_exepipes(int argc, char **argv, t_pipex *pipex)
{
	int	i;
	// int	fd[2];

	i = 2;
	if(argc >= 5)
	{
	// printf("Valor de infile: %s\n", pipex->infile);
		pipex->fd[F_IN] = open(pipex->infile, O_RDONLY);
	// printf("Valor de file1: %d\n", pipex->fd[F_IN]);
	
		dup2(pipex->fd[F_IN], STDIN_FILENO);
		close(pipex->fd[F_IN]);

		while(i < argc - 2)
		{
			ft_createchildren(pipex, argv[i]);
			i++;
		}
		pipex->fd[F_OUT] = open(pipex->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		// printf("Outfile: %s\n", pipex->outfile);
		// printf("Valor de file2: %d\n", pipex->fd[F_OUT]);
		dup2(pipex->fd[F_OUT], STDOUT_FILENO);
		close(pipex->fd[F_OUT]);
		// dup2(pipex->fd[F_IN], STDIN_FILENO);
		// char	buf[18];
		// read(STDIN_FILENO, buf, 18);
		// write(2, buf, 18);
		
		ft_execmd(argv[i], pipex);
	}
}