/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:25:57 by yhajbi            #+#    #+#             */
/*   Updated: 2024/12/21 13:22:14 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_bits_info	g_info = {0, 0, 0, 0, 0};

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	sigusr_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (info->si_pid != g_info.pid)
	{
		g_info.byte = 0;
		g_info.cnt = 0;
		g_info.pid = info->si_pid;
	}
	if (signum == SIGUSR2)
		g_info.byte = (g_info.byte << 1) | 1;
	else if (signum == SIGUSR1)
		g_info.byte = g_info.byte << 1;
	g_info.cnt++;
	if (g_info.cnt == 8)
	{
		if (g_info.byte == 0)
			kill (g_info.pid, SIGUSR1);
		else
		{
			ft_putchar(g_info.byte);
			g_info.byte = 0;
			g_info.cnt = 0;
		}
	}
	usleep(10);
	kill(g_info.pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sigusr_handler;
	g_info.pid = getpid();
	ft_printf("PID = %d\n", g_info.pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("%s\n", ERR_ON_SIGHDL);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("%s\n", ERR_ON_SIGHDL);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
