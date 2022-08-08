/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 08:07:19 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/06/10 10:30:25 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoi_continued(const char *s, int sign, int i)
{
	long	res;

	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
		if ((res > 922337203685477580 || (res == 922337203685477580
					&& (s[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
					&& (s[i] - '0') > 8)) && sign == -1)
			return (0);
	}
	return (res * sign);
}

int	ft_atoi(const char *s)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (ft_atoi_continued(s, sign, i));
}
