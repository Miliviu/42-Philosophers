/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:40:32 by juhagon           #+#    #+#             */
/*   Updated: 2022/01/24 14:27:48 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

t_args	parse_data(char **argv, int argc)
{
	t_args	args;

	args.number_of_philosophers = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		args.number_of_times_each_philosopher_must_eat = 0;
	return (args);
}

int	main(int argc, char **argv)
{
	t_args	args;
	if (argc == 5 || argc == 6)
	{
		if (check_args(argv) == 0)
		{
			printf("Error\n");
			return (0);
		}
		args = parse_data(argv, argc);
	}
	else
	{
		printf("Error\n");
		return (0);
	}
}
