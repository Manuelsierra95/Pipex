/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:13:00 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/07 17:39:39 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	a = malloc(count * size);
	if (!a)
		return (NULL);
	ft_bzero(a, (count * size));
	return (a);
}
