/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@students.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:59:26 by abronner          #+#    #+#             */
/*   Updated: 2025/03/12 18:42:51 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//	TYPEDEFS

typedef struct s_list {
	struct s_list	*next;
	void			*data;
	size_t			size;
}	t_list;

typedef struct s_listwrap {
	t_list	*head;
	t_list	*tail;
}	t_listwrap;

//	DEFINES

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define MAXFDS 64
# define LST 0
# define NLLST 1

char	*get_next_line(int fd);

//	UTILS

void	free_wrap(t_listwrap *wrap);

void	wrap_add_back(t_listwrap *wrap, t_list *node);

void	wrap_del_first(t_listwrap *wrap);

char	*ft_strchr(const char *s, char c);

char	*ft_substr(const char *s, size_t start, size_t end);

#endif
