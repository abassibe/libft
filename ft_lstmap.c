/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:43:07 by abassibe          #+#    #+#             */
/*   Updated: 2017/02/22 21:11:09 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*flst;

	if (!lst)
		return (NULL);
	if (!(nlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	nlst = f(lst);
	flst = nlst;
	while (lst->next)
	{
		if (!(nlst->next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		lst = lst->next;
		nlst->next = f(lst);
		nlst = nlst->next;
	}
	return (flst);
}
