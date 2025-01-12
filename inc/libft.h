/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:22:25 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/12 20:22:26 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>

# define HEXADECIMAL_LO "0123456789abcdef"
# define HEXADECIMAL_UP "0123456789ABCDEF"
# define DECIMAL "0123456789"
# define RAD2DEG (M_PI / 360.0 * 2)
# define DEG2RAD (360 / M_PI / 2)
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Linked lists
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

bool		is_number(char *str);
bool		is_double(const char *str);

// is_something
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int is_rgb(char **split);
int is_coord(char **split);
int is_normalized_vec(char *vec);

// memory
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *s, int c, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

// string
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strins(char **str_ptr, int snip_l, int snip_r, char *str_insert);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_gnl(char *s1, char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);

int			ft_atoi(const char *str);
int			a2i(char *str, int *n);
int			a2uc(char *str, unsigned char *n);
char		*ft_itoa(int n);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*get_next_line(int fd);
int			ft_strcmp(const char *s1, const char *s2);
double		to_double(const char *str);

// linked_lists
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lst2ndlast(t_list *lst);
t_list		*ft_lstcpy(t_list *lst, void (*del)(void *));

int			ft_printf(char const *format, ...);
int			ft_print_hex(unsigned int n, int lcase);
int			ft_print_char(int c);
int			ft_print_str(char *str);
int			ft_print_ptr(void *ptr);
int			ft_print_dec(int n);
int			ft_print_uns(unsigned int n);

int	ft_dprintf(int fd, char const *s, ...);

// split
char		**splitstr(char const *s, char c);
size_t		splitlen(char **array);
void		splitcpy(char **src, char **dst);
void		splitfree(char **split);
char		**splitlast(char **split);
int			splitadd(char *new_string, char ***split_ptr);
char		**splitdup(char **src);

#endif
