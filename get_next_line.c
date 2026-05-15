/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:31:59 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/16 00:54:32 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	BUFFER_SIZE;
	ssize_t	read_rtrn;
	size_t	cycle;
	char	*BUFFER;
	static char	*acc;
	
	if (BUFFER_SIZE < 0)
		return (NULL);
	BUFFER = (char *) malloc(BUFFER_SIZE * sizeof(char));
	if (!BUFFER)
		return (NULL);
	cycle = 0;
	while (ft_new_line_check(acc, BUFFER_SIZE * cycle, read_rtrn) == 0)
	{
		read_rtrn = read(fd, BUFFER, BUFFER_SIZE);
		if (read_rtrn == -1)
			return (NULL);		
		*(BUFFER + BUFFER_SIZE) == 0;
		acc = ft_strjoin(acc, BUFFER);
		cycle++;
	}
	// missing returning the correct string
	return (acc);
}
