/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 02:18:04 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/14 03:33:50 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*compte(int value)
{
	char	*ret;

	if (value <= 2047)
		ret = ft_strdup("110xxxxx10xxxxxx");
	else if (value <= 57471)
		ret = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else
		ret = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	if (!ret)
		return (NULL);
	return (ret);
}

char			*ft_itoa_base_unicode(int value, int base)
{
	char	*retour;
	int		nb;
	int		i;
	char	*tab;

	tab = "0123456789abcdef";
	if (value == 0)
		return (ft_strdup("0"));
	if (!(retour = compte(value)))
		return (NULL);
	nb = ft_strlen(retour);
	i = 1;
	while (value != 0)
	{
		while (retour[nb - i] != 'x')
			i++;
		retour[nb - i] = tab[value % base];
		value /= base;
		i++;
	}
	return (retour);
}
