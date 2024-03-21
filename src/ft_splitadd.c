/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:00:01 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/21 14:21:05 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitadd(char *new_string, char ***split_ptr)
{
	int		len;
	char	**cpy;

	if (!*split_ptr)
	{
		*split_ptr = (char **)malloc(sizeof(char *));
		**split_ptr = NULL;
	}
	len = ft_splitlen(*split_ptr);
	cpy = (char **)malloc(sizeof(char *) * (len + 2));
	if (!cpy)
		return (perror(0), 1);
	ft_splitcpy(*split_ptr, cpy);
	free(*split_ptr);
	cpy[len] = new_string;
	cpy[len + 1] = NULL;
	*split_ptr = cpy;
	return (0);
}
