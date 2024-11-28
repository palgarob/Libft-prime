/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:07:16 by pepaloma          #+#    #+#             */
/*   Updated: 2024/11/28 18:09:04 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_double(const char *str)
{
	char	**split;
	int		i;

	if (!str || !*str)
		return (false);
	split = splitstr(str, '.');
	if (!split)
		return (ft_printf("Split error\n"), false);
	if (splitlen(split) == 1 && is_number(split[0]))
		return (free_split(split), true);
	if (splitlen(split) != 2)
		return (free_split(split), false);
	if (split[0][0] == '-' && split[0][1] == '\0')
		return (free_split(split), false);
	if (split[0][0] == '-' && !is_number(split[0] + 1))
		return (free_split(split), false);
	if (split[0][0] != '-' && !is_number(split[0]))
		return (free_split(split), false);
	i = -1;
	while (split[1][++i])
	{
		if (!ft_isdigit(split[1][i]))
			return (free_split(split), false);
	}
	return (free_split(split), true);
}
