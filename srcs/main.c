/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sookim <sookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:00:47 by sookim            #+#    #+#             */
/*   Updated: 2021/01/23 17:41:14 by sookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_prompt(char **envp)
{
	char *home;
	char *path;
	char cwd[4097];

	home = get_env(envp, "HOME");
	getcwd(cwd, 4096);
	if (ft_memcmp(cwd, home, ft_strlen(home)))
		path = ft_strdup(cwd);
	else
		path = ft_strjoin("~", cwd + ft_strlen(home));
	write(2, "sookimshell", 12);
	ft_putstrs_fd(":", path, "$ ", 2);
	free(path);
}

static void	sig_handler(int sig)
{
	char cwd[4097];

	if (sig == SIGINT)
	{
		getcwd(cwd, 4096);
		ft_putstr_fd("\033[2D\033[0K", 2);
		write(2, "\n", 1);
		write(2, "\rsookimshell", 14);
		ft_putstrs_fd(":", cwd, "$ ", 2);
	}
	else if (sig == SIGQUIT)
	{
		ft_putstr_fd("\033[2D\033[0K", 2);
	}
}

static void	init(t_data **param, char **argv, char **envp, int *ret_len)
{
	(*param) = (t_data *)malloc(sizeof(t_data));
	(*param)->envp = copy_env(envp, 0);
	(*param)->export = (char **)ft_calloc(sizeof(char *), 1);
	(*param)->argv = argv;
	(*param)->ret = 0;
	(*param)->str = 0;
	(*param)->child = 0;
	ret_len[0] = 1;
}

int			main(int argc, char **argv, char **envp)
{
	t_data	*param;
	int		ret_len[2];
	char	c;

	if (argc != 1)
		return (1);
	init(&param, argv, envp, ret_len);
	signal(SIGQUIT, sig_handler);
	while (1)
	{
		if (ret_len[0])
			init_prompt(param->envp);
		signal(SIGINT, sig_handler);
		while ((ret_len[0] = read(1, &c, 1)) && c != '\n')
			ft_addchr(&(param->str), c);
		ret_len[1] = (int)ft_strlen(param->str);
		if (c == '\n')
			parser(param);
		if (!ret_len[0] && !ret_len[1])
		{
			ft_putstr_fd("\nexit\n", 2);
			exit(0);
		}
	}
	return (0);
}
