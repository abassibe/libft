/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 02:53:50 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/14 04:17:16 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long int	k;
	int					i;
	int					ret;
	int					p;

	k = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	p = str[i] == '-' ? 1 : 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += str[i] - 48;
		i++;
		if (p == 0 && k > 9223372036854775807)
			return (-1);
		if (p == 1 && k > 9223372036854775807)
			return (0);
	}
	ret = p == 1 ? k * -1 : k;
	return (ret);
}
