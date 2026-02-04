/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:20:38 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/04 19:25:19 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	check_status(int status);

void	check_pid(pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;


	if (waitpid(pid2, &status1, 0) == -1)
	{
		perror("waitpid");
		exit(1);
	}
	if (waitpid(pid1, &status2, 0) == -1)
	{
		perror("waitpid");
		exit(1);
	}
	check_status(status1);
	check_status(status2);
}

static	void	check_status(int status)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
			exit(WEXITSTATUS(status));
	}
}
