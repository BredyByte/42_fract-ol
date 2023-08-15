/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:09:54 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/15 16:11:39 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_remove_first_and_last_line(char *str)
{
	char	*start;
	char	*end;
	int		len;

	if (!str)
		return (NULL);
	start = ft_strchr(str, '*');
	if (!start)
		return (NULL);
	start++;
	end = ft_strrchr(str, '*');
	if (!end)
		return (NULL);
	len = end - start;
	return (ft_substr(start, 0, len));
}

char	*ft_read_all(int fd)
{
	char	*res;
	char	*temp;
	char	*line;
	char	*processed_res;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		temp = line;
		res = ft_strjoin(res, temp);
		free(line);
		line = get_next_line(fd);
	}
	processed_res = ft_remove_first_and_last_line(res);
	free(res);
	return (processed_res);
}
