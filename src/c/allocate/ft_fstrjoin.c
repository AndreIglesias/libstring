/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:39:19 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 19:03:30 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

char	*ft_fstrjoin(char *s1, char *s2)
{
	char	*str;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_memalloc(len);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	free(s1);
	return (str);
}
