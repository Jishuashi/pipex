/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:29:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/04 00:24:49 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	get_nb_arg(char *cmd)
{
	char		**cmd_split;
	size_t		res;
	size_t		i;

	cmd_split = ft_split(cmd, ' ');
	i = 0;
	while (cmd_split[i] != NULL)
		i++;
	res = i;
	ft_free_all(cmd_split, res);
	return (res);
}
