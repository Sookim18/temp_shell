/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 03:58:23 by sookim            #+#    #+#             */
/*   Updated: 2021/01/23 17:38:37 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *c1;
	unsigned char *c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (0 < n--)
	{
		if (*(c1++) != *(c2++))
			return (*(--c1) - *(--c2));
		else if (!(*c1) || !(*c2))
			return (*(c1) - *(c2));
	}
	return (0);
}
