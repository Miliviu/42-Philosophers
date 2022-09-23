/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:42:21 by juhagon           #+#    #+#             */
/*   Updated: 2022/09/20 14:13:07 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	one_death;
	pthread_mutex_t print;
}	t_args;

typedef struct s_philosopher
{
	t_args			*args;
	int				id;
	long long int	born_time;
	int				check_meal;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	long long int	time_of_last_eat;
	int				check_death;
	
}	t_philosopher;

long long int	ft_atoi(const char *s);
int				ft_isdigit(int c);
int				ft_strlen(char *s);
void			init_philos(t_philosopher *philos, t_args args);
long long int	gettime();
#endif
