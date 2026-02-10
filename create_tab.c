/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:45:36 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/29 16:06:31 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Create a double-entry table in the 
 * memory 
 * 
 * @param len The len of the collumn
 * @return char** An alloued double-entry tab
 */
char	**create_tab(size_t len)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * len);
	if (!res)
	{
		ft_putstr_fd("Error on memory allocation", 2);
		exit(1);
	}
	return (res);
}
