/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 08:51:56 by mabasset          #+#    #+#             */
/*   Updated: 2022/02/17 12:28:05 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft.h"

typedef struct s_struct
{
	int		minus;
	int		zero;
	int		sharp;
	char	exe;
	int		space;
	int		plus;
	int		point;
	int		width;
	int		precision;
	size_t	len;
	char	*dbase;
	char	*ebase;
	char	*e_base;
}				t_struct;

int		ft_printf(const char *str, ...);
void	ft_strrev(char *str);
void	ft_printchar(char c, t_struct *params);
void	ft_printstr(char *str, t_struct *params);
void	ft_printnum(char *str, t_struct *params);
void	ft_struct_init(t_struct *params);
int		ft_checkflags(const char *str, t_struct *params);
int		ft_checkidentifier(char c);
void	ft_identifier(char c, va_list arg, t_struct *params);
void	ft_utoa_base(unsigned long int n, char *base, t_struct *params, int a);
void	ft_itoa_base(long long n, char *base, t_struct *params);
int		ft_precision(const char *str, int i, t_struct *params);
void	ft_width(char ch, t_struct *params);
void	ft_print_params(t_struct *params);

#endif
