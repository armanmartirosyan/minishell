/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:23:58 by armartir          #+#    #+#             */
/*   Updated: 2023/04/30 21:27:48 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	controller(t_minishell *shell, char *user_input)
{
	shell->user_input = ft_strtrim(user_input, WHITE_SPACE);
	free_single((void *)&user_input);
	if (!shell->user_input)
		force_quit(12);
	shell->status = quote_controller(shell, shell->user_input);
	if (shell->status && !free_single((void *)&shell->user_input))
		return (shell->status);
	shell->status = check_cmd_line(shell, shell->user_input, 0, 0);
	if (shell->status && !free_single((void *)&shell->user_input))
		return (shell->status);
	if (heredoc_process_control(shell)
		&& !free_single((void *)&shell->user_input))
		return (shell->status);
	shell->execute->heredoc_out = get_heredoc_count(shell);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	shell->execute->tokens = start_parse_cmds(shell->user_input, 0, 0);
	fill_cmd_list(shell);
	free_single((void *)&shell->user_input);
	shell->execute->skip_mode = 0;
	shell->execute->skip_phs = 0;
	shell->execute->sub_shell_mode = 0;
	execution_management(shell, 0);
	free_double((void *)&shell->execute->tokens);
	return (shell->status);
}

void	fill_cmd_list(t_minishell *shell)
{
	char	*temp;
	size_t	i;

	i = 0;
	shell->execute->clist_len
		= get_2d_array_length((void **)shell->execute->tokens);
	shell->execute->cmd_list = init_tokens(shell->execute->clist_len);
	while (i < shell->execute->clist_len)
	{
		temp = shell->execute->tokens[i];
		if (shell->execute->cmd_list[i].token_mode == CMD)
			temp = ft_strtrim(temp, WHITE_SPACE);
		else
			temp = ft_strdup(shell->execute->tokens[i]);
		if (!temp)
			force_quit(ERNOMEM);
		shell->execute->cmd_list[i].token_mode = get_line_type(temp);
		shell->execute->cmd_list[i].heredoc_sum = get_heredoc_sum(shell, temp);
		shell->execute->cmd_list[i].cmd = temp;
		i++;
	}
	free_double((void *)&shell->execute->tokens);
}
