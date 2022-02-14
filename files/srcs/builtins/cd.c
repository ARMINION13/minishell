/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:13:01 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/14 16:38:06 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void change_directory(char *path, char **envp)
{
	char *new_path;
	char *old_path;
	char *tmp;
	
	if (path)
	{	
		old_path = ft_strjoin("OLDPWD=", getvar("PWD", envp));
		change_val("OLDPWD", old_path, envp);
		free(old_path);
		if (chdir(path) < 0)
			perror("Chdir Error");
		tmp = getcwd(NULL, 1000);
		new_path = ft_strjoin("PWD=", tmp);
		change_val("PWD", new_path, envp);
		free(tmp);
		free(new_path);
	}
}