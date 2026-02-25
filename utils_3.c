/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:46:06 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/25 12:11:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	is_just_space(char *cmd)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(cmd))
	{
		if (cmd[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	**space_arg(char *cmd, char **arg)
{
	arg = malloc(sizeof(char *) * 2);
	if (!arg)
		return (NULL);
	arg[0] = check_cmd(cmd);
	arg[1] = NULL;
	return (arg);
}
