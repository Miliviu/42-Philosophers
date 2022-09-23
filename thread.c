/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhagon <juhagon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:44:07 by juhagon           #+#    #+#             */
/*   Updated: 2022/09/20 15:13:06 by juhagon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void mysleep(int time)
{
    long long int time_of_request;
    long long int end_time;

    time_of_request = gettime();
    end_time = time_of_request + time;
    while (gettime() > end_time)
    {   
        usleep(200);
    }
}

long long int philo_eat(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->args->print);
    philo->time_of_last_eat = gettime();
    //printf("[%lld] %d is eating\n", gettime() - philo->born_time, philo->id);
    printf("IN         ID: %d, PTR: %p\n", philo->id, philo);
    if (philo->id == 0)
        philo->id = 99;
    pthread_mutex_unlock(&philo->args->print);
    usleep(philo->args->time_to_eat * 1000);
    return(gettime());
}

void philo_sleep(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->args->print);
    //printf("[%lld] %d is sleeping\n", gettime() - philo->born_time, philo->id);
    pthread_mutex_unlock(&philo->args->print);
    usleep(philo->args->time_to_sleep * 1000);

}

void *run_philo(void *ptr)
{   
    t_philosopher *philo;
    
    philo = ptr;
    while (philo->check_death == 0)
    {
        philo->time_of_last_eat = philo_eat(philo);
        philo_sleep(philo);
    }
    return (ptr);
}

void init_philos(t_philosopher *philos, t_args args)
{
    pthread_t   *threads;
    int         i;
    int         stop;

    stop = 0;
    threads = malloc(sizeof(pthread_t) * args.number_of_philosophers + 1);
    i = 0;
    pthread_mutex_init(&philos->args->print, 0);
    
    gettime();
    while(i < args.number_of_philosophers)
    {
        pthread_create(&threads[i], NULL, *run_philo, (void *)&philos[i]);
        printf("OUT         ID: %d, PTR: %p\n", philos[i].id, &philos[i]);

        i++;

    }
    i = 0;
    while (stop == 0)
    {   
        if (gettime() - philos[i].time_of_last_eat > args.time_to_die)
            stop = 1;
    }
    i = 0;
    while(i < args.number_of_philosophers)
    {
        pthread_join(threads[i], NULL);
    }
}


