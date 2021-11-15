/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:52:59 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/15 18:48:50 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//TODO: 
//Controlar si me meten la direccion directamente en el argumento (Hacer un access antes de buscar con el path)
//Controlar que el infile no sea /dev/random
//

void	ft_errormsg(void)
{
	char	*error;
	int		i;

	i = 0;
	error = "Error";
	while(error[i])
	{
		write(1, &error[i], 1);
		i++;
	}
	exit(1);
}

void	ft_badinfile(char *argv)
{
	if(ft_strncmp(argv, "/random", ft_strlen(argv)))
	{
		ft_errormsg();
	}
}
