/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:29:24 by ateow             #+#    #+#             */
/*   Updated: 2023/12/28 17:29:25 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler_ctrl_c(int signo)
{
	signo = signo;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	setup_custom_signal_handlers(void)
{
	struct sigaction	signal_ctrl_c;
	struct sigaction	signal_ctrl_slash;

	signal_ctrl_c.sa_handler = &signal_handler_ctrl_c;
	sigemptyset(&signal_ctrl_c.sa_mask);
	signal_ctrl_c.sa_flags = SA_RESTART;
	sigaction(SIGINT, &signal_ctrl_c, NULL);
	signal_ctrl_slash.sa_handler = SIG_IGN;
	sigemptyset(&signal_ctrl_slash.sa_mask);
	signal_ctrl_slash.sa_flags = 0;
	sigaction(SIGQUIT, &signal_ctrl_slash, NULL);
}

void	block_custom_signal_handlers(void)
{
	struct sigaction	signal_ctrl_c;
	struct sigaction	signal_ctrl_slash;

	signal_ctrl_c.sa_handler = SIG_IGN;
	sigemptyset(&signal_ctrl_c.sa_mask);
	signal_ctrl_c.sa_flags = 0;
	sigaction(SIGINT, &signal_ctrl_c, NULL);
	signal_ctrl_slash.sa_handler = SIG_IGN;
	sigemptyset(&signal_ctrl_slash.sa_mask);
	signal_ctrl_slash.sa_flags = 0;
	sigaction(SIGQUIT, &signal_ctrl_slash, NULL);
}

void	use_default_signal_handlers(void)
{
	struct sigaction	signal_default;

	sigemptyset(&signal_default.sa_mask);
	sigaction(SIGINT, &signal_default, NULL);
	sigaction(SIGQUIT, &signal_default, NULL);
}
