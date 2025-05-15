/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:25:45 by maxmart2          #+#    #+#             */
/*   Updated: 2025/02/26 03:25:47 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_better_lstclear(t_list *map, void *content, void (*del)(void *))
{
	del(content);
	if (map)
		ft_lstclear(&map, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*node;
	void	*content;

	if (!lst)
		return (NULL);
	map = ft_lstnew((content = f(lst->content)));
	node = NULL;
	if (!map)
		return (ft_better_lstclear(map, content, del));
	lst = lst->next;
	while (lst)
	{
		node = ft_lstnew((content = f(lst->content)));
		if (!node)
		{
			return (ft_better_lstclear(map, content, del));
		}
		ft_lstadd_back(&map, node);
		lst = lst->next;
	}
	return (map);
}
