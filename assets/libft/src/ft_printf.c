/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:03:46 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/19 16:27:53 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_types(const char *str, size_t i, va_list param)
{
	size_t	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(param, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(param, char *));
	else if (str[i] == '%')
		count += ft_putchar('%');
	else if (str[i] == 'i' || str[i] == 'd')
		count += ft_putdec(va_arg(param, int));
	else if (str[i] == 'u')
		count += ft_putdeclong(va_arg(param, size_t));
	else if (str[i] == 'p')
		count += ft_putvoid(va_arg(param, void *));
	if (str[i] == 'x')
		count += ft_puthexa(va_arg(param, unsigned int), 'x');
	if (str[i] == 'X')
		count += ft_puthexa(va_arg(param, unsigned int), 'X');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	count;
	va_list	param;

	va_start(param, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else
		{
			i++;
			count += ft_types(str, i, param);
		}
		i++;
	}
	va_end(param);
	return ((int)count);
}
