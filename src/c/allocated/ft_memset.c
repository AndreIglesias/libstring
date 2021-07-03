/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:44:40 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/03 12:23:06 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

/*
**	write 8 t_u_long cccc per iteration until < than 8 remain
*/

static void	bwritex(size_t len, long int *dstp, t_u_long cccc)
{
	size_t	xlen;

	xlen = len / ((sizeof(t_u_long)) * 8);
	while (xlen > 0)
	{
		((t_u_long *)(*dstp))[0] = cccc;
		((t_u_long *)(*dstp))[1] = cccc;
		((t_u_long *)(*dstp))[2] = cccc;
		((t_u_long *)(*dstp))[3] = cccc;
		((t_u_long *)(*dstp))[4] = cccc;
		((t_u_long *)(*dstp))[5] = cccc;
		((t_u_long *)(*dstp))[6] = cccc;
		((t_u_long *)(*dstp))[7] = cccc;
		(*dstp) += 8 * (sizeof(t_u_long));
		xlen -= 1;
	}
}

/*
**	write 1 t_u_long per iteration until < than (sizeof(t_u_long)) bytes remain
*/

static size_t	bwrite(size_t len, long int *dstp, t_u_long cccc)
{
	size_t	xlen;

	len %= (sizeof(t_u_long)) * 8;
	xlen = len / (sizeof(t_u_long));
	while (xlen > 0)
	{
		((t_u_long *)(*dstp))[0] = cccc;
		(*dstp) += (sizeof(t_u_long));
		xlen -= 1;
	}
	len %= (sizeof(t_u_long));
	return (len);
}

/*
**	write last few bytes
*/

static void	blast_bytes(size_t len, long int *dstp, int c)
{
	while (len > 0)
	{
		((t_byte *)(*dstp))[0] = c;
		dstp += 1;
		len -= 1;
	}
}

void	*ft_memset (void *dstpp, int c, size_t len)
{
	long int	dstp;
	t_u_long	cccc;

	dstp = (long int) dstpp;
	if (len >= 8)
	{
		cccc = (unsigned char) c;
		cccc |= cccc << 8;
		cccc |= cccc << 16;
		if ((sizeof(t_u_long)) > 4)
			cccc |= (cccc << 16) << 16;
		while (dstp % (sizeof(t_u_long)) != 0)
		{
			((t_byte *)dstp)[0] = c;
			dstp += 1;
			len -= 1;
		}
		bwritex(len, &dstp, cccc);
		len = bwrite(len, &dstp, cccc);
	}
	blast_bytes(len, &dstp, c);
	return (dstpp);
}

/*
**  void	*ft_memset(void *b, int c, size_t len)
**{
**	unsigned int	i;
**	unsigned char	*copy;
**
**	copy = (unsigned char *)b;
**	i = 0;
**	while (i < len)
**		*(copy + (i++)) = (unsigned char)c;
**	b = (void *)copy;
**	return (b);
**}
*/
