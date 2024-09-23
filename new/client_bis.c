#include "../minitalk.h"

/*Check if there are some errors in the arguments passed.
	Arguments :
	-> int	nb_args : basically argc in the main.
	-> char	**arguments : basically argv in the main.
	Returns :
	-> 1 : If an error is detected.
		-> Wrong nb of arguments.
		-> PID not only composed of digits.
		-> PID <= 0.
	-> 0 : If the arguments are corrects.
*/
static int	arg_error(int nb_args, char **arguments)
{
	int	i;

	if (nb_args != 3)
	{
		ft_printf("Error.\nInvalid number of arguments.\n");
		return (1);
	}
	i = -1;
	while (arguments[1][++i])
	{
		if (!ft_isdigit(arguments[1][i]))
		{
			ft_printf("Error.\nInvalid characters found in PID.\n");
			return (1);
		}
	}
	if (ft_atoi(arguments[1]) <= 0)
	{
		ft_printf("Error.\nPID can't be null or negative.\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (arg_error(argc, argv))
		return (-1);
	ft_printf("Must send :\n%s\nto %d.\n", argv[2], ft_atoi(argv[1]));
}
