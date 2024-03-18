/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:02:43 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/18 17:14:18 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_delimiter(char c, char *s)
{
	while (*s)
	{
		if (*s = c)
			return (true);
		s++;
	}
	return (false);
}

unsigned long	count_substrings(char *string, char *separators, char *delimiters)
{
	unsigned long		n_substrings;

	n_substrings = 0;
	string--;
	while (*++string)
	{
		if (is_in_group(*string, delimiters))
		{
			while (*string != )
		}
	}
}

char	**ft_split_delimiter(char *string, char *separators, char *delimiters)
{
	char			**split_string;
	unsigned long	n_substrings;

	n_substrings = count_substrings(string, separators, delimiters);
	split_string = (char **)malloc(sizeof(char *) * (n_substrings + 1));
	if (!split_string)
		return (ft_error_ptr("ft_split_delimiter", 0, 0));
	if (store_substrings(split_string, string, separators, delimiters))
		return (free(split_string), NULL);
	return (split_string);
}


