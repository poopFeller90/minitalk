/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:22:30 by yhajbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:18:20 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

static t_bits_info	g_info;

void	sigusr_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (signum == SIGUSR1 && g_info.pid == info->si_pid)
	{
		ft_printf("Server: Message received\n");
		g_info.msg_rcv = 1;
	}
	else if (signum == SIGUSR2)
		g_info.msg_rcv = 1;
}

static void	set_sa(struct sigaction *sa)
{	
	sa->sa_sigaction = sigusr_handler;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	if (sigaction(SIGUSR1, sa, NULL) == -1)
	{
		ft_printf("%s\n", ERR_ON_SIGHDL);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) == -1)
	{
		ft_printf("%s\n", ERR_ON_SIGHDL);
		exit(EXIT_FAILURE);
	}
}

void	ft_send_signal(int pid, char c)
{
	int	i;
	int	ret;
	int	cup;

	i = 7;
	ret = 0;
	cup = 0;
	while (i >= 0)
	{
		while (!g_info.msg_rcv)
			usleep(1);
		g_info.msg_rcv = 0;
		cup = (c & (1 << i));
		if (cup == 0)
			ret = kill(pid, SIGUSR1);
		else if (cup > 0)
			ret = kill(pid, SIGUSR2);
		if (ret == -1)
		{
			ft_printf("%s %d\n", ERR_ON_SEND, pid);
			exit(EXIT_FAILURE);
		}
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int					i;
	int					pid;
	struct sigaction	sa;

	set_sa(&sa);
	if (argc != 3)
		return (ft_printf("%s\n", ERR_USAGE), 0);
	i = 0;
	pid = ft_atoi(argv[1]);
	g_info.pid = pid;
	if (pid <= 0)
		return (ft_printf("%s\n", ERR_PID), 0);
	ft_printf("%s %d\n%s\n", CLT_STARTUP, pid, CLT_SENDING);
	g_info.msg_rcv = 1;
	while (argv[2][i])
		ft_send_signal(pid, argv[2][i++]);
	ft_send_signal(pid, (char)0);
	return (0);
}
