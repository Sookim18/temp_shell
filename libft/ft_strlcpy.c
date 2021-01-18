/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 03:57:54 by sookim            #+#    #+#             */
/*   Updated: 2021/01/19 03:57:55 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	length_src;
	size_t	i;

	if (!dest || !src)
		return (0);
	length_src = 0;
	while (src[length_src])
		length_src++;
	if (n)
	{
		i = -1;
		if (length_src + 1 < n)
			while (++i < length_src)
				dest[i] = src[i];
		else
			while (++i < n - 1)
				dest[i] = src[i];
		dest[i] = '\0';
	}
	return (length_src);
}
