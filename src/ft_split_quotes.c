/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:02:43 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/19 12:52:34 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add_string(char *new_string, char ***split_ptr)
{
	int		len;
	char	**cpy;

	len = ft_split_len(*split_ptr);
	if (!len)
	{
		*split_ptr = (char **)malloc(sizeof(char *) * 2);
		**split_ptr = ft_strdup(new_string);
		*(*split_ptr + 1) = NULL;
	}
	else
	{
		cpy = (char **)malloc(sizeof(char *) * (len + 2));
		ft_splitcpy(*split_ptr, cpy);
		free(*split_ptr);
		cpy[len + 1] = ft_strdup(new_string);
		cpy[len + 2] = NULL;
		*split_ptr = cpy;
	}
}



char	**ft_split_quotes(char *line, char separator)
{
	char	**split;
	int		pos1;
	int		pos2;
	

	split = NULL;
	pos1 = 0;
	while (line[pos1])
	{
		if (line[pos1] == ' ')
			pos1++;
		else if (line[pos1] == 39)
		{
			pos2 = pos1 + 1;
			while (line[pos2++] != 39);
			add_string(ft_substr(line, pos1, pos2 - pos1), &split);
			pos1 = pos2;
		}
		else if (line[pos1] == 34)
		{
			pos2 = pos1 + 1;
			while (line[pos2++] != 34);
			add_string(ft_substr(line, pos1, pos2 - pos1), &split);
			pos1 = pos2;
		}
		else
		{
			pos2 = pos1;
			while(line[++pos2] != 32);
			add_string(ft_substr(line, pos1, pos2 - pos1), &split);
		}
	}
	return (split);
}


