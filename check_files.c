/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:53:35 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/29 16:56:16 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	create_file(char *path);

int	check_files(char *infile, char *outfile)
{
	int	res;

	res = 0;
	if (check_files_exist(infile))
	{
		if (!access(infile, R_OK) == 0)
		{
			ft_printf("-bash: %s: Permission denied", infile);
			res = -1;
		}
	}
	else
	{
		res = -1;
		ft_printf("-bash: %s: No such file or directory", infile);
	}
	if (!check_files_exist(outfile))
		create_file(outfile);
	return (res);
}

static void	create_file(char *path)
{
	pid_t	pid;
	char	*bin_path;
	char	**args;
	char	**env;

	bin_path = "/bin/touch";
	args = create_tab(3);
	env = create_tab(1);
	if (!args)
		exit(1);
	args[0] = bin_path;
	args[1] = path;
	args[2] = NULL;
	env[0] = NULL;
	pid = fork();
	if (pid == 0)
	{
		execve(bin_path, args, env);
		perror("execve");
	}
	else if (pid > 0)
		wait(NULL);
}
