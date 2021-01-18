/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:42:46 by sookim            #+#    #+#             */
/*   Updated: 2021/01/18 23:42:47 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*last;

	if (!lst || !(lst->content))
		return (NULL);
	head = ft_lstnew(f(lst->content));
	last = head;
	while (lst->next)
	{
		lst = lst->next;
		if (!(last->next = ft_lstnew(f(lst->content))))
		{
			while (head)
			{
				del(head->content);
				head = head->next;
			}
			return (NULL);
		}
		last = last->next;
		last->content = f(lst->content);
	}
	return (head);
}
