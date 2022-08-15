/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:34:14 by theophilebr       #+#    #+#             */
/*   Updated: 2022/08/03 14:34:37 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	convert;

	i = 0;
	sign = 1;
	convert = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		convert *= 10;
		convert = convert + (s[i] - '0');
		i++;
	}
	return (convert * sign);
}