/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasbeer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:53:08 by hcasbeer          #+#    #+#             */
/*   Updated: 2018/01/30 14:53:08 by hcasbeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

void	abort_error(int code)
{
	ft_putstr("map error\n");
	if (code != 0)
		exit(code);
}
