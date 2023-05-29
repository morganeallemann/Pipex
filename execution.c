/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:38:05 by malleman          #+#    #+#             */
/*   Updated: 2023/05/29 14:22:37 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error\n");
	exit (1);
}

char	*search_path(char *cmds, char **envp)
{
	char	**s_path;
	char	*sep_path;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	s_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (s_path[i])
	{
		sep_path = ft_strjoin(s_path[i], "/");
		path = ft_strjoin(sep_path, cmds);
		free (sep_path);
		if (access(path, F_OK) == 0)
			return (path);
		free (path);
		i++;
	}
	i = 0;
	while (s_path[i])
	{
		free(s_path[i]);
		i++;
	}
	return (0);
}

void	start_execution(char *cmd, char **envp)
{
	char	*path;
	char	**cmds;
	int		i;

	i = 0;
	cmds = ft_split(cmd, ' ');
	path = search_path(cmds[0], envp);
	if (!path)
	{
		while (cmds[i])
		{
			free (cmds[i]);
			i++;
		}
		free (cmds);
	}
	if (execve(path, cmds, envp) == -1)
		error();
}
