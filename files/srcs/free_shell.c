/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:11:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/25 20:46:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//FIXME: FREE tokens

 void del_token(void *content)
{
	t_token *token;

	token = ((t_token *)content);
	free(token->word);
	free(content);
}

void del_data(void *content)
{
	t_cmd_data *data;
	t_list *token;

	data = ((t_cmd_data *)content);
	free(data->cmd);
	free(content);
	token = ((t_cmd_data *)content)->token;
	//ft_lstclear(&token, del_token);
}

void free_shell(t_shell *shell)
{
	free(shell->cmdline);
	free(shell->prompt);
	ft_lstclear(&shell->cmdlist, del_data);
/* 	dup2(STDOUT_FILENO ,STDOUT_FILENO);
	dup2(STDIN_FILENO, STDIN_FILENO); */
}