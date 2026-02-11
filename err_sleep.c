/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:11:42 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/11 18:33:24 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	ft_execute_sleep(char *cmd);

/**
 * @brief If an err was occur 
 * execute if sleep command are present
 * 
 * @param cmd1 Sleep1 with arg
 * @param cmd2 Sleep2 with arg
 */
void	err_sleep(char *cmd1, char *cmd2)
{
	pid_t	pid[2];

	pid[0] = -1;
	if (ft_strnstr(cmd1, "sleep", ft_strlen(cmd1)))
		pid[0] = ft_execute_sleep(cmd1);
	pid[1] = -1;
	if (ft_strnstr(cmd2, "sleep", ft_strlen(cmd2)))
		pid[1] = ft_execute_sleep(cmd1);
	if (pid[0] > 0)
		waitpid(pid[0], NULL, 0);
	if (pid[1] > 0)
		waitpid(pid[1], NULL, 0);
}

/**
 * @brief Exectue a sleep command if present
 * in cmd1 or cmd2 if an error occur
 * 
 * @param cmd The spleep cmd with arg
 */
static pid_t	ft_execute_sleep(char *cmd)
{
	char	**arg;
	char	**env;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		env = create_tab(2);
		env = make_env("LC_COLLATE=en_US.UTF-8", env);
		arg = NULL;
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
