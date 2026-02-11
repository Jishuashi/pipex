/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:29:11 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/11 18:32:18 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		pipex(char *infile, char *outfile, char *cmd1, char *cmd2);
static pid_t	ft_execute(char *cmd, int in_fd, int out_fd, int close_me);
static void		pipex_err(char *cmd2, char *outfile);

/**
 * @brief Entry of the program check files acess
 * and call pipex if all is clear in the infile
 * if access of the infile can't be reached
 * execute only the second command with /dev/null
 * as a infile
 *
 * If outfile exist and write is not permited
 * print errno and exit 1
 * If there is a sleep command, it executes it.
 * @param ac The argument count of the program
 * @param av All argument value of the program
 * @return int Exit Code
 */
int	main(int ac, char *av[])
{
	int		check;

	if (ac != 5)
	{
		ft_putstr_fd("Not engouh argument", 2);
		return (1);
	}
	check = check_files(av[1], av[4]);
	if (check == 1)
		pipex(av[1], av[4], av[2], av[3]);
	else if (check == -1)
	{
		err_sleep(av[2], av[3]);
		exit(1);
	}
	else
		pipex_err(av[3], av[4]);
	return (0);
}

/**
 * @brief Executes command cmd1 with the input file as input and the pipe
 * as output, and the output of the pipe as input to the second command
 * and the output file as output.
 *
 * If any error occur print in sdterr errno and exit with the err code
 * @param infile The int file of the pipe
 * @param outfile The out file of the pipe
 * @param cmd1 The first command execute on the infile
 * @param cmd2 The second command execute on the result of the first
 * command and put it result in outfile
 */
static void	pipex(char *infile, char *outfile, char *cmd1, char *cmd2)
{
	int		p_fd[2];
	int		f[2];
	pid_t	pid[2];

	if (pipe(p_fd) == -1)
		exit(1);
	f[0] = open(infile, O_RDONLY);
	pid[0] = ft_execute(cmd1, f[0], p_fd[1], p_fd[0]);
	close(p_fd[1]);
	close(f[0]);
	f[1] = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	pid[1] = ft_execute(cmd2, p_fd[0], f[1], -1);
	close(p_fd[0]);
	close(f[1]);
	check_pid(pid);
}

/**
 * @brief Create a child process and execute the command
 *
 *
 * @param cmd The command to execute
 * @param nb_arg The nunber of argument of the command
 * @param in_fd The fd of the cmd entry
 * @param out_fd The fd of the cmd exit
 * @return pid_t The pid of the child process
 */
static pid_t	ft_execute(char *cmd, int in_fd, int out_fd, int close_me)
{
	char	**arg;
	char	**env;
	pid_t	pid;

	cmd_is_empty(cmd);
	pid = fork();
	arg = NULL;
	if (pid == 0)
	{
		dup2(in_fd, 0);
		dup2(out_fd, 1);
		ft_close(in_fd, out_fd);
		close(close_me);
		env = create_tab(2);
		env = make_env("LC_COLLATE=en_US.UTF-8", env);
		arg = generate_args(cmd, arg);
		if (execve(arg[0], arg, env) == -1)
		{
			perror("execve");
			exit_child(arg, env);
		}
		ft_free_all(env);
		ft_free_all(arg);
	}
	return (pid);
}

/**
 * @brief Execute the cmd2 if an error occur in infile
 * 
 * @param cmd2 The second command of the pipex program
 * @param outfile The outfile of the cmd
 */
static void	pipex_err(char *cmd2, char *outfile)
{
	int		file;
	int		null_file;
	pid_t	pid;

	null_file = open("/dev/null", O_RDONLY);
	file = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	pid = ft_execute(cmd2, null_file, file, -1);
	close(file);
	close(null_file);
	check_err_pid(pid);
}
