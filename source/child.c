/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:47:40 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/28 15:23:19 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(t_pipex *pipex, char **env, int i)
{
	close(pipex->fd[0]);
	ft_dup2(pipex, pipex->fd[1], 1);
	ft_dup2(pipex, pipex->infile, 0);
	close(pipex->fd[1]);
	ft_execve(pipex, ft_get_path(pipex, pipex->cmd[i]),
		ft_split(pipex->cmd[i], ' '), env);
}

void	ft_child2(t_pipex *pipex, char **env, int i)
{
	close(pipex->fd[1]);
	ft_dup2(pipex, pipex->fd[0], 0);
	ft_dup2(pipex, pipex->outfile, 1);
	close(pipex->fd[0]);
	ft_execve(pipex, ft_get_path(pipex, pipex->cmd[i]),
		ft_split(pipex->cmd[i], ' '), env);
}
