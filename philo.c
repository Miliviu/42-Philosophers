/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:40:32 by juhagon           #+#    #+#             */
/*   Updated: 2022/09/20 14:56:14 by juhagon          ###   ########.fr       */
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
	args.one_death = 0;
	if (argc == 6)
		args.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		args.number_of_times_each_philosopher_must_eat = 0;
	return (args);
}

t_philosopher	*create_philos(t_args args, t_philosopher *philos)
{
	int				i;
	long long int	born_time;

	born_time = gettime();
	philos = malloc(sizeof(t_philosopher) * args.number_of_philosophers);
	i = 0;
	while (i < args.number_of_philosophers)
	{
		philos[i].id = i;
		philos[i].born_time = born_time;
		philos[i].args = &args;
		philos[i].time_of_last_eat = gettime();
		philos[i].check_death = 0;
		i++;
	}
	init_philos(philos, args);

	return (philos);
}

int	main(int argc, char **argv)
{
	t_philosopher	*philos;
	t_args			args;
	int				i;

	i = 0;
	philos = NULL;
	if (check_args(argv) == 0)
		return (1);
	if (argc != 5 && argc != 6)
		return (1);
	args = parse_data(argv, argc);
	create_philos(args, philos);
}
