#include "../incl/push_swap.h"

//checker s'il y a des doublons
int	doublons(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//checker s'il y a des lettres
int	alpha(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//checker si chaque av est ds la limite du long
int	avlen(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) < -2147483648)
			return (1);
		else if (ft_atoi(av[i]) > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

//parsing
int	parsing(char **av)
{
	if (doublons(av))
		return (1);
	if (alpha(av))
		return (1);
	if (avlen(av))
		return (1);
	return (0);
}
