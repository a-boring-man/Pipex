/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:39:17 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/18 10:54:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *block, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*(unsigned char *)(block + i) = (unsigned char)c;
		i++;
	}
	return (block);
}

int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < size - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_bzero(void *block, size_t size)
{
	ft_memset(block, 0, size);
}

void	*ft_calloc(size_t count, size_t eltsize)
{
	void	*block;

	block = malloc(count * eltsize);
	if (!block)
	{
		ft_putstr_fd("a malloc error append, please check your code", 2);
		exit(0);
	}
	ft_bzero(block, count * eltsize);
	return (block);
}
