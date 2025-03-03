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

#include "../include/minitalk_bonus.h"

static t_bits_info	g_info;

static int	ft_get_range(int c)
{
	if (c && (c >= 0x00 && c <= 0x7F))
		return (1);
	else if (c && (c >= 0xC2 && c <= 0xDF))
		return (2);
	else if (c && (c >= 0xE0 && c <= 0xEF))
		return (3);
	else if (c && (c >= 0xF0 && c <= 0xF4))
		return (4);
	return (1);
}

static void	ft_handle_utf8_char(void)
{
	write(1, g_info.utf8_buf, g_info.utf8_cnt);
	g_info.utf8_cnt = 0;
	g_info.utf8_exp = 0;
}

static void	ft_helper(void)
{
	if (g_info.utf8_cnt == 0)
		g_info.utf8_exp = ft_get_range(g_info.byte);
	g_info.utf8_buf[g_info.utf8_cnt++] = g_info.byte;
	if (g_info.utf8_cnt >= g_info.utf8_exp)
		ft_handle_utf8_char();
}

void	sigusr_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (info->si_pid != g_info.pid)
	{
		ft_memset(&g_info, 0, sizeof(t_bits_info) - (sizeof(int) * 2));
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
			ft_helper();
			g_info.byte = 0;
			g_info.cnt = 0;
		}
	}
	kill(g_info.pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sigusr_handler;
	g_info.pid = 0;
	ft_printf("PID = %d\n", getpid());
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
