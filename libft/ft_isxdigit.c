/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:08:58 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/04 11:09:02 by nmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isxdigit(int c)
{
	if (c == '0'
		|| c == '1'
		|| c == '2'
		|| c == '3'
		|| c == '4'
		|| c == '5'
		|| c == '6'
		|| c == '7'
		|| c == '8'
		|| c == '9'
		|| c == 'a'
		|| c == 'b'
		|| c == 'c'
		|| c == 'd'
		|| c == 'e'
		|| c == 'f'
		|| c == 'A'
		|| c == 'B'
		|| c == 'C'
		|| c == 'D'
		|| c == 'E'
		|| c == 'F')
		return (1);
	return (0);
}
