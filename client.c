/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 03:23:49 by ykoseki           #+#    #+#             */
/*   Updated: 2024/03/06 22:43:32 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send_char(const pid_t pid, char c)
{
	int	digit;

	digit = 7;
	while (digit >= 0)
	{
		if (c & (1 << digit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		digit--;
		usleep(500);
	}
}

void	ft_error_handler(void)
{
	ft_printf("%s", "Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (!ft_isdigit(argv[1][i]))
				ft_error_handler();
			i++;
		}
		pid = ft_atoi(argv[1]);
		i = 0;
		if (pid < 100 || pid > 99998)
			ft_error_handler();
		while (argv[2][i] != '\0')
		{
			send_char(pid, argv[2][i]);
			i++;
		}
	}
	else
		ft_error_handler();
	return (0);
}
