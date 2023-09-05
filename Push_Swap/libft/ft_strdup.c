/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:55:37 by mabasset          #+#    #+#             */
/*   Updated: 2022/09/14 15:10:01 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	ptr = (char *) malloc (sizeof(char) * i + 1);
	i = 0;
	while (s1[i] != 0 && s1[i] != '\n')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
