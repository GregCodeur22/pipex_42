/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garside <garside@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:39:37 by garside           #+#    #+#             */
/*   Updated: 2025/03/11 18:13:33 by garside          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../octolib/includes/libft.h" 

char	*create__check_path(t_pipex *pipex, char *cmd)
{
	pipex->cmd = ft_split(cmd, ' ');
	if (!pipex->cmd)
		return (NULL);
	pipex->path = find_cmd_path(pipex->cmd[0], pipex->env);
	if (!pipex->path)
	{
		free_split(pipex->cmd);
		return (NULL);
	}
	return (pipex->path);
}

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*get_path_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*try_paths(char **paths, char *cmd)
{
	int		i;
	char	*res;
	char	*resfinal;

	i = 0;
	while (paths[i])
	{
		res = ft_strjoin(paths[i], "/");
		if (!res)
			return (NULL);
		resfinal = ft_strjoin(res, cmd);
		free(res);
		if (!resfinal)
			return (NULL);
		if (access(resfinal, X_OK) != -1)
		{
			free_split(paths);
			return (resfinal);
		}
		free(resfinal);
		i++;
	}
	free_split(paths);
	ft_putstr_fd("Error: command not found\n", 2);
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **env)
{
	char	*path_env;
	char	**paths;
	char	*cmd_path;

	path_env = get_path_env(env);
	if (!path_env)
		return (ft_putstr_fd("Error: PATH not found\n", 2), NULL);
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) != -1)
			return (cmd);
		else
			return (NULL);
	}
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	cmd_path = try_paths(paths, cmd);
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}
