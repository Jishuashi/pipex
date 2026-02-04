/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:29:36 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/04 19:22:24 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

int		check_files_exist(char *path);
void	ft_free_all(char **tab, size_t len);
char	**create_tab(size_t len);
void	check_files(char *infile, char *outfile);
size_t	get_nb_arg(char *cmd);
void	check_pid(pid_t pid1, pid_t pid2);

#endif