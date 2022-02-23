/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:38:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/23 19:04:50 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_msg(void)
{
	printf("%s        .__       .__       .__           .__  .__   \n",
		COLOR(1, 31));
	printf("  _____ |__| ____ |__| _____|  |__   ____ |  | |  |  \n");
	printf(" /     \\|  |/    \\|  |/  ___/  |  \\_/ __ \\|  | |  |  \n");
	printf("|  Y Y  \\  |   |  \\  |\\___ \\|   Y  \\  ___/|  |_|  |__\n");
	printf("|__|_|  /__|___|  /__/____  >___|  /\\___  >____/____/\n");
	printf("      \\/        \\/        \\/     \\/     \\/           \n\n%s",
		NC);
}

char	**init_env(char **envp)
{
	char	**new_envp;
	int		i;

	new_envp = (char **)malloc(sizeof(char *) * g_global.env_len);
	i = 0;
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = NULL;
	return (new_envp);
}

void	init_g_global(char **envp, char **argv)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	g_global.env_len = (i + 2);
	g_global.env = init_env(envp);
	g_global.exit_status = 0;
	g_global.fd_stdin = dup(STDIN_FILENO);
	g_global.fd_stdout = dup(STDOUT_FILENO);
	g_global.exec = false;
	g_global.signal_status = 0;
	(void)argv;
}

int	init_shell(char **argv, char **envp)
{
	print_msg();
	init_g_global(envp, argv);
	return (0);
}
