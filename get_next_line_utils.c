/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:32:44 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/01 19:49:05 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s1_s2;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (NULL);
	len1 = ft_strlen_mod(s1, 0);
	len2 = ft_strlen_mod(s2, 0);
	s1_s2 = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (!s1_s2)
		return (free(s1), NULL);
	ft_strlcpy(s1_s2, s1, len1 + 1);
	ft_strlcpy(s1_s2 + len1, s2, len2 + 1);
	free (s1);
	return (s1_s2);
}

size_t	ft_strlen_mod(const char *s, char end)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (*(s + len) != 0 && *(s + len) != end)
		len++;
	if (*(s + len) == '\n')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	index;

	len = ft_strlen_mod(src, 0);
	if (size == 0)
		return (len);
	index = 0;
	while (index < (size - 1) && *src)
	{
		*dst++ = *src++;
		index++;
	}
	*dst = 0;
	return (len);
}

size_t	ft_new_line_check(char *acc)
{
	if (!acc)
		return (0);
	while (*acc)
	{
		if (*acc == '\n')
			return (1);
		acc++;
	}
	return (0);
}

char	*ft_split_mini(char **acc_ptr)
{
	size_t	len_res;
	size_t	len_acc;
	char	*result;
	char	*new_acc;

	if (!*acc_ptr)
		return (NULL);
	len_res = ft_strlen_mod(*acc_ptr, '\n');
	if (*(*acc_ptr + len_res) != 0)
	{
		len_acc = ft_strlen_mod(*acc_ptr + len_res, 0);
		new_acc = malloc(len_acc + 1 * sizeof(char));
		if (!new_acc)
			return (free(*acc_ptr), *acc_ptr = NULL, NULL);
		ft_strlcpy(new_acc, *acc_ptr + len_res, len_acc + 1);
	}
	else
		new_acc = NULL;
	result = malloc(len_res + 1 * sizeof(char));
	if (!result)
		return (free(*acc_ptr), *acc_ptr = NULL, free(new_acc), NULL);
	ft_strlcpy(result, *acc_ptr, len_res + 1);
	return (free(*acc_ptr), *acc_ptr = new_acc, result);
}
