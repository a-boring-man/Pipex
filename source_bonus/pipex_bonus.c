/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:30:53 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/28 15:22:22 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit(t_pipex *pipex, int mode)
{
	int	i;

	i = -1;
	if (pipex->paths && mode)
	{
		while (pipex->paths[++i])
			ft_free(&(pipex->paths[i]));
		ft_free((char **)&(pipex->paths));
	}
	i = -1;
	if (pipex->cmd)
	{
		while (pipex->cmd[++i])
			ft_free(&(pipex->cmd[i]));
		ft_free((char **)&(pipex->cmd));
	}
	exit (0);
}

int	ft_heredoc(char **av)
{
	if (!ft_strncmp(av[1], "heredoc", 7))
		return (1);
	return (0);
}

static void	ft_check_arg(t_pipex *pipex, int ac, char **av)
{
	if (ac < 5)
	{
		ft_putstr_fd("not enough argument, please RTFM\n", 2);
		ft_exit(pipex, 1);
	}
	if (ft_heredoc(av))
	{
		pipex->heredoc = 1;
		pipex->ac = ac + 1;
	}
	else
	{
		pipex->heredoc = 0;
		pipex->ac = ac;
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		i;

	i = -1;
	ft_check_arg(&pipex, ac, av);
	ft_cmd_init(&pipex, ac, av);
	pipex.infile = ft_open(av[1], O_RDONLY, 'i');
	pipex.outfile = ft_open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 'o');
	ft_path_init(&pipex, env);
	ft_pipe(&pipex, pipex.fd);
	while (++i < ac - 3)
		ft_child(&pipex, ac, env, i);
	while (wait(0) > -1)
		;
	ft_exit(&pipex, 1);
}
