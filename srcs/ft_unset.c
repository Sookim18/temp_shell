/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:01:20 by sookim            #+#    #+#             */
/*   Updated: 2021/01/23 17:39:50 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**erase_env(char **envp, int i)
{
	int		j;
	int		len;
	char	**cpy;

	len = 0;
	while (envp[len])
		len++;
	if (!(cpy = (char **)ft_calloc(sizeof(char *), len)))
		return (NULL);
	j = -1;
	while (++j < i)
		cpy[j] = ft_strdup(envp[j]);
	i++;
	while (envp[i])
		cpy[j++] = ft_strdup(envp[i++]);
	free_matrix(envp);
	return (cpy);
}

char		**ft_unset(t_data *param, int j)
{
	int		i;
	int		len;
	char	*env;
	char	**cpy;

	if (param->argc < 2)
		return (param->envp);
	len = strlen(param->argv[j]);
	env = ft_strjoin(param->argv[j], "=");
	i = 0;
	while (param->envp[i] && ft_memcmp(env, param->envp[i], len + 1))
		i++;
	if (param->envp[i])
		cpy = erase_env(param->envp, i);
	else
		cpy = param->envp;
	free(env);
	return (cpy);
}

int	dq(char **str, int *i)
{
	(*i)++;
	while ((*str)[*i] && ((*str)[*i] != '"'))
		(*i)++;
	if (!(*str)[*i])
	{
		ft_putstr_fd("Non finished double quotes\n", 2);
		return (1);
	}
	return (0);
}