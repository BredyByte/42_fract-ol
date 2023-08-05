/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:09:54 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/05 20:39:17 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (res);
}
