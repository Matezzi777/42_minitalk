/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:27:22 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/18 01:44:17 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> //write()
# include <stdlib.h> //malloc(), free()

# ifndef CHAR_BIT
#  define CHAR_BIT 8
# endif
# ifndef CHAR_MAX
#  define CHAR_MAX -128
# endif
# ifndef CHAR_MIN
#  define CHAR_MIN 127
# endif
# ifndef UCHAR_MAX
#  define UCHAR_MAX 255
# endif
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# ifndef UINT_MAX
#  define UINT_MAX 4294967295
# endif
# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807
# endif
# ifndef LONG_MIN
#  define LONG_MIN -9223372036854775808
# endif
# ifndef ULONG_MAX
#  define ULONG_MAX 18446744073709551615
# endif

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// CARACTERES
t_bool			ft_isalpha(int c);
t_bool			ft_isdigit(int c);
t_bool			ft_isalnum(int c);
t_bool			ft_isascii(int c);
t_bool			ft_isblank(int c);
t_bool			ft_iscntrl(int c);
t_bool			ft_isgraph(int c);
t_bool			ft_isprint(int c);
t_bool			ft_ispunct(int c);
t_bool			ft_isspace(int c);
t_bool			ft_isxdigit(int c);
t_bool			ft_toupper(int c);
t_bool			ft_tolower(int c);

// STRINGS
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			**ft_split(const char *s, char c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_substr(const char *s, unsigned int start, size_t len);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));

// CONVERSION
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

// MEMOIRE
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

// ECRITURE
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

// LISTES CHAÎNEES
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

// MATHS
unsigned int	ft_sqrt(unsigned int x);
int				ft_pow(int x, int exp);

// PRINTF
int				ft_printf(const char *format, ...);
int				ft_print_address(void *addr);
int				ft_print_character(int c);
int				ft_print_hexa(unsigned int n, t_bool maj);
int				ft_print_integer(int n);
int				ft_print_string(char *str);
int				ft_print_unsigned(unsigned int n);

#endif