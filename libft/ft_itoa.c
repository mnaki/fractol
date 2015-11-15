/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:55:20 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:55:20 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char		*str;
	int			tmp;
	int			i;
	int			sign;

	sign = n > 0 ? 1 : -1;
	i = sign == -1 ? 1 : 0;
	tmp = n;
	while (tmp)
	{
		++i;
		tmp = tmp / 10;
	}
	str = ft_strnew((size_t)i);
	tmp = n;
	if (str)
	{
		while (i--)
		{
			str[i] = tmp % 10 * (char)sign + '0';
			tmp = tmp / 10;
		}
		str[0] = sign == -1 && n != 0 ? '-' : str[0];
	}
	return (str);
}
