/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:40:47 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 15:40:12 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

static int	ft_condition(char const *s, int i)
{
	return (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'));
}

char	*ft_strtrim(char const *s)
{
	int		ls;
	int		sb;
	int		i;
	char	*copy;
	char	*str;

	if (!s)
		return (NULL);
	ls = ft_strlen(s);
	i = 0;
	while (ft_condition(s, i))
		i++;
	sb = i;
	if (sb == ls)
		return (ft_strdup(""));
	copy = (char *)&s[i];
	i = ls - 1;
	while (ft_condition(s, i))
		i--;
	str = ft_strnew(i - sb + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, copy, i - sb + 1);
	return (str);
}
