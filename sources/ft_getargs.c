/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:10:20 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/15 18:27:03 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_getpath(t_pipex *pipex)
{
	int		x;

	x = 0;
	while(pipex->env[x])
	{
		if(ft_strncmp(pipex->env[x], "PATH", 4) == 0)
			pipex->path = ft_split(ft_strchr(pipex->env[x], '/'), ':');
		x++;
	}
}

void	ft_getcmd(char *argv, t_pipex *pipex)
{
	pipex->cmd =  ft_split(argv, ' ');
}

void	ft_getfile(char **argv, t_pipex *pipex)
{
	pipex->infile = argv[1];
	pipex->outfile = argv[4];
}


// void	ft_getcmd_bonus(int argc, char **argv, t_pipex *pipex)
// {
// 	int		x;
// 	int		y;
// 	int		i;

// 	x = 1;
// 	i = 0;
// 	while(x < argc)
// 	{
// 		y = 0;
// 		while(argv[x][y])
// 		{
// 			if(argv[x][y] == ' ')
// 			{
// 				pipex->cmd[0] = ft_substr(argv[x], 0, i);
// 				pipex->cmd[1] = ft_substr(argv[x], i + 1, ft_strlen(argv[x]));
// 			}
// 			i++;
// 			y++;
// 		}
// 		x++;
// 	}
// }