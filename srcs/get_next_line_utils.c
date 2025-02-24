/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@42studnets.berlin>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:45:02 by abronner          #+#    #+#             */
/*   Updated: 2025/02/24 09:45:18 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_wrap(t_listwrap *wrap)
{
	t_list	*node;
	t_list	*tmp;

	if (!wrap->head)
		return ;
	node = wrap->head;
	while (node)
	{
		tmp = node->next;
		free(node->data);
		free(node);
		node = tmp;
	}
	wrap->head = NULL;
	wrap->tail = NULL;
}

void	wrap_add_back(t_listwrap *wrap, t_list *node)
{
	t_list	*tmp;

	if (wrap->tail)
	{
		tmp = wrap->tail;
		tmp->next = node;
		wrap->tail = node;
	}
	else
	{
		wrap->tail = node;
		wrap->head = node;
	}
}

void	wrap_del_first(t_listwrap *wrap)
{
	t_list	*node;

	if (!wrap->head)
		return ;
	node = wrap->head;
	if (wrap->head == wrap->tail)
		wrap->tail = NULL;
	wrap->head = node->next;
	free(node->data);
	free(node);
}

char	*ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(const char *s, size_t start, size_t end)
{
	char	*out;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		++len;
	if (len < start || len < end - start - 1)
		return (NULL);
	len = end - start + 1;
	out = malloc(len-- * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[start + i];
		++i;
	}
	out[i] = '\0';
	return (out);
}
