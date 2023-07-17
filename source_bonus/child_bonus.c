/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:52:04 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/01 09:52:31 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_child(t_pipex *pipex, int ac, char **env, int i)
{
	pipex->fd[2] = pipex->fd[0];
	ft_pipe(pipex, pipex->fd);
	ft_fork(pipex, &pipex->id);
	if (!pipex->id)
	{
		close(pipex->fd[0]);
		if (i == 0)
			ft_dup2(pipex, pipex->infile, pipex->fd[2]);
		if (i == ac - 4)
			ft_dup2(pipex, pipex->outfile, pipex->fd[1]);
		ft_dup2(pipex, pipex->fd[2], 0);
		ft_dup2(pipex, pipex->fd[1], 1);
		ft_execve(pipex, ft_get_path(pipex, pipex->cmd[i]),
			ft_split(pipex->cmd[i], ' '), env);
	}
	close(pipex->fd[1]);
	close(pipex->fd[2]);
}
