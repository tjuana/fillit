/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:53:38 by tjuana            #+#    #+#             */
/*   Updated: 2019/05/11 13:11:25 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_coord		get_coordinate(char *buff)
{
	t_coord	coord;
	int		i;

	coord.t = 3;
	coord.r = 0;
	coord.b = 0;
	coord.l = 3;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == TBLOCK)
		{
			if (i / 5 < coord.t)
				coord.t = i / 5;
			if (i / 5 > coord.b)
				coord.b = i / 5;
			if (i % 5 > coord.r)
				coord.r = i % 5;
			if (i % 5 < coord.l)
				coord.l = i % 5;
		}
		i++;
	}
	return (coord);
}

static t_piece		*init_piece(char *buff)
{
	t_piece		*newp;
	t_coord		pts;
	int			i;
	static char	c = 'A';

	if (!(newp = ft_memalloc(sizeof(t_piece))))
		print_error(2);
	newp->x = 0;
	newp->y = 0;
	newp->letter = c++;
	pts = get_coordinate(buff);
	newp->width = pts.r - pts.l + 1;
	newp->hight = pts.b - pts.t + 1;
	if (!(newp->map = (char **)malloc(newp->hight * sizeof(char *))))
		print_error(2);
	i = 0;
	while (i < newp->hight)
	{
		newp->map[i] = buff_piece(buff, ((pts.t + i) * 5 + pts.l), newp->width, newp->letter);
		i++;
	}
	return (newp);
}

void				piece_to_back(t_game *game, t_piece *piece)
{
	t_piece	*list;

	list = game->pieces;
	while (!list)
	{
		game->pieces = piece;
		game->nb_pieces++;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = piece;
	game->nb_pieces++;

}
void				store(t_game *game, char *buff)
{
	t_piece *next;

	next = init_piece(buff);
	piece_to_back(game, next);
}
