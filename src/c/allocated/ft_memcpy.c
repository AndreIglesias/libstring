/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:44:52 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/03 20:12:04 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

static void	longcpy(unsigned char **udst, unsigned char **usrc, size_t *n)
{
	long	*ldst;
	long	*lsrc;

	ldst = (long *)(*udst);
	lsrc = (long *)(*usrc);
	while ((*n) >= sizeof(long) * 4)
	{
		ldst[0] = lsrc[0];
		ldst[1] = lsrc[1];
		ldst[2] = lsrc[2];
		ldst[3] = lsrc[3];
		ldst += 4;
		lsrc += 4;
		(*n) -= sizeof(long) * 4;
	}
	while ((*n) >= sizeof(long))
	{
		*ldst++ = *lsrc++;
		(*n) -= sizeof(long);
	}
	(*udst) = (unsigned char *)ldst;
	(*usrc) = (unsigned char *)lsrc;
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*udst;
	unsigned char	*usrc;
	t_uintptr		pdst;
	t_uintptr		psrc;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	pdst = (t_uintptr)dst;
	psrc = (t_uintptr)src;
	if (n >= sizeof(long) * 2
		&& (pdst & (sizeof(long) - 1)) == (pdst & (sizeof(long) - 1)))
	{
		while (((t_uintptr)usrc & (sizeof(long) - 1)) != 0)
		{
			*udst++ = *usrc++;
			n--;
		}
		longcpy(&udst, &usrc, &n);
	}
	while (n--)
		*udst++ = *usrc++;
	return (dst);
}

/*
**void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
**{
**	unsigned int	i;
**	unsigned char	*copy;
**	unsigned char	*cpsrc;
**
**	copy = (unsigned char *)dst;
**	cpsrc = (unsigned char *)src;
**	i = 0;
**	while (i < n)
**	{
**		*(copy + i) = *(cpsrc + i);
**		i++;
**	}
**	dst = (void *)copy;
**	return (dst);
**}
*/
