/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:08:02 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 20:34:52 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec(char **cmds, char **envp)
{
	int pid;

	pid = fork();
	if (!pid)
	{
		execve(cmds[0], cmds, envp);
		perror("Execution error");
	}
	else if(pid)
		wait(NULL);
	else
		perror("Fork error\n");
	return(0);
}