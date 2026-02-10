/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:59:35 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/10 02:05:06 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Free all value of a double-entry char tab
 * with tab itself 
 * 
 * @param tab The tab to free
 * @param len The number of collumn
 */
void	ft_free_all(char **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}
