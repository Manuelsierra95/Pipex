/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:06:32 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/16 17:47:56 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex.env = NULL;
	if (argc < 5)
		ft_errormsg(-3);
	ft_badinfile(argv[1]);
	if (env[0] != NULL)
	{
		pipex.env = env;
		ft_getpath(&pipex);
		ft_joinpath(&pipex);
	}
	ft_getfile(argv, &pipex);
	ft_exepipes(argc, argv, &pipex);
}
