/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:02:43 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/19 16:36:27 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* En casos como una comilla pegada a palabras en posicion inesperada como:
"Pongo una comilla aqui' pero no la cierro" la funcion se piensa que
forma parte del final de esa palabra. No se si gestionar esto o no*/

#include "libft.h"

static int	add_string(char *new_string, char ***split_ptr)
{
	int		len;
	char	**cpy;

	len = ft_splitlen(*split_ptr);
	cpy = (char **)malloc(sizeof(char *) * (len + 2));
	if (!cpy)
		return (free(new_string), perror(0), 1);
	ft_splitcpy(*split_ptr, cpy);
	free(*split_ptr);
	cpy[len] = new_string;
	cpy[len + 1] = NULL;
	*split_ptr = cpy;
	return (0);
}

int	stract_arg(char *line, char quote, char ***split_ptr)
{
	int		position;
	char	*arg;

	position = 0;
	if (quote)
	{
		while (line[position] != quote)
			if (!line[position++])
				return (perror(ERR_SYNTAX), -1);
		arg = ft_substr(line, 0, position);
	}
	else
	{
		while (line[++position] != 32 && line[position])
			;
		arg = ft_substr(line, 0, position);
	}
	if (!arg)
		return (ft_error("", 0, 0, -1));
	if (add_string(arg, split_ptr))
		return (free(arg), -1);
	if (quote)
		position += 1;
	return (position);
}

char	**ft_split_quotes(char *line, char separator)
{
	char	**split;
	int		position;

	split = (char **)malloc(sizeof(char *) * 1);
	*split = NULL;
	while (*line)
	{
		if (*line == ' ')
			line++;
		else
		{
			if (*line == 39)
				position = stract_arg(++line, 39, &split);
			else if (*line == 34)
				position = stract_arg(++line, 34, &split);
			else
				position = stract_arg(line, 0, &split);
			if (position == -1)
				return (ft_splitfree(split), NULL);
			line += position;
		}
	}
	return (split);
}

/* int	main(void)
{
	char	*str = "Me dijo:          'Como estas? yo le dije 'que ' bien ";
	char	**split;

	split = ft_split_quotes(str, ' ');
	if (!split)
		exit(0);
	while (*split)
		ft_printf("%s\n", *(split++));
	return (0);
} */
