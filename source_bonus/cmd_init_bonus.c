/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:40:48 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/28 13:13:51 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_cmd_init(t_pipex *pipex, int ac, char **av)
{
	int	i;

	i = -1;
	pipex->cmd = ft_calloc(ac - 1, sizeof(char *));
	if (!pipex->cmd)
		ft_exit(pipex, 1);
	while (++i < ac - 3)
	{
		pipex->cmd[i] = ft_strdup(av[i + 2]);
		if (!pipex->cmd[i])
			ft_exit(pipex, 1);
		if (!pipex->cmd[i][0])
		{
			ft_putstr_fd("a command line is empty, please check your input", 2);
			ft_exit(pipex, 1);
		}
	}
}
