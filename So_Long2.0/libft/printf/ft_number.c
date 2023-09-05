/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 08:51:47 by mabasset          #+#    #+#             */
/*   Updated: 2022/01/28 23:10:42 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rec_len(unsigned long n, char *base, unsigned long blen, int *len)
{
	if (n >= blen)
		ft_rec_len(n / blen, base, blen, len);
	*len += 1;
}

void	ft_rec(unsigned long n, char *base, unsigned long blen, char *str)
{
	if (n >= blen)
		ft_rec(n / blen, base, blen, str + 1);
	*str = (base[n % blen]);
}

void	ft_negative(long long *n, t_struct *params)
{
	*n *= -1;
	params -> plus = 0;
	params -> space = 0;
}

void	ft_itoa_base(long long n, char *base, t_struct *params)
{
	int		blen;
	int		len;
	int		flag;
	char	*str;

	len = 0;
	flag = 1;
	if (n < 0 || params -> plus == 1 || params -> space == 1)
		flag = 2;
	if (n < 0)
		ft_negative(&n, params);
	blen = ft_strlen(base);
	ft_rec_len(n, base, blen, &len);
	str = (char *) malloc (sizeof(char) * len + flag);
	str[len + flag - 1] = '\0';
	if (flag == 2 && params -> plus == 0 && params -> space == 0)
		str[len] = '-';
	else if (params -> plus == 1)
		str[len] = '+';
	else if (params -> space == 1)
		str[len] = ' ';
	ft_rec(n, base, blen, str);
	ft_strrev(str);
	ft_printnum(str, params);
	free(str);
}

void	ft_utoa_base(unsigned long int n, char *base, t_struct *params, int add)
{
	int		blen;
	int		len;
	char	*str;

	len = 0;
	blen = ft_strlen(base);
	ft_rec_len(n, base, blen, &len);
	if (params -> sharp == 1 && n != 0)
		add = 2;
	str = (char *) malloc (sizeof(char) * (len + add + 1));
	str[len + add] = '\0';
	if (add == 2)
	{
		str[len + 1] = '0';
		str[len] = params -> exe;
	}
	ft_rec(n, base, blen, str);
	ft_strrev(str);
	ft_printnum(str, params);
	free(str);
}
