/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:41:08 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 15:36:53 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

char	*ft_strrev(char *str, int size)
{
	int		i;
	char	temp;
	char	*copy;

	copy = ft_strnew(size);
	if (!copy)
		return (NULL);
	ft_strcpy(copy, str);
	i = 0;
	size--;
	while (size > i)
	{
		temp = copy[size];
		copy[size] = copy[i];
		copy[i] = temp;
		i++;
		size--;
	}
	str = copy;
	return (str);
}
