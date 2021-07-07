/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strins.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:26:48 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/07 19:43:02 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

/*
**	strins(&ls->files, &hola, 0, ls->size_f);
*/

/*
**void	strins(char ***array, char **str, size_t pos, size_t size)
**{
**	ft_memins((void **)array, str, sizeof(char *) * pos,
**		(t_sizes){sizeof(char *) * size, sizeof(char **)});
**}
*/

void	strins(char array[][256], char *str, size_t pos, size_t size)
{
	long	last;

	if (size == 0)
	{
		array[pos][0] = 0;
		ft_strcpy(array[pos], str);
		return ;
	}
	last = (long)size;
	last--;
	while (4 <= (last - (long)pos) && 0 <= (last - (long)pos))
	{
		array[last + 1][0] = 0;
		ft_strcpy(array[last + 1], array[last]);
		array[last][0] = 0;
		ft_strcpy(array[last], array[last - 1]);
		array[last - 1][0] = 0;
		ft_strcpy(array[last - 1], array[last - 2]);
		array[last - 2][0] = 0;
		ft_strcpy(array[last - 2], array[last - 3]);
		last -= 4;
	}
	while ((long)pos <= last && 0 <= last)
	{
		array[last + 1][0] = 0;
		ft_strcpy(array[last + 1], array[last]);
		last--;
	}
	array[pos][0] = 0;
	ft_strcpy(array[pos], str);
}
