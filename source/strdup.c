/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:34:42 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/28 10:12:10 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = ft_calloc(ft_strlen(s) + 1, 1);
	i = -1;
	if (dup)
		while (s[++i])
			dup[i] = s[i];
	return (dup);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd > -1)
		write(fd, s, ft_strlen(s));
}
