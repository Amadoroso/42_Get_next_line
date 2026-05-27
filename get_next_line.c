/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:31:59 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/27 15:44:18 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		read_rtrn;
	size_t		cycle;
	char		*buffer;
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
			return (free(buffer), NULL);
		if (read_rtrn == 0)
			break ;
		*(buffer + read_rtrn) = 0;
		acc = ft_strjoin(acc, buffer);
		cycle++;
	}
	return (free(buffer), ft_split_mini(&acc));
}

/* int main()
{
	int fd;
	int i;

	fd = open("test1", O_RDWR | O_CREAT, 0644);

	i = -20;
	while (i++ < 0)
		printf("%s", get_next_line(fd));
	return (0);
	
} */

/* int main()
{
	printf("%s", get_next_line(0));
	return (0);
} */

/* int main()
{
	int fd;
	char	*str;

	fd = open("test", O_RDWR | O_CREAT, 0644);
	write(fd, NULL, 1);
	close(fd);
	fd = open("test", O_RDONLY);
	fd = 6;
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
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	close(fd);
	return (0);
} */