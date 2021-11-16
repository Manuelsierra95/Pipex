/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:52:59 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/16 17:36:00 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// -1 errno / -2 infile / -3 args
void	ft_errormsg(int flag)
{
	if (flag == -1)
	{
		perror("pipex");
		exit(errno);
	}
	else if (flag == -2)
		ft_putstringerror("Error: Infile not supported");
	else if (flag == -3)
		ft_putstringerror("Error: Insufficient number of arguments");
}

void	ft_badinfile(char *argv)
{
	if (ft_strnstr(argv, "/random", ft_strlen(argv)))
	{
		ft_errormsg(-2);
	}
}
