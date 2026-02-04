/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_exist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:02:55 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/29 16:55:06 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files_exist(char *path)
{
	int	resp;

	resp = access(path, F_OK);
	if (resp == -1)
		return (0);
	return (1);
}
