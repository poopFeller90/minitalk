/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:03:18 by yhajbi            #+#    #+#             */
/*   Updated: 2025/03/01 15:08:57 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define U_HEX "0123456789ABCDEF"
# define L_HEX "0123456789abcdef"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*ft_memset(void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);

int		ft_putchari(char c);
int		ft_strleni(char *str);
int		ft_putstri(char *str);
int		ft_countd(unsigned long n, int base);
int		ft_putnbri(int n);
int		ft_putunbri(unsigned int n);
int		ft_printmemory(void *ptr);
int		ft_printhex(unsigned int n, int flag);
int		ft_handle_specifier(char **str, va_list ptr);
int		ft_switch(char **str, va_list ptr);
int		ft_printf(const char *str, ...);

#endif
