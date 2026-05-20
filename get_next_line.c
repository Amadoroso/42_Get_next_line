/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:31:59 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/20 18:13:56 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	read_rtrn;
	size_t	cycle;
	char	*buffer;
	static char	*acc;
	
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	cycle = 0;
	read_rtrn = 0;
	while (!ft_new_line_check(acc, BUFFER_SIZE, cycle))
	{
		read_rtrn = read(fd, buffer, BUFFER_SIZE);
		if (read_rtrn == -1)
			return (NULL);
		*(buffer + read_rtrn) = 0;
		acc = ft_strjoin(acc, buffer);
		cycle++;
	}
	free(buffer);
	return (ft_split_mod(&acc));
}

/* int main()
{
	int fd;
	char	*str;

	fd = open("test", O_RDWR | O_CREAT, 0644);
	write(fd, "wesutygryderxcfgvuyhgtfcg\ndrxcfvyggtdrxcfgvytrydcg fjv\nawzexsdcyreszxd12234\n", 76);
	close(fd);
	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	close(fd);
	return (0);
} */