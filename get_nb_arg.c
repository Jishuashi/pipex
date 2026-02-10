/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:29:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/10 02:02:32 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Get the nb arg int the cmd string
 * 
 * @param cmd The cmd string with arg
 * @return size_t The number of the arg of cmd  + cmd itself
 */
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
