/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:20:38 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/11 17:46:07 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	check_status(int status);

/**
 * @brief Waits for children and propagates the final exit status.
 * This function prevents zombies process and exit with the second 
 * command status 
 *
 * @param pid1 PID of the first child process.
 * @param pid2 PID of the second child process.
 */
void	check_pid(pid_t pid[2])
{
	int	status1;
	int	status2;

	waitpid(pid[1], &status2, 0);
	waitpid(pid[0], &status1, 0);
	check_status(status2);
}

/**
 * @brief Wait the child process 
 * 
 * @param pid PID of the second child process
 */
void	check_err_pid(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid");
		exit(1);
	}
	check_status(status);
}

/**
 * @brief Analyzes the child process's termination status.
 * and exits the parent process with the error code.
 * 
 * @param status The status integer populated by waitpid.
 */
static void	check_status(int status)
{
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		exit(128 + WTERMSIG(status));
	exit (1);
}
