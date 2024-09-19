/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:29:20 by jmenard           #+#    #+#             */
/*   Updated: 2024/07/26 16:27:19 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<stdarg.h>
# include<stdbool.h>

typedef struct s_list
{
	long int		content;
	int				target;
	int				cost;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strnstr(const char *big, const char *little, size_t len);
char				*ft_itoa(int n);
char				**ft_split(char *str, char charset);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
t_list				*ft_lstnew(long int content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, long int (*f)(long int), void (*del)(long int));

void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(long int));
void				ft_lstclear(t_list **lst, void (*del)(long int));
void				ft_lstiter(t_list *lst, void (*f)(long int));

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_lstsize(t_list *lst);
int					ft_printf(const char *str, ...);
int					ft_format(va_list argument, const char f);
int					ft_putstr(char *str);
int					ft_putnbr_print_int(int n, int len);
int					ft_putnbr_print_unsigned(unsigned int n, unsigned int len1);
int					ft_putchar(char c);
long int			ft_atoi(const char *src);
unsigned long int	ft_count_base(unsigned long int nbr, const char type);
unsigned long int	ft_putnbr_base(unsigned long int nbr, const char type);
unsigned long int	ft_print_hex_ptr(unsigned long int nbr, const char type);

#endif
