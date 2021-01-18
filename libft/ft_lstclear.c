/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:42:23 by sookim            #+#    #+#             */
/*   Updated: 2021/01/18 23:42:24 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *aux;

	if (!lst || !(*lst) || !del)
		return ;
	while ((*lst))
	{
		aux = *lst;
		del((*lst)->content);
		(*lst) = (*lst)->next;
		free(aux);
	}
}
