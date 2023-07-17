/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:52:26 by jrinna            #+#    #+#             */
/*   Updated: 2021/11/12 08:59:16 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

# define ERROR_ARG "argument error \n"
# define ERROR_PIPE "pipe error \n"
# define ERROR_FORK "fork error \n"
# define ERROR_OPENING "opening error \n"
# define ERROR_CMD "cmd error \n"

typedef struct s_pipex
{
	int		fd[2];
	pid_t	id1;
	pid_t	id2;
	int		infile;
	int		outfile;
	char	**paths;
	char	**cmd;
}	t_pipex;

int		ft_strncmp(char *s1, char *s2, int size);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t eltsize);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
void	ft_cmd_init(t_pipex *pipex, int ac, char **av);
void	ft_path_init(t_pipex *pipex, char **env);
void	ft_child1(t_pipex *pipex, char **env, int i);
void	ft_child2(t_pipex *pipex, char **env, int i);
char	*ft_get_path(t_pipex *pipex, char *cmd);
int		ft_pipe(t_pipex *pipex, int	*fd);
void	ft_fork(t_pipex *pipex, pid_t *id);
int		ft_dup2(t_pipex *pipex, int oldfd, int newfd);
int		ft_open(char *pathname, int flags, char mode);
void	ft_execve(t_pipex *pipex, char *pathname, char **av, char **env);
void	ft_putstr_fd(char *s, int fd);
void	ft_exit(t_pipex *pipex, int mode);

#endif