/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:56:18 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/07 10:57:23 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_coord(char **split)
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
