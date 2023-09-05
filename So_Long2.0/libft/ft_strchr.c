/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:07:04 by mabasset          #+#    #+#             */
/*   Updated: 2023/02/01 14:00:05 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*(unsigned char *) s == (unsigned char) c)
			break ;
		s++;
	}
	if (*(unsigned char *) s != (unsigned char) c)
		return (NULL);
	return ((char *) s);
}
