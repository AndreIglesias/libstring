/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:33:20 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 22:02:29 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*copy;

	i = 0;
	copy = (unsigned char *)s;
	while (i < n)
		*(copy + (i++)) = '\0';
	s = (void *)copy;
}
