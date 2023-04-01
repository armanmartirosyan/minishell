/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:25:46 by arsbadal          #+#    #+#             */
/*   Updated: 2023/04/01 12:35:04 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
#define SHELL_H

typedef struct s_minishell {
	struct s_exc_line *execute;
	struct s_status *status;
	char **envp;
} t_minishell;

typedef struct s_exc_line {
	struct s_cmd *cmd_list;
	char *cmd_line;
	char **cmd_parts;
} t_exc_line;

typedef struct s_cmds {
	char *cmd_line;
	char **cmd;
} t_cmds;

typedef struct s_status {
	int line;
	int part;
	int error;
} t_status;

// Initialize
t_minishell *init_minishell();
t_exc_line *init_exc_line();
t_cmds **init_cmds(size_t size);
t_status *init_status();

#endif