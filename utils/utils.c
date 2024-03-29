/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:25:31 by juhagon           #+#    #+#             */
/*   Updated: 2022/09/20 12:26:53 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long int gettime()
{
	long long int		seconds;
	long long int		micro;
	struct timeval 		test;
	gettimeofday(&test, NULL);

	seconds = test.tv_sec * 1000LL;
	micro = test.tv_usec / 1000;

	return(seconds + micro);
}

long long int	ft_atoi(const char *s)
{
	long long int	tmp;
	long long int	nmb;
	long long int	sign;

	tmp = 0;
	nmb = 0;
	sign = 0;
	while (s[tmp] == 32 || s[tmp] == '\n' || \
	s[tmp] == '\v' || s[tmp] == '\r' || s[tmp] == '\t' || s[tmp] == '\f')
		tmp++;
	if (s[tmp] == '+')
		tmp++;
	else if (s[tmp] == '-')
	{
		tmp++;
		sign = 1;
	}
	while (s[tmp] >= '0' && s[tmp] <= '9')
	{
		nmb = nmb * 10 + s[tmp] - '0';
		tmp++;
	}
	if (sign == 1)
		nmb = -nmb;
	return (nmb);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
