/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mishell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:42:02 by arsbadal          #+#    #+#             */
/*   Updated: 2023/04/30 21:25:42 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_code = 0;

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*shell;

	shell = NULL;
	(void)argv;
	if (argc > 1)
		exit(1);
	shell = init_minishell();
	if (!shell)
		return (1);
	print_header();
	env_controller(shell, envp);
	read_shell(shell, NULL, NULL);
	return (g_exit_code);
}
