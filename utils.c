/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:22:44 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/10 15:59:42 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Close the fd of all files
 * 
 * @param file1 
 * @param file2 
 */
void	ft_close(int file1, int file2)
{
	close(file1);
	close(file2);
}

/**
 * @brief Create the tab of the arg for execve 
 * with the command and all arg of the command
 * 
 * @param cmd The command to execute
 * @param arg The arg tab
 * @return char** 
 */
char	**generate_args(char *cmd, char **arg)
{
	size_t	i;
	char	*path;
	char	**cmd_split;
	size_t	nb_args;

	cmd_split = ft_split(cmd, ' ');
	path = ft_strjoin("/usr/bin/", cmd_split[0]);
	nb_args = get_nb_arg(cmd);
	arg = create_tab(nb_args);
	i = 0;
	while (i++ < nb_args)
		arg[i] = cmd_split[i];
	arg[0] = path;
	return (arg);
}

/**
 * @brief Put the env var in the env aray
 * 
 * @param env_arg Var of the env
 * @param env the env
 * @return char** 
 */
char	**make_env(char *env_arg, char **env)
{
	env[0] = env_arg;
	env[1] = NULL;
	return (env);
}
