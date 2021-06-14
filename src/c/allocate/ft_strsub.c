/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:40:53 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 15:40:56 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s)
	{
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		i = start;
		while (i - start < len)
		{
			str[i - start] = s[i];
			i++;
		}
		str[i - start] = '\0';
		return (str);
	}
	return (NULL);
}
