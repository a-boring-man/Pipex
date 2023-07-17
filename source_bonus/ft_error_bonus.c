/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:39 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/28 13:15:22 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_open(char *pathname, int flags, char mode)
{
	int	fd;

	if (mode == 'o')
		fd = open(pathname, flags, 0644);
	else
		fd = open(pathname, flags);
	if (fd == -1)
		ft_putstr_fd("an opening error occur, please check your pathname\n", 2);
	return (fd);
}

void	ft_fork(t_pipex *pipex, pid_t *id)
{
	*id = fork();
	if (*id == -1)
	{
		ft_putstr_fd("a fork error occur, please check your code\n", 2);
		ft_exit(pipex, 1);
	}
}

int	ft_pipe(t_pipex *pipex, int	*fd)
{
	if (pipe(fd) == -1)
	{
		ft_putstr_fd("a pipe error occur, please check your code\n", 2);
		ft_exit(pipex, 1);
	}
	return (0);
}

int	ft_dup2(t_pipex *pipex, int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
	{
		ft_putstr_fd("a dup error occur, please check your code\n", 2);
		ft_exit(pipex, 1);
	}
	return (0);
}

void	ft_execve(t_pipex *pipex, char *pathname, char **av, char **env)
{
	if (execve(pathname, av, env) == -1)
	{
		ft_putstr_fd("a execve error occur, please check your path/cmd\n", 2);
		ft_exit(pipex, 0);
	}
}
