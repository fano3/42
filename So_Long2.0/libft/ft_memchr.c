/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mepifano <mepifano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:18:31 by mabasset          #+#    #+#             */
/*   Updated: 2023/02/01 13:58:12 by mepifano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *) s;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}

/*int	main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	printf("%s\n", ft_memchr(s, 2, 3));
	printf("%s\n", s + 2);
}*/
