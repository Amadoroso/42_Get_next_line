/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:31:59 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/18 20:24:42 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
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
	read_rtrn = 0;
	while (ft_new_line_check(acc, BUFFER_SIZE, cycle) == 0)
	{
		read_rtrn = read(fd, BUFFER, BUFFER_SIZE);
		if (read_rtrn == -1)
			return (NULL);
		*(BUFFER + read_rtrn - 1) = 0;
		acc = ft_strjoin(acc, BUFFER);
		cycle++;
	}
	free(BUFFER);
	return (ft_strtrim_mod(acc));
}

int main()
{
	int fd;
	char	*str;

	fd = open("test", O_RDWR | O_CREAT, 0644);
	write(fd, "wesutygryderxcfgvuyhgtfcg\ndrxcfvyggtdrxcfgvytrydcg fjv\nawzexsdcyreszxd12234\n", 76);
	close(fd);
	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	close(fd);
	return (0);
}