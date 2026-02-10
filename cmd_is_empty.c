/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:06:45 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/10 01:35:38 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Check if the cmd is empty and
 * return code 127 command not found if the 
 * command is empty
 * 
 * @param cmd 
 */
void	cmd_is_empty(char *cmd)
{
	if (cmd[0] == '\0')
	{
		ft_putstr_fd(" : command not found\n", 2);
		exit(127);
	}
}
