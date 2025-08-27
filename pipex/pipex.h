/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:10:32 by npetitpi          #+#    #+#             */
/*   Updated: 2022/12/28 23:18:58 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

int		ft_counter(char const *s, char c);
void	ft_free(char **strs, int words_index);
char	**ft_split(char *s, char c);
char	**ft_split2(const char *s, char c, char **strs, int nb_words);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*acces_command(char *cmd_name, char **paths);
char	*find_path(char *cmd_name, char **env);
int		initiate_child_process(char **av, int i, int *pipe_fd, char **env);
int		main(int ac, char **av, char **env);
void	ft_frees(char **paths);
void	ft_error(void);
void	fail_execve(char **arg);
void	first_cmd(char **env, char *infile, char **arg, int *pipe_fd);
void	second_cmd(char **env, char *outfile, char **arg, int *pipe_fd);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(char *str1, char *str2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	close_all(int fd, int pipefd[2]);

#endif