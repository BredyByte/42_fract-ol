/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:09:54 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/03 18:48:28 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
static char	*ft_remove_comments(char *str)
{

} */

char	*ft_read_all(int fd)
{
	char	*res;
	char	*temp;
	char	*line;

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
	/* res = ft_remove_comments(res); */
	return (res);
}
