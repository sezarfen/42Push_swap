#include "push_swap.h"

/* 
• In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.
*/


// FIND SOLUTION FOR DUPLICATES

int check_max_int(int ac, char **av)
{  // long çevirmesi yapılıp bakılabilir, (long ft_atoi)
	int		i;
	long	num;

	i = 1;
	num = 0;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (-1);
		i++;
	}
	return (1);
}

int check_single_arg(char **av)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(av[1], ' ');
	i = 0;
	j = 0;
	while (split[i])
	{
		while (split[i][j])
		{
			if (!(split[i][j] <= '9' && split[i][j] >= '0'))
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int av_checker(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	if (ac == 2)
		return (check_single_arg(av));
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!(av[i][j] <= '9' && av[i][j] >= '0'))
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (check_max_int(ac, av));
}