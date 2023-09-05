/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:56:42 by mabasset          #+#    #+#             */
/*   Updated: 2023/02/01 13:58:37 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || (dst == src))
		return (dst);
	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(const char *)(src + i);
		i++;
	}
	return (dst);
}
