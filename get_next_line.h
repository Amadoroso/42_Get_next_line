/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:33:08 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/25 18:42:31 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s, char end);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_new_line_check(char *acc, ssize_t BUF_SIZE, ssize_t cycle);
char	*ft_strtrim_mod(char *s1, size_t end);
char	*ft_split_mini(char **acc_ptr);

#endif