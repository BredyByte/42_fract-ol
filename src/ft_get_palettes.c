/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_palettes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:15:43 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/13 21:08:08 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	*get_palettes(void)
{
	static t_palette	array[6];

	array[0] =
		(t_palette){5, 0, {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[1] =
    	 (t_palette){5, 0, {0x610B4B, 0x01A9DB, 0xF4FA58, 0xFE642E, 0xB40404}};
	array[2] =
   		(t_palette){5, 0, {0x000000, 0x311B92, 0x512DA8, 0x6A1B9A, 0x4A148C}};
	return (array);
}
