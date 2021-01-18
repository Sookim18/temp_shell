/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:43:25 by sookim            #+#    #+#             */
/*   Updated: 2021/01/18 23:43:26 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *v1;
	unsigned char *v2;

	v1 = (unsigned char *)s1;
	v2 = (unsigned char *)s2;
	while (0 < n--)
		if (*(v1++) != *(v2++))
			return (*(--v1) - *(--v2));
	return (0);
}
