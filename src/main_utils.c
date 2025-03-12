/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garside <garside@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:20:43 by garside           #+#    #+#             */
/*   Updated: 2025/03/11 18:50:37 by garside          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../octolib/includes/libft.h" 

void	pipex_fork(t_pipex *pipex, int pid)
{
	if (pid == 1)
	{
		pipex->pid_1 = fork();
		if (pipex->pid_1 == -1)
			(close_all(pipex), free(pipex));
		if (pipex->pid_1 == 0)
			exec_fork1(pipex);
		if (pipex->cmd[0] != pipex->path)
			free(pipex->path);
		free_split(pipex->cmd);
	}
	if (pid == 2)
	{
		pipex->pid_2 = fork();
		if (pipex->pid_2 == -1)
			(close_all(pipex), free(pipex));
		if (pipex->pid_2 == 0)
			exec_fork2(pipex);
		if (pipex->cmd[0] != pipex->path)
			free(pipex->path);
		free_split(pipex->cmd);
	}
}
