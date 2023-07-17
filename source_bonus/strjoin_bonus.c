/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:39:27 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/28 15:22:56 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **s)
{
	if (*s)
		free(*s);
	*s = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	while (s1 && s1[j])
		new_line[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		new_line[i++] = s2[j++];
	new_line[i] = '\0';
	if (s1)
		ft_free(&s1);
	return (new_line);
}
