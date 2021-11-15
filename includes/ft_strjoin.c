/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:09:58 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/08 14:03:36 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		size1;
	int		size2;
	
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	a = malloc((size1 + size2 + 1) * sizeof(char));
	if (!a)
		return (NULL);
	ft_memcpy(a, s1, size1);
	ft_memcpy(a + size1, s2, size2);
	a[size1 + size2] = '\0';
	return (a);
}
