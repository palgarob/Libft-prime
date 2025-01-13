/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:56:18 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 19:53:14 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int good_format(char **split)
{
	int i;

	if (splitlen(split) != 3)
		return (0);
	i = -1;
	while (++i < 3)
		if (!is_double(split[i]))
			return (0);
	return (1);
}

int	is_coord(t_vec *dst, char *src)
{
	char **split;

	split = splitstr(src, ',');
	if (!split)
		return (1);
	if (!good_format(split))
		return (splitfree(split), 0);
	dst->x = to_double(split[0]);
	dst->y = to_double(split[1]);
	dst->z = to_double(split[2]);
	return (splitfree(split), 1);
}
