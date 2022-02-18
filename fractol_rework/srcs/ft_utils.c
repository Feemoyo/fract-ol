/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:43:29 by fmoreira          #+#    #+#             */
/*   Updated: 2022/02/18 17:38:46 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_complex_magnitude(t_complex z)
{
	return (sqrt(pow(z.re, 2) + pow(z.im, 2)));
}

float	ft_atof(char *str)
{
	float			result;
	int				i;
	int				sign;
	unsigned int	len;

	i = 0;
	sign = 1;
	result = 0.0;
	if (!ft_is_charset(str, "-+.0123456789") || ft_strlen(str) > 12)
	{
		ft_putstr_fd("ft_atof: invalid input\n", 2);
		return (0.0);
	}
	result = (float)ft_atof(str);
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.' && str[i + 1])
	{
		++i;
		len = ft_strlen(str) - 1;
		result += (float)ft_atof(str + i) / pow(10, len);
	}
	return (result);
}

t_bool	ft_c_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (TRUE);
		++charset;
	}
	return (FALSE);
}

t_bool	ft_is_charset(const char *str, char *charset)
{
	int	len;

	len = 0;
	while (ft_c_in_charset(str[len], charset) == TRUE && str[len])
		++len;
	if (str[len] == '\0')
		return (TRUE);
	return (FALSE);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
