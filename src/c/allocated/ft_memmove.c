/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:44:43 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 18:03:44 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*copy;
	unsigned char	*cpsrc;

	copy = (unsigned char *)dst;
	cpsrc = (unsigned char *)src;
	i = 0;
	if (cpsrc > copy)
	{
		while (i < len)
		{
			*(copy + i) = *(cpsrc + i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*(copy + len - 1) = *(cpsrc + len - 1);
			len--;
		}
	}
	return (copy);
}
