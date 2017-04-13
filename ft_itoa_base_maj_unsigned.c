/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 02:18:04 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/13 14:14:20 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		compte(unsigned long long nbr, int base)
{
	int		ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}

char			*ft_itoa_base_maj_unsigned(unsigned long long value, int base)
{
	char	*retour;
	int		nb;
	int		i;
	char	*tab;

	tab = "0123456789ABCDEF";
	if (value == 0)
		return (ft_strdup("0"));
	nb = compte(value, base);
	retour = (char *)malloc(nb + 1);
	i = 1;
	while (value != 0)
	{
		retour[nb - i] = tab[value % base];
		value /= base;
		i++;
	}
	retour[nb] = '\0';
	return (retour);
}
