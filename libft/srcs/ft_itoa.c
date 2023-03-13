/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:51:32 by gylim             #+#    #+#             */
/*   Updated: 2022/11/21 17:52:12 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_base(long long nbr, char *base);
static int	ft_baselen(char *base);
static int	ft_nbrlen(long long nbr, char *base);
static void	ft_fill(long long nbr, char *str, char *base, int i);

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, "0123456789"));
}

static char	*ft_itoa_base(long long nbr, char *base)
{
	char	*str;
	int		base_len;
	int		str_size;

	base_len = ft_baselen(base);
	str_size = 1;
	if (!base_len)
		return (NULL);
	if (nbr < 0)
		str_size++;
	str_size += ft_nbrlen(nbr, base);
	str = malloc(str_size);
	if (!str)
		return (NULL);
	ft_fill(nbr, str, base, str_size - 2);
	str[str_size - 1] = '\0';
	return (str);
}

static int	ft_baselen(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

static int	ft_nbrlen(long long nbr, char *base)
{
	int	nbr_len;
	int	base_len;

	base_len = ft_baselen(base);
	if (!base_len)
		return (0);
	if (nbr < 0)
		nbr *= -1;
	nbr_len = 1;
	while (nbr >= base_len)
	{
		nbr_len++;
		nbr /= base_len;
	}
	return (nbr_len);
}

static void	ft_fill(long long nbr, char *str, char *base, int i)
{
	int	base_len;

	base_len = ft_baselen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr >= base_len)
		ft_fill(nbr / base_len, str, base, i - 1);
	str[i] = base[nbr % base_len];
}
