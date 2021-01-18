/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:42:09 by sookim            #+#    #+#             */
/*   Updated: 2021/01/18 23:42:10 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *head;

	if (!alst || !new)
		return ;
	if (*alst)
	{
		head = *alst;
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		*alst = new;
}
