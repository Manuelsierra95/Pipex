/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:00:50 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/16 18:01:51 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_END 0
# define WRITE_END 1
# define F_IN 0
# define F_OUT 1
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
typedef struct s_pipex
{
	char	**cmd;
	char	**path;
	char	**env;
	char	*infile;
	char	*outfile;
	int		fd[2];
	int		fd2[2];

}	t_pipex;
//	Includes
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putchar_fd(char c, int fd);
//	Sources
void	ft_putstringerror(char *str);
void	ft_getcmd(char *argv, t_pipex *pipex);
void	ft_createchildren(t_pipex *pipex, char *argv);
void	ft_exepipes(int argc, char **argv, t_pipex *pipex);
void	ft_getpath(t_pipex *pipex);
void	ft_getfile(char **argv, t_pipex *pipex);
char	*ft_checkaccess(t_pipex *pipex);
void	ft_joinpath(t_pipex *pipex);
void	ft_errormsg(int flag);
void	ft_badinfile(char *argv);
#endif
