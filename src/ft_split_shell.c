/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:02:43 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/20 12:21:06 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* En casos como una comilla pegada a palabras en posicion inesperada como:
"Pongo una comilla aqui' pero no la cierro" la funcion se piensa que
forma parte del final de esa palabra. No se si gestionar esto o no. Tampoco
creo que funcione bien si hay dos comillas pegadas de diferentes scopes*/

#include "libft.h"

static bool	is_metachar(char c)
{
	if (
		c == '|' || c == '<' || c == '>' || c == ' ' || c == '"' || c == '\''
	)
		return (true);
	return (false);
}

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

int	stract_arg(char *line, char ***split_ptr)
{
	int		position;
	char	*arg;

	position = 1;
	if (*line == '"' || *line == '\'')
	{
		while (line[position] != *line)
			if (!line[position++])
				return (perror(ERR_SYNTAX), -1);
		position++;
	}
	else if (*line == '<' || *line == '>')
	{
		if (line[position] == *line)
			position += 1;
	}
	else if (*line != '|')
		while (!is_metachar(line[position]) && line[position])
			position++;
	arg = ft_substr(line, 0, position);
	if (!arg)
		return (perror(0), -1);
	if (add_string(arg, split_ptr))
		return (free(arg), -1);
	return (position);
}

char	**ft_split_shell(char *line, char separator)
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
			position = stract_arg(line, &split);
			if (position == -1)
				return (ft_splitfree(split), NULL);
			line += position;
		}
	}
	return (split);
}

/* int	main(void)
{
	char	*str = "   Hola<j   ";
	char	**split;

	split = ft_split_shell(str, ' ');
	if (!split)
		exit(0);
	while (*split)
		ft_printf("%s\n", *(split++));
	return (0);
} */
