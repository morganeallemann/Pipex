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

void	first_process(char **av, char **envp, int *fd)
{
	int r_file;

	r_file = open(av[1], O_RDONLY, 0640);
	if (r_file == -1)
		error();
	dup2(fd[1], STDIN_FILENO);
	dup2(r_file, STDOUT_FILENO);
	close(fd[0]);
	start_execution(av[2], envp);
}

void	second_process(char **av, char **envp, int *fd)
{
	int w_file;
	
	w_file = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0640);
	if (w_file == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(w_file, STDOUT_FILENO);
	close(fd[1]);
	start_execution(av[3], envp);
}


int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		else if (pid == 0)
			first_process(av, envp, fd);
		waitpid(pid, NULL, 0);
		second_process(av, envp, fd);
		return (0);
	}
	else 
	{
		ft_printf("Error: Arguments invalides\n");
		exit (1);
	}
	return (0);
}
