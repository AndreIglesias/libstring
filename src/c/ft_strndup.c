/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:41:37 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 15:35:08 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*blank;

	blank = ft_strnew(n);
	if (!blank)
		return (NULL);
	ft_strncpy(blank, s, n);
	return (blank);
}
