/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/06 20:56:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;
	char	*cmdline;
	int		pid;

	check_args(argc);
	save_env(envp);
	while (1)
	{
		prompt = build_prompt(prompt);
		cmdline = readline(prompt);
		action(cmdline, envp);
		free(cmdline);
	}
	return (0);
}
