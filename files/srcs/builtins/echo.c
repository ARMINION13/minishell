/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:16:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/17 20:25:22 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void echo(char **cmd)
{
	int i;
	int option;

	if (!ft_strncmp(cmd[1], "-n", ft_strlen(cmd[1])))
	{
		i = 2;
		option = 1;
	}
	else
	{
		i = 1;
		option = 0;
	}
	while (cmd[i])
	{
		if (option)
			printf("%s", cmd[i]);
		else
			printf("%s\n", cmd[i]);
		i++;
	}
}