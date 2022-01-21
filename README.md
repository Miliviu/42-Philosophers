# 42-Philosophers English
1. Global variables are forbidden!
2. The program should take the following arguments: number_of_philosophers time_to_die
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
3. Each philosopher should be given a number from 1 to ’number_of_philosophers’.
4. Philosopher number 1 is next to philosopher number ’number_of_philosophers’.
Any other philosopher with the number N is seated between philosopher N - 1 and
philosopher N + 1.
5. Any change of status of a philosopher must be written as follows (with X replaced
with the philosopher number and timestamp_in_ms the current timestamp in milliseconds):

      ◦ timestamp_in_ms X has taken a fork

      ◦ timestamp_in_ms X is eating

      ◦ timestamp_in_ms X is sleeping

      ◦ timestamp_in_ms X is thinking

      ◦ timestamp_in_ms X died
6. The status printed should not be scrambled or intertwined with another philosopher’s status.
7. You can’t have more than 10 ms between the death of a philosopher and when it
will print its death.
8. Again, philosophers should avoid dying!
