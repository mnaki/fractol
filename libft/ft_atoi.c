/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:55:29 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 10:55:30 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int			result;

	i = 0;
	sign = 1;
	result = 0;
	if (str == NULL)
		return (0);
	while (!(ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-'))
		++i;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? -1 : sign;
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	return (sign * result);
}
