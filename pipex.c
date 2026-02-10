/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:29:11 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/10 15:48:10 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		pipex(char *infile, char *outfile, char *cmd1, char *cmd2);
static pid_t	ft_execute(char *cmd, size_t nb_arg, int in_fd, int out_fd);
static void		pipex_err(char *cmd2, char *outfile);
static void	ft_execute_sleep(char *cmd, size_t nb_arg);

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
	if (ac != 5)
	{
		ft_putstr_fd("Not engouh argument", 2);
		return (1);
	}
	if (check_files(av[1], av[4]) == 1)
		pipex(av[1], av[4], av[2], av[3]);
	else if (check_files(av[1], av[4]) == -1)
	{
		if (!ft_strnstr(av[2], "sleep", get_nb_arg(av[2])))
		{
			ft_execute_sleep(av[2], get_nb_arg(av[2]));
		}
		else if (!ft_strnstr(av[3], "sleep", get_nb_arg(av[3])))
		{
			ft_execute_sleep(av[3], get_nb_arg(av[3]));
		}
		return (1);
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
	int		fdpipe[2];
	int		file;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fdpipe))
	{
		perror("pipe");
		exit(1);
	}
	file = open(infile, O_RDONLY);
	pid1 = ft_execute(cmd1, get_nb_arg(cmd1), file, fdpipe[1]);
	ft_close(file, fdpipe[1]);
	file = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	cmd_is_empty(cmd2);
	pid2 = ft_execute(cmd2, get_nb_arg(cmd1), fdpipe[0], file);
	ft_close(file, fdpipe[0]);
	ft_close(fdpipe[0], fdpipe[1]);
	check_pid(pid1, pid2);
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
static pid_t	ft_execute(char *cmd, size_t nb_arg, int in_fd, int out_fd)
{
	char	**arg;
	char	**env;
	pid_t	pid;

	pid = fork();
	arg = NULL;
	if (pid == 0)
	{
		dup2(in_fd, 0);
		dup2(out_fd, 1);
		ft_close(in_fd, out_fd);
		env = create_tab(2);
		env = make_env("LC_COLLATE=en_US.UTF-8", env);
		arg = generate_args(cmd, arg);
		if (execve(arg[0], arg, env) == -1)
		{
			perror("execve");
			ft_free_all(env, 2);
			ft_free_all(arg, nb_arg);
			exit(127);
		}
		ft_free_all(env, 2);
		ft_free_all(arg, nb_arg);
	}
	return (pid);
}

static void	pipex_err(char *cmd2, char *outfile)
{
	int		file;
	int		null_file;
	pid_t	pid;

	null_file = open("/dev/null", O_RDONLY);
	file = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	pid = ft_execute(cmd2, get_nb_arg(cmd2), null_file, file);
	close(file);
	close(null_file);
	check_err_pid(pid);
}

static void	ft_execute_sleep(char *cmd, size_t nb_arg)
{
	pid_t	pid;
	char	**arg;
	char	**env;

	pid = fork();
	arg = NULL;
	env = create_tab(2);
	env = make_env("LC_COLLATE=en_US.UTF-8", env);
	arg = generate_args(cmd, arg);
	if (execve(arg[0], arg, env) == -1)
	{
		perror("execve");
		free(env);
		ft_free_all(arg, nb_arg);
		exit(127);
	}
	free(env);
	ft_free_all(arg, nb_arg);
	exit(1);
}
