#include "push_swap.h"

//nodoublons
//noalpha
//nottoolong
//parsing

int	nodoublons(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (atoi(av[i]) == atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	noalpha(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//marche pas!!!
//int	nottoolong(char **av)
//{
//	int i;

//	i = 1;
//	while (av[i])
//	{
//		if (ft_long_atoi(av[i]) < -2147483648)
//			return (0);
//		else if (ft_long_atoi(av[i]) > 2147483647)
//			return (0);
//		i++;
//	}
//	return (1);
//}

//retourne 1 si toutes les conditions propices sont reunies
int	parsing(char **av)
{
	if (nodoublons(av) && noalpha(av))
		return 1;
	return 0;
}
