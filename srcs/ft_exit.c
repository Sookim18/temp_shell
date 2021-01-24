/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:00:26 by sookim            #+#    #+#             */
/*   Updated: 2021/01/24 17:38:40 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_param(t_data *param)
{
	free(param->str);
	free_matrix(param->envp);
	free_matrix(param->export);
	free_matrix(param->argv);
	free_matrix(param->cmds);
	free(param);
}

void		ft_exit(t_data *param)
{
	int i;

	if (param->argc > 2)
	{
		ft_putstrs_fd("exit\n", "bash: exit: too many arguments\n", 0, 2);
		g_ret = 1;
	}
	else
	{
		i = 0;
		while (param->argc > 1 && ft_isdigit(param->argv[1][i]))
		{
			i++;
		}
		if (param->argc > 1 && param->argv[1][i])
		{
			ft_putstrs_fd("exit\nbash: exit: ",
				param->argv[1], ": numeric argument required\n", 2);
			g_ret = 2;
		}
		i = (param->argc > 1 && g_ret != 2)
			? ft_atoi(param->argv[1]) : g_ret;
		free_param(param);
		exit(i);
	}
}
