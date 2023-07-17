/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:28 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/28 15:21:59 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_get_path(t_pipex *pipex, char *cmd)
{
	int		i;
	char	**tmp;
	char	*tmp1;

	i = -1;
	tmp = ft_split(cmd, ' ');
	while (pipex->paths[++i])
	{
		if (access(tmp[0], F_OK) == 0)
			return (tmp[0]);
		tmp1 = ft_strjoin(pipex->paths[i], tmp[0]);
		if (access(tmp1, F_OK) == 0)
			return (tmp1);
		ft_free(&tmp1);
	}
	ft_putstr_fd("an cmd acces error occur, please check your cmd\n", 2);
	exit (0);
}
