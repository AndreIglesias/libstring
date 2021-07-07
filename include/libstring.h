/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstring.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:06:57 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/07 14:43:57 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRING_H
# define LIBSTRING_H

# include "libtypes.h"

/*
**	ASM
*/

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

/*
**	C
*/

/*
**		str
*/

char	*ft_strcat(char *restrict s1, const char *restrict s2);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
int		ft_strcmpn(const char *s1, const char *s2, const char *lim);
void	ft_strdel(char **as);
int		ft_strequ(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char *));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_fstrjoin(char *s1, char *s2);
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strrev(char *str, int size);
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);

/*
**		mem
*/

void	ft_memdel(void **ap);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memins(void **restrict mem, const void *restrict ins,
			size_t pos, t_sizes sizes);
void	strins(char array[][256], char *str, size_t pos, size_t size);

/*
**		others
*/

void	ft_bzero(void *s, size_t n);
int		ft_countchr(const char *s, int c);

#endif
