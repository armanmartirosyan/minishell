/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:42:43 by armartir          #+#    #+#             */
/*   Updated: 2023/04/02 21:49:36 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	here_doc_controller(t_minishell *shell, char *cmd_line)
{
	size_t	i;
	int		par_err_index;
	int		quotes[2];

	i = 0;
	quotes[0] = 0;
	quotes[1] = 0;
	while (cmd_line[i])
	{
		quote_check(&quotes[0], &quotes[1], cmd_line[i]);
		if((quotes[0] || quotes[1]) && ++i)
			continue;
		if (cmd_line[i] == '<' && cmd_line[i + 1] == '<')
		{
			i += 2;
			while (cmd_line[i] == ' ')
				i++;
			execute_heredoc(shell, cmd_line, i);
		}
		else
			i++;
	}
}

int quote_controller(char *line)
{
	size_t i;
	int db_quote;
	int sg_quote;

	i = 0;
	db_quote = 0;
	sg_quote = 0;
	while(line[i])
	{
		if(!quote_check(&sg_quote, &db_quote, line[i]))
			return (write_exception(130, "(\') or (\")", NULL, 0));
		i++;
	}
	if(db_quote || sg_quote)
		return (write_exception(130, "(\') or (\")", NULL, 0));
	return (0);
}