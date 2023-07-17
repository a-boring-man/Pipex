/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:48:04 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/28 12:37:59 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_path_init(t_pipex *pipex, char **env)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = NULL;
	while (env[++i])
		if ((env[i] + 5) && !ft_strncmp(env[i], "PATH=", 5))
			tmp = ft_split(env[i] + 5, ':');
	if (!tmp)
	{
		ft_putstr_fd("a path error occur, please check the environment", 2);
		ft_exit(pipex, 1);
	}
	i = 0;
	while (tmp[i])
		i++;
	pipex->paths = ft_calloc(i + 1, sizeof(char *));
	i = -1;
	while (tmp[++i])
		pipex->paths[i] = ft_strjoin(tmp[i], "/");
	free (tmp);
}
