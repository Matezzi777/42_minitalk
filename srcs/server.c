#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		printf("Aucun argument passé...\n");
	else
	{
		printf("Arguments passés :\n");
		i = 0;
		while (++i < argc)
			printf("	- %s\n", argv[i]);
	}
}