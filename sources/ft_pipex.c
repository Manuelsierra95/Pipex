/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:06:32 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/15 18:44:50 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

//TODO: Control de errores
	pipex.env = env;
	ft_getpath(&pipex);
	ft_joinpath(&pipex);
	ft_getfile(argv, &pipex);
	ft_exepipes(argc, argv, &pipex);
}
