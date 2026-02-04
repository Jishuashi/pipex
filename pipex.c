/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:29:11 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/04 18:37:18 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		pipex(char *infile, char *outfile, char *cmd1, char *cmd2);
static pid_t	ft_execute(char *cmd, size_t nb_arg, int in_fd, int out_fd);
static void		ft_close(int file1, int file2);
static char		**generate_args(char *cmd, char **arg);

int	main(int ac, char *av[])
{
	int	check;

	if (ac < 5)
	{
		ft_printf("./pipex infile \"cmd1\" \"cmd2\" oufile\n");
		return (1);
	}
	check = check_files(av[1], av[4]);
	if (check == -1)
		exit(1);
	else
		pipex(av[1], av[4], av[2], av[3]);
	return (0);
}

static void	pipex(char *infile, char *outfile, char *cmd1, char *cmd2)
{
	int		fdpipe[2];
	int		file1;
	int		file2;
	pid_t	pid1;
	pid_t	pid2;

	pipe(fdpipe);
	file1 = open(infile, O_RDONLY);
	pid1 = ft_execute(cmd1, get_nb_arg(cmd1), file1, fdpipe[1]);
	ft_close(file1, fdpipe[1]);
	file2 = open(outfile, O_WRONLY | O_CREAT | O_TRUNC);
	pid2 = ft_execute(cmd2, get_nb_arg(cmd1), fdpipe[0], file2);
	ft_close(file2, fdpipe[0]);
	ft_close(fdpipe[0], fdpipe[1]);
	if (waitpid(pid1, NULL, 0) == -1)
		perror("waitpid");
	if (waitpid(pid2, NULL, 0) == -1)
		perror("waitpid");
}

static pid_t	ft_execute(char *cmd, size_t nb_arg, int in_fd, int out_fd)
{
	char	**arg;
	char	**env;
	pid_t	pid;

	pid = fork();
	arg = NULL;
	env = NULL;
	if (pid == 0)
	{
		dup2(in_fd, 0);
		dup2(out_fd, 1);
		ft_close(in_fd, out_fd);
		env = create_tab(1);
		env[0] = NULL;
		arg = generate_args(cmd, arg);
		if (execve(arg[0], arg, env) == -1)
		{
			perror("execve");
			exit(1);
		}
		ft_free_all(env, 1);
		ft_free_all(arg, nb_arg);
	}
	return (pid);
}


static	void	ft_close(int file1, int file2)
{
	close(file1);
	close(file2);
}


static	char	**generate_args(char *cmd, char **arg)
{
	size_t	i;
	char	*path;
	char	**cmd_split;
	size_t	nb_args;

	cmd_split = ft_split(cmd, ' ');
	path = ft_strjoin("/bin/", cmd_split[0]);
	nb_args = get_nb_arg(cmd);
	arg = create_tab(nb_args);
	i = 0;
	while (i++ < nb_args)
		arg[i] = cmd_split[i];
	arg[0] = path;
	return (arg);
}
