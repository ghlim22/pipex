/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:32:04 by gylim             #+#    #+#             */
/*   Updated: 2023/03/01 15:50:45 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int	convert(int fd, const char **str, va_list ap)
{
	++*str;
	if (**str == 'c')
		return (print_char(fd, va_arg(ap, int)));
	else if (**str == 's')
		return (print_str(fd, va_arg(ap, char *)));
	else if (**str == 'p')
		return (print_addr(fd, va_arg(ap, void *)));
	else if (**str == 'd' || **str == 'i')
		return (print_nbr(fd, va_arg(ap, int)));
	else if (**str == 'u')
		return (print_uint(fd, va_arg(ap, unsigned int)));
	else if (**str == 'x')
		return (print_hex(fd, va_arg(ap, unsigned int), HEX_LOWER));
	else if (**str == 'X')
		return (print_hex(fd, va_arg(ap, unsigned int), HEX_UPPER));
	else if (**str == '%')
		return (ft_write(fd, "%%", 1));
	else
		return (ERROR);
}

int	ft_printf(int fd, const char *str, ...)
{
	int		cnt;
	int		temp_cnt;
	va_list	ap;

	if (!str)
		return (ERROR);
	cnt = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			temp_cnt = ft_write(fd, str, 1);
		else
			temp_cnt = convert(fd, &str, ap);
		if (temp_cnt == ERROR)
			return (ERROR);
		cnt += temp_cnt;
		++str;
	}
	va_end(ap);
	return (cnt);
}
