/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:13:34 by malleman          #+#    #+#             */
/*   Updated: 2023/05/29 14:18:36 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	child_process(char *av, char **envp)
{
	int		fd[2];
	pid_t	pid;
	
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		start_execution(av, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	
}

int	file_access(char *av, int access)
{
	int	file;

	file = 0;
	if (access == 0)
		file = open(av, O_RDONLY, 0777);
	else if (access == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0640);
	else if (access == 2)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0640);
	if (file == -1)
		error();
	return (file);
}

int	main(int ac, char **av, char **envp)
{
	int		in_file;
	int		out_file;
	int		cmd;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			cmd = 3;
			out_file = file_access(av[ac - 1], 2);
		}
		else
		{
			cmd = 2;
			out_file = file_access(av[ac - 1], 1);
			in_file = file_access(av[1], 0);
			dup2(in_file, STDIN_FILENO);

		}
		while (cmd < ac - 2)
			child_process(av[cmd++], envp);
		dup2(out_file, STDOUT_FILENO);
		start_execution(av[ac - 2], envp);
	}
	else
	{
		ft_printf("Nombre d'arguments incorrects\n");
		exit (1);
	}
	return (0);
}
