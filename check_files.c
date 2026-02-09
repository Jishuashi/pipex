/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:53:35 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/09 17:39:52 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <errno.h>
#include <string.h>

int	check_files(char *infile, char *outfile)
{
	if (access(infile, F_OK) == -1 || access(infile, R_OK) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(infile, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	if (access(outfile, F_OK) == 0 && access(outfile, W_OK) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(outfile, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}
