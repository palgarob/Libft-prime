/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:54:52 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/29 13:56:15 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int good_format(char **split)
{
	int i;
	int n;

	if (splitlen(split) != 3 || !is_double(split[0]) || !is_double(split[1]) || !is_double(split[2]))
		return (0);
	i = -1;
	while (++i < 3)
	{
		n = ft_atoi(split[i]);
		if (n < 0 || n > 255)
			return (0);
	}
	return (1);
}

bool	is_rgb(t_color *dst, char *org)
{
	char	**split;

	split = splitstr(org, ',');
	if (!split)
		return (false);
	if (!good_format(split))
		return (splitfree(split), false);
	*dst = color((double)ft_atoi(split[0]) / 255.0, (double)ft_atoi(split[1]) / 255.0,
			(double)ft_atoi(split[2]) / 255.0);
	return (splitfree(split), true);
}
