/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garside <garside@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:22:43 by garside           #+#    #+#             */
/*   Updated: 2025/03/13 13:21:12 by garside          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include "../octolib/includes/libft.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	char	*path;
	char	**cmd;
	char	**env;
}	t_pipex;

void	free_split(char **tab);
char	*find_cmd_path(char *cmd, char **env);
char	*create__check_path(t_pipex *pipex, char *cmd);
void	pipex_fork1(t_pipex *pipex, int pid);
void	pipex_fork2(t_pipex *pipex, int pid);
void	close_all(t_pipex *pipex);
void	exec_fork1( t_pipex *pipex);
void	exec_fork2(t_pipex *pipex);

#endif
