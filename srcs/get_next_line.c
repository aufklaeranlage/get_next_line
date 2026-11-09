/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@students.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:59:02 by abronner          #+#    #+#             */
/*   Updated: 2025/03/12 18:43:36 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_out(t_listwrap *wrap, int fd, size_t tsize);

static char	*init_out(size_t *size, size_t tsize, char *buf, char *tmp);

static void	store_remainder(t_listwrap *wrap, char *str, size_t size);

static void	ft_strncpy(char *dest, char *src, size_t len);

char	*get_next_line(int fd)
{
	static t_listwrap	wrap[MAXFDS];
	char				*out;
	size_t				size;

	if (fd < 0 || fd >= MAXFDS)
		return (NULL);
	size = 0;
	if ((wrap + fd)->head)
		size = (wrap + fd)->head->size;
	if (size && ((char *)((wrap + fd)->head->data))[size - 1] == '\n')
	{
		out = malloc(((wrap + fd)->head->size + 1) * sizeof(*out));
		out[size] = '\0';
	}
	else
		out = read_to_out(wrap + fd, fd, size);
	if ((wrap + fd)->head)
		ft_strncpy(out, (char *)(wrap + fd)->head->data, size);
	if (size)
		wrap_del_first(wrap + fd);
	return (out);
}

static char	*read_to_out(t_listwrap *wrap, int fd, size_t tsize)
{
	char	*out;
	char	buf[BUFFER_SIZE + 1];
	size_t	size;
	char	*tmp;

	size = read(fd, buf, BUFFER_SIZE);
	if (!size)
		return (NULL);
	buf[size] = '\0';
	tmp = ft_strchr(buf, '\n');
	if (!tmp)
		tmp = buf + size;
	if (*tmp == '\0')
		out = read_to_out(wrap, fd, tsize + size);
	else
	{
		if (size - (tmp - buf) - 1)
			store_remainder(wrap, tmp + 1, size - (tmp - buf) - 1);
		out = init_out(&size, tsize, buf, tmp);
	}
	if (!out)
		return (free_wrap(wrap), NULL);
	while (size--)
		out[tsize + size] = buf[size];
	return (out);
}

static char	*init_out(size_t *size, size_t tsize, char *buf, char *tmp)
{
	char	*out;

	*size = tmp - buf + 1;
	out = malloc((tsize + *size + 1) * sizeof(*out));
	out[tsize + *size] = '\0';
	return (out);
}

static void	store_remainder(t_listwrap *wrap, char *str, size_t size)
{
	char	*tmp;
	t_list	*node;
	char	*check;

	node = malloc(sizeof(*node));
	if (!node)
		return (free_wrap(wrap));
	check = ft_strchr(str, '\n');
	if (!check)
		check = str + size;
	else
		++check;
	tmp = ft_substr(str, 0, check - str);
	if (!tmp)
		return (free_wrap(wrap));
	node->data = (void *)tmp;
	node->size = check - str;
	node->next = NULL;
	wrap_add_back(wrap, node);
	if (*(check - 1) == '\n' && size - (check - str))
		store_remainder(wrap, check, size - (check - str));
}

static void	ft_strncpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		++i;
	}
}
