/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 08:51:41 by mabasset          #+#    #+#             */
/*   Updated: 2022/01/27 16:30:44 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	len = 0;
	while (str[len] != '\0')
		len++;
	len -= 1;
	i = 0;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
}

void	ft_struct_init(t_struct *params)
{
	params -> minus = 0;
	params -> zero = 0;
	params -> sharp = 0;
	params -> exe = 'x';
	params -> space = 0;
	params -> plus = 0;
	params -> point = 0;
	params -> width = 0;
	params -> precision = 0;
	params -> len = 0;
	params -> dbase = "0123456789\0";
	params -> ebase = "0123456789abcdef\0";
	params -> e_base = "0123456789ABCDEF\0";
}

int	ft_checkidentifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_precision(const char *str, int i, t_struct *params)
{
	params -> point = 1;
	while (ft_checkidentifier(str[i]) == 0 && ft_isdigit(str[i]) == 1)
	{
		params -> precision *= 10;
		params -> precision += str[i] - '0';
		i++;
	}
	i -= 1;
	return (i);
}

void	ft_width(char ch, t_struct *params)
{
	params -> width *= 10;
	params -> width += ch - '0';
}
