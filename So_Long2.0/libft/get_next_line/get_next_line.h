/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabasset <mabasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:41:05 by mabasset          #+#    #+#             */
/*   Updated: 2022/02/14 11:14:12 by mabasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_findchr(const char *s, char c);
char	*get_next_line(int fd);
int		ft_strcpy(char *s1, char *s2);
char	*ft_save(char *str);

#endif