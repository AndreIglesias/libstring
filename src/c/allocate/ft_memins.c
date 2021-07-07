/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:17:46 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/06 21:06:41 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

void	*ft_memins(void **restrict mem, const void *restrict ins,
				size_t pos, t_sizes sizes)
{
	unsigned char	*umem;
	unsigned char	*uins;
	unsigned char	*tmp;

	if (pos <= sizes.s1)
	{
		umem = (unsigned char *)(*mem);
		uins = (unsigned char *)ins;
		tmp = (unsigned char *)malloc(sizes.s1 + 1);
		tmp[sizes.s1] = 0;
		ft_memcpy(tmp, umem, pos);
		ft_memcpy(tmp + pos, uins, sizes.s2);
		ft_memcpy(tmp + pos + sizes.s2, umem + pos, sizes.s1 - pos);
		free(*mem);
		*mem = tmp;
		return (tmp);
	}
	return (*mem);
}
