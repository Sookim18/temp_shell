/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 03:58:45 by sookim            #+#    #+#             */
/*   Updated: 2021/01/23 17:38:44 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		len;

	s1 = (char *)s;
	len = 0;
	while (s1[len])
		len++;
	while (s1[len] != c && len != 0)
		len--;
	if (s1[len] == c)
		return (&s1[len]);
	else
		return (NULL);
}
