/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:29:36 by hchartie          #+#    #+#             */
/*   Updated: 2026/02/10 15:24:26 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

void	ft_free_all(char **tab, size_t len);
char	**create_tab(size_t len);
int		check_files(char *infile, char *outfile);
size_t	get_nb_arg(char *cmd);
void	check_pid(pid_t pid1, pid_t pid2);
void	check_err_pid(pid_t pid);
void	cmd_is_empty(char *cmd);
void	ft_close(int file1, int file2);
char	**generate_args(char *cmd, char **arg);
char	**make_env(char *env_arg, char **env);

#endif