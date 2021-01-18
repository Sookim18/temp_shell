/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:45:10 by sookim            #+#    #+#             */
/*   Updated: 2021/01/18 23:45:11 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t len1;
	size_t i;

	len = ft_strlen(src);
	len1 = ft_strlen(dst);
	i = 0;
	if (size <= len1)
		return (len + size);
	else
		len += len1;
	while (src[i] != 0 && len1 + 1 < size)
	{
		dst[len1] = src[i];
		len1++;
		i++;
	}
	dst[len1] = 0;
	return (len);
}
