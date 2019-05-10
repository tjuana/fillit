/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:21:31 by tjuana            #+#    #+#             */
/*   Updated: 2019/05/10 15:23:14 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check da fucking CHAR if its a GOOD ONE or NOT! BROW
*/

static int		is_val_char(int c, int i)
{
	if (c == TEMPTY || c == TBLOCK || \
	((c == '\n') && ((i % 5 == 4) || (i == 20))))
		return (1);
	return (0);
}
/*
** check da neighboorhood to know if its a valid tetriminos BRO'
*/

static int		ch_nighbour(char *buff, int i)
{
	int r;

	r = 0;
	if (i == 19)
		return (0);
	if (buff[i] == TBLOCK)
	{
		if (i > 0 && buff[i - 1] == TBLOCK)
			r++;
		if (i < 19 && buff[i + 1] == TBLOCK)
			r++;
		if (i >= 5 && buff[i - 5] == TBLOCK)
			r++;
		if (i <= 14 && buff[i + 5] == TBLOCK)
			r++;
	}
	return (r + ch_nighbour(buff, ++i));
}

static int		ch_block(char *buff)
{
	int i;
	int	nb;
	int	first;
	int	r;

	i = 0;
	nb = 0;
	while (buff[i] && is_val_char(buff[i], i) && nb <= 4)
	{
		if (buff[i] == TBLOCK)
		{
			nb++;
			if (nb == 1)
				first = i;
		}
		i++;
	}
	if (i >= 20 && !buff[i] && nb == 4 && \
	(r = ch_nighbour(buff, first)) && (r == 6 || r == 8))
		return (1);
	else
		print_error(2);
	return (0);
}

int				check_file(t_game *game, char *file)
{
	int		fd;
	int		r;
	int		lastr;
	char	buff[22];

	r = 0;
	lastr = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error(2);
	while ((r = read(fd, buff, 21)) > 0)
	{
		lastr = r;
		buff[r] = '\0';
		if (r >= 20 && ch_block(buff))
			store(game, buff);
		else
			print_error(2);
	}
	if (r <= 0 && (lastr == 21 || !lastr))
		print_error(2);
	return (1);
}
