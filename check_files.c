/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:53:35 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/29 19:05:16 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (check_files_exist(outfile))
	{
		if (!access(infile, W_OK) == 0)
		{
			ft_printf("-bash: %s: Permission denied", outfile);
			exit(1);
		}
	}
	return (res);
}
