/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:20:41 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/07 17:45:01 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_counts(char *s, char c);
static char	**ft_matrix(char *s, char c, size_t n);
static char	**ft_empty_matrix(void);
static char	**free_matrix(char **mat, size_t last_index);

char	**ft_split(char *s, char c)
{
	size_t	i;
	char	**matrix;

	i = 0;
	if (!s)
		return (NULL);
	matrix = ft_matrix(s, c, ft_counts(s, c));
	return (matrix);
}

static int	ft_counts(char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	tok;

	tok = 1;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (tok == 1 && s[i] != c)
		{
			tok = 0;
			count++;
		}
		else if (tok == 0 && s[i] == c)
			tok = 1;
		i++;
	}
	return (count);
}

static char	**ft_matrix(char *s, char c, size_t n)
{
	size_t	content;
	size_t	row;
	size_t	i;
	char	**matrix;

	i = 0;
	row = 0;
	matrix = malloc((n + 1) * sizeof(char *));
	if (!matrix)
		return (ft_empty_matrix());
	while (row < n && s[content])
	{
		content = 0;
		while (s[i] == c)
			i++;
		while (s[content + i] && s[content + i] != c)
			content++;
		matrix[row] = ft_substr(s, i, (content));
		if (!matrix[row])
			return (free_matrix(matrix, (row)));
		i = i + content;
		row++;
	}
	matrix[row] = NULL;
	return (matrix);
}

static char	**free_matrix(char **mat, size_t last_index)
{
	while (last_index >= 0)
	{
		if (mat[last_index])
			free(mat[last_index]);
		last_index--;
	}
	free(mat);
	return (NULL);
}

static char	**ft_empty_matrix(void)
{
	char	**mat;

	mat = (char **) ft_calloc(1, sizeof(char *));
	if (!mat)
		return (NULL);
	mat[0] = 0;
	return (mat);
}
