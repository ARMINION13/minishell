/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:14:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/18 18:56:14 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_builtins(char **cmd)
{
	if (!ft_strncmp(cmd[0], "pwd", ft_strlen(cmd[0])))
	{
		printf("%s\n", getenv("PWD"));
		return (1);
	}
	if (!ft_strncmp(cmd[0], "env", ft_strlen(cmd[0])))
	{
		env(global.env);
		return (1);
	}
	if (!ft_strncmp(cmd[0], "cd", ft_strlen(cmd[0])))
	{
		change_directory(cmd[1]);
		return (1);
	}
	if (!ft_strncmp(cmd[0], "exit", ft_strlen(cmd[0])))
	{
		exit(EXIT_SUCCESS);
		return (1);
	}
	if (!ft_strncmp(cmd[0], "echo", ft_strlen(cmd[0])))
	{
		echo(cmd);
		return (1);
	}
	return (0);
}