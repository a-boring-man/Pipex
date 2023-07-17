/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:34:16 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/28 12:48:50 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(t_pipex *pipex, int mode)
{
	int	i;

	i = -1;
	if (pipex->paths && mode)
	{
		while (pipex->paths[++i])
			free(pipex->paths[i]);
		free(pipex->paths);
	}
	i = -1;
	if (pipex->cmd)
	{
		while (pipex->cmd[++i])
			free(pipex->cmd[i]);
		free(pipex->cmd);
	}
	exit (0);
}

static void	ft_check_arg(t_pipex *pipex, int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("not enough argument, please RTFM\n", 2);
		ft_exit(pipex, 1);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		i;

	i = 0;
	ft_check_arg(&pipex, ac);
	ft_pipe(&pipex, pipex.fd);
	ft_cmd_init(&pipex, ac, av);
	pipex.infile = ft_open(av[1], O_RDONLY, 'i');
	pipex.outfile = ft_open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 'o');
	ft_path_init(&pipex, env);
	ft_fork(&pipex, &pipex.id1);
	if (pipex.id1 == 0)
		ft_child1(&pipex, env, i);
	ft_fork(&pipex, &pipex.id2);
	if (pipex.id2 == 0)
		ft_child2(&pipex, env, i + 1);
	close (pipex.fd[0]);
	close (pipex.fd[1]);
	waitpid(pipex.id1, NULL, 0);
	waitpid(pipex.id2, NULL, 0);
	ft_exit(&pipex, 1);
}
