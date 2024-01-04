/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:57:26 by ateow             #+#    #+#             */
/*   Updated: 2023/12/28 16:57:27 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	contains_spaces_tabs(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && *str != '\t')
			return (0);
		i++;
	}
	return (1);
}

t_var	init_minishell_vars(char *envp[])
{
	t_var	vars;

	vars.exit_status = 0;
	vars.history_list = NULL;
	vars.env = init_env(envp);
	return (vars);
}

int	main(int argc, char **argv, char *envp[])
{
	t_var	vars;

	vars = init_minishell_vars(envp);
	while (1 && argc && argv)
	{
		setup_custom_signal_handlers();
		vars.user_input = readline("Minishell: ");
		if (vars.user_input == NULL)
		{
			free_str_lst_arr(vars.user_input, vars.history_list, vars.env);
			return (0);
		}
		else if (vars.user_input[0] != '\0'
			&& contains_spaces_tabs(vars.user_input) == 0)
		{
			vars.fds.infd = 0;
			vars.fds.outfd = 1;
			vars.clean_input = inject_space(vars.user_input);
			store_history(vars.user_input, &(vars.history_list));
			free(vars.user_input);
			parsed_and_execute(vars.clean_input, &vars);
			free(vars.clean_input);
		}
	}
	return (vars.exit_status);
}

// // DEBUG FUNCTION > TO DELETE!
// void	print_array(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		printf("arr[%d]: %s\n", i, arr[i]);
// 		i++;
// 	}
// }