/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:17:23 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/15 18:31:48 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_joinpath(t_pipex *pipex)
{
	int		i;

	i = 0;
	while(pipex->path[i])
	{
		pipex->path[i] = ft_strjoin(pipex->path[i], "/");
		i++;
	}
}

char	*ft_checkcmdacc(t_pipex *pipex)
{
	int	flag;

	if(strchr(pipex->cmd[0], '/'))
	{
		flag = access(pipex->cmd, X_OK);
		if(flag == 0)
			return(1);
		else
			ft_errormsg(); //TODO: Error with exit
	}
	
}

char	*ft_checkaccess(t_pipex *pipex)
{
	int		flag;
	int		i;
	char	*path;

	i = 0;
	if(ft_checkcmdacc(pipex))
	{
		path = pipex->cmd[0];
		return(path);
	}
	while(pipex->path[i])
	{
		path = ft_strjoin(pipex->path[i], pipex->cmd[0]);
		flag = access(path, X_OK);
		if(flag == 0)
			return (path);
		else
			ft_errormsg(); //TODO: Error with exit
		i++;
	}
	return (0);
}
