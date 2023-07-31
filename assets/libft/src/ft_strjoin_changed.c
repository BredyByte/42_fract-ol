/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_changed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:37:15 by dbredykh          #+#    #+#             */
/*   Updated: 2023/07/31 17:38:03 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_changed(char *s1, char *s2)
{
	char	*res;
	size_t	len;

	if (s1 == NULL)
		return (s2);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	ft_strlcat(res, s2, len + 1);
	free(s1);
	free(s2);
	return (res);
}
