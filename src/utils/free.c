/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:25:52 by arsbadal          #+#    #+#             */
/*   Updated: 2023/04/02 16:04:28 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*free_single(void **addr)
{
	if (*addr)
	{
		free (*addr);
		*addr = 0;
	}
	return (0);
}

void	*free_double(void ***addr)
{
	int	i;

	i = 0;
	if (*addr)
	{
		while ((*addr)[i])
		{
			free_single((void *)&(*addr)[i]);
			i++;
		}
		free_single((void *)&(*addr));
	}
	return (0);
}

void *free_token(t_minishell *shell, t_token *token)
{
	free_single((void *)&token->cmd);
	free_single((void *)&token->path);
	free_double((void *)&token->tokens);
	free_double((void *)&token->redirects);
	// free(token);
	return (NULL);
}