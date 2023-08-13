/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_palettes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:15:43 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/13 16:11:22 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	*get_palettes(void)
{
	static t_palette	array[5];
/* 	array[0]
		= (t_palette){5, 0, {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF}}; // blue */
	array[0]
		= (t_palette){5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	array[1]
		= (t_palette){5, 0, {0xFED7D7, 0xFED3A0, 0xFEEA7E, 0xC4F0C5, 0xA9DEF9}};
	array[2] = (t_palette){5, 0, {0x1B262C, 0x0F4C75, 0x3282B8, 0xBBE1FA, 0x1F4E78}}; // blue
	array[3] = (t_palette){5, 0, {0x6B4226, 0x942B3D, 0xBF2A6A, 0xE43E8B, 0xFF69B4}}; // green
	array[4] = (t_palette){5, 0, {0x004D2D,  0x006F44, 0x00A15E, 0x00D478, 0x00FF8D}}; // violet
	return (array);
}
