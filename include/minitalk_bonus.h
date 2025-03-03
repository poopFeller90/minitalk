/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:23:39 by yhajbi            #+#    #+#             */
/*   Updated: 2025/03/01 14:59:04 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct bits_info_s
{
	int				cnt;
	int				bit;
	int				byte;
	int				utf8_cnt;
	int				utf8_exp;
	unsigned char	utf8_buf[4];
	int				pid;
	int				msg_rcv;
}		t_bits_info;

// Error macros
# define ERR_ON_SEND "An error has occured when sending a signal to PID"
# define ERR_ON_SIGHDL "An error has occured while setting a sighandler"
# define ERR_USAGE "Usage: ./client <pid> <string>"
# define ERR_PID "Please enter a valid PID"

// Log macros
# define CLT_STARTUP "Client: server pid ="
# define CLT_SENDING "Client: sending data ..."

// LIBFT_H
int		ft_atoi(const char *nptr);

// LIBFTPRINTF_H
int		ft_printf(const char *str, ...);

// MINITALK_H
void	ft_send_signal(int pid, char c);
void	sigusr_handler(int signum, siginfo_t *info, void *ucontext);
void	*ft_memset(void *p, int c, size_t len);

#endif