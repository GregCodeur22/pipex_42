/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garside <garside@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:20:43 by garside           #+#    #+#             */
/*   Updated: 2025/03/13 13:22:06 by garside          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../octolib/includes/libft.h" 

void	free_all(t_pipex *pipex)
{
	if (pipex->cmd[0] != pipex->path)
		free(pipex->path);
	if (pipex->cmd)
		free_split(pipex->cmd);
}

void	pipex_fork1(t_pipex *pipex, int pid)
{
	if (pid == 1)
	{
		if (pipex->infile == -1)
		{
			free_all(pipex);
			return ;
		}
		pipex->pid_1 = fork();
		if (pipex->pid_1 == -1)
			(close_all(pipex), free(pipex));
		if (pipex->pid_1 == 0)
			exec_fork1(pipex);
		free_all(pipex);
	}
}

void	pipex_fork2(t_pipex *pipex, int pid)
{
	if (pid == 2)
	{
		if (pipex->outfile == -1)
		{
			free_all(pipex);
			return ;
		}
		pipex->pid_2 = fork();
		if (pipex->pid_2 == -1)
			(close_all(pipex), free(pipex));
		if (pipex->pid_2 == 0)
			exec_fork2(pipex);
		free_all(pipex);
	}
}
