/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:45:04 by sookim            #+#    #+#             */
/*   Updated: 2021/01/18 23:45:05 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*str;

	if (s1 && s2)
	{
		len = ft_strlen(s1);
		if (!(str = (char*)malloc(1 * (len + ft_strlen(s2) + 1))))
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len] = s2[i];
			len++;
		}
		str[len] = '\0';
		return (str);
	}
	else if (s1)
		return (ft_strdup(s1));
	return (NULL);
}
