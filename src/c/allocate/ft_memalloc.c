/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:45:12 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 16:55:07 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = malloc(sizeof(fresh) * (size));
	if (!fresh)
		return (NULL);
	ft_memset(fresh, 0, size);
	return (fresh);
}
