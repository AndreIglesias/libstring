/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:41:03 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 15:34:04 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

static int	skip_spaces(const char *str, int pos, char c)
{
	while (str[pos] && str[pos] == c)
		pos++;
	return (pos);
}

static int	ft_count_letters(const char *str, int letrs, char c)
{
	while (str[letrs] && str[letrs] != c)
		letrs++;
	return (letrs);
}

static int	ft_count_wordsc(const char *str, int spos, int cont, char c)
{
	spos = skip_spaces(str, spos, c);
	if (!str[spos])
		return (cont);
	while (str[spos] && str[spos] != c)
		spos++;
	return (ft_count_wordsc(str, spos, cont + 1, c));
}

static char	**ft_decomposec(char **tab, char *str, int spos, char c)
{
	int	letrs;
	int	i;
	int	tpos;

	tpos = 0;
	while (str[spos])
	{
		spos = skip_spaces(str, spos, c);
		if (!str[spos])
			break ;
		letrs = ft_count_letters(str, spos, c);
		tab[tpos] = (char *)malloc(sizeof(char) * (letrs + 1 - spos));
		if (!tab[tpos])
			return (0);
		i = 0;
		while (str[spos] && str[spos] != c)
		{
			tab[tpos][i] = str[spos];
			spos++;
			i++;
		}
		tab[tpos++][i] = '\0';
	}
	tab[tpos] = 0;
	return (tab);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**tab;

	if (s)
	{
		tab = malloc(sizeof(char *) * (ft_count_wordsc(s, 0, 0, c) + 1));
		if (!tab)
			return (NULL);
		return (ft_decomposec(tab, (char *)s, 0, c));
	}
	return (NULL);
}
