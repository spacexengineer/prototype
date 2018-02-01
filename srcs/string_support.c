/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasbeer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:55:09 by hcasbeer          #+#    #+#             */
/*   Updated: 2018/01/29 18:55:09 by hcasbeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen_until(char *str, char c)
{
	int i;

	i = 0;
	while (*str != c && *str)
	{
		++str;
		++i;
	}
	return (i);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		++str;
		++i;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int strlen;

	strlen = ft_strlen(str);
	write(1, str, strlen);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_atoi(char *str)
{
	int sign;
	int count;
	int num;

	sign = 1;
	num = 0;
	count = 0;
	while ((str[count] >= '\t' && str[count] <= '\r') || str[count] == ' ')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		sign = str[count] == '+' ? 1 : -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		num = 10 * num + (str[count] - '0');
		count++;
	}
	return (sign == -1 ? -num : num);
}
