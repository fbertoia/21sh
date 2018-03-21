/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfontain <hfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:37:13 by fbertoia          #+#    #+#             */
/*   Updated: 2018/03/15 15:55:47 by hfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <limits.h>
# define BUFF_SIZE_GNL 4028

typedef struct		s_get
{
	struct s_get	*next;
	char			content[BUFF_SIZE_GNL];
	struct s_get	*fd_ptr[OPEN_MAX];
	int				first;
}					t_get;

typedef struct		s_list
{

	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_void
{
	struct s_void *next;
	struct s_void *previous;
}					t_void;

typedef struct		s_btree
{
	struct s_btree	*parent;
	struct s_btree	*left;
	struct s_btree	*right;
	void			*content;
}					t_btree;

char				*ft_strpushback(char *str, char c, size_t *buff_sz);
char				**ft_strsplit(char *s, char c);
char				**ft_strsplitwhitespace(char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
char				*ft_strcapitalize(char *str);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcdup(const char *s1, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_multiple(int nb_args, ...);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strndup(char *src, size_t size);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					arrlen(char **arr);
int					ft_abs(int a);
int					ft_atoi(const char *str);
int					ft_binsearch(const void *arr, const void *value,
					size_t size, size_t length);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_lstsize(t_list *begin_list);
int					ft_max(int a, int b);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_min(int a, int b);
int					ft_sqrt(int nb);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strindex(const char *str, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strnindex(const char *str, int c, int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					get_next_line(const int fd, char **line);
int					size_list(void *a);
int					str_alnum(char *str);
int					str_digit(char *str);
int					str_isprint(char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
void				*add_elem_back(void **alst, void *elem_to_add);
void				*add_elem_front(void **alst, void *elem_to_add);
void				*add_elem_back_dl(void **alst, void *elem_to_add);
void				*add_elem_front_dl(void **alst, void *elem_to_add);
t_list				*ft_lstadd_back(t_list **alst, void const *content,
					size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, size_t new_size);
void				*last_elem(void *a);
void				del_arr(char ***arr);
void				del_list(void **elem, void (*f)(void**));
void				del_str(int nb_args, ...);
void				ft_bzero(void *s, size_t n);
void				ft_lstadd(t_list **alst, t_list *nl);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_sortstrings(char **ptr, size_t size,
					int (*f)(char *, char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_swap(void *a, void *b, size_t size);
char				*ft_strpopm(char *str, size_t idx);
char				*ft_strpop(char *str, size_t idx);
char				*ft_strpushm(char *str, size_t index, char c);
char				*ft_strpush(char *str, size_t index, char c,
					size_t *buff_sz);
char				*ft_strfjoin(char *s1, char const *s2);
char				*ft_strffjoin(char *s1, char *s2);
unsigned long long	ft_hash(const char *str);
char				*ft_strredup(char *s1);
char				*ft_strlcat_multiple(char *buff, size_t len,
					int nb_args, ...);
char				*random_str(size_t len);
int					is_whitespace(char c);
char				**cpy_arr(char **arr);
void				print_arr(char **arr);

# define MY_INT_MAX 2147483647
# define MY_INT_MIN -2147483648

#endif
