/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:00:01 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/03 20:26:10 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitadd(char *new_string, char ***split_ptr)
{
	int		len;
	char	**new_split;

	if (!*split_ptr)
	{
		*split_ptr = (char **)malloc(sizeof(char *));
		**split_ptr = NULL;
	}
	len = ft_splitlen(*split_ptr);
	new_split = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new_split)
		return (perror(0), 1);
	ft_splitcpy(*split_ptr, new_split);
	free(*split_ptr);
	new_split[len] = new_string;
	new_split[len + 1] = NULL;
	*split_ptr = new_split;
	return (0);
}
