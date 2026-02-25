/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:34:33 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/25 11:48:57 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Check:
 * 
 * If the infile exist and can be read if not return 1 to execute only cmd2
 * 
 * If the outfile exist and can be edited if not return -1 to exit
 * with code 1
 * 
 * In case of an error print errno on the stderr
 * @param infile 
 * @param outfile 
 * @return int 
 */
int	check_files(char *infile, char *outfile)
{
	if (access(outfile, F_OK) == 0 && access(outfile, W_OK) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(outfile, 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	if (access(infile, F_OK) == -1 || access(infile, R_OK) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(infile, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}

/**
 * @brief Check if the cmd is empty and
 * return code 127 command not found if the 
 * command is empty
 * 
 * @param cmd 
 */
int	cmd_is_empty(char *cmd)
{
	if (cmd[0] == '\0')
	{
		ft_putstr_fd(" : command not found\n", 2);
		return (1);
	}
	return (0);
}

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

/**
 * @brief Free all value of a double-entry char tab
 * with tab itself 
 * 
 * @param tab The tab to free
 * @param len The number of collumn
 */
void	ft_free_all(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	exit_child(char	**arg, char	**env)
{
	ft_free_all(env);
	ft_free_all(arg);
	exit(127);
}
