/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:26:40 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/18 16:28:10 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

int ft_isspace(int c)
{
    return (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == ' ');
}

double ft_atof(const char *str)
{
    double res;
    double frac;
    int sign;
    bool is_fraction;
    int frac_power;

    res = 0.0;
    frac = 0.0;
    sign = 1;
    is_fraction = false;
    frac_power = 1;

    while (ft_isspace(*str))
        str++;

    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;

    while ((*str >= '0' && *str <= '9') || *str == '.')
    {
        if (*str == '.')
        {
            is_fraction = true;
            str++;
            continue;
        }
        if (is_fraction)
        {
            frac = frac * 10 + (*str - '0');
            frac_power *= 10;
        }
        else
        {
            res = res * 10 + (*str - '0');
        }
        str++;
    }

    return (res + frac/frac_power) * sign;
}
