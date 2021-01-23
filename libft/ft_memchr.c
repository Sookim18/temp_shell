/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:43:11 by sookim            #+#    #+#             */
/*   Updated: 2021/01/23 17:37:42 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*v;
	size_t			i;

	v = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (v[i] == (unsigned char)c)
			return ((void *)&v[i]);
		i++;
	}
	return (NULL);
}
