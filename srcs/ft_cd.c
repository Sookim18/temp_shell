/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:00:14 by sookim            #+#    #+#             */
/*   Updated: 2021/01/24 17:39:37 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_dir(char *path, t_data *param)
{
	char		cwd[4097];
	char		oldpwd[4097];

	getcwd(oldpwd, 4096);
	if (chdir(path) == 0)
	{
		param->argc = 4;
		free_matrix(param->argv);
		param->argv = (char **)ft_calloc(sizeof(char *), 4);
		param->argv[0] = ft_strdup("export");
		param->argv[1] = ft_strdup("OLDPWD=");
		param->argv[2] = ft_strdup(oldpwd);
		param->envp = ft_export(param, 1);
		free_matrix(param->argv);
		param->argv = (char **)ft_calloc(sizeof(char *), 4);
		param->argv[0] = ft_strdup("export");
		param->argv[1] = ft_strdup("PWD=");
		param->argv[2] = ft_strdup(getcwd(cwd, 4096));
		param->envp = ft_export(param, 1);
	}
	else
		ft_putstrs_fd("bash: cd: ", param->argv[1], ": ", 2);
}

void		ft_cd(t_data *param)
{
	char *path;

	errno = 0;
	if (param->argc <= 2)
	{
		if (!param->argv[1] || !ft_strncmp(param->argv[1], "--", 3) ||
			!ft_strncmp(param->argv[1], "~", 2))
			path = get_env(param->envp, "HOME");
		else if (!ft_strncmp(param->argv[1], "-", 2))
			path = get_env(param->envp, "OLDPWD");
		else
			path = param->argv[1];
		change_dir(path, param);
		if (errno > 0)
		{
			ft_putstrs_fd(strerror(errno), "\n", 0, 2);
			g_ret = 1;
		}
	}
	else
	{
		ft_putstr_fd("bash: cd: too many arguments\n", 2);
		g_ret = 1;
	}
	errno = 0;
}
