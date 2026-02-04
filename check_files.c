/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:53:35 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/04 19:01:42 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <errno.h>
#include <string.h>

int	check_files(char *infile, char *outfile)
{
	int	res;

	res = 0;
	if (access(infile, F_OK) == -1)
	{
		ft_printf("pipex: %s: %s\n", infile, strerror(errno));
		res = -1;
	}
	else if (access(infile, R_OK) == -1)
	{
		ft_printf("pipex: %s: %s\n", infile, strerror(errno));
		res = -1;
	}
	if (access(outfile, F_OK) == 0 && access(outfile, W_OK) == -1)
		ft_printf("pipex: %s: %s\n", outfile, strerror(errno));
	return (res);
}
