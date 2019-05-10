/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:58:53 by tjuana            #+#    #+#             */
/*   Updated: 2019/05/10 15:25:36 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** if the last piece doesnt work, erase it outta map
*/

static int	revert_map(t_game *game, t_piece *pic, int w, int h)
{
	int i;
	int k;

	k = 0;
	w = (h > 0 ? pic->width - 1 : w);
	while (k <= h)
	{
		i = 0;
		while (i <= w)
		{
			if (game->map[pic->y + k][pic->x + i] == pic->letter)
				game->map[pic->y + k][pic->x + i] = TEMPTY;
			i++;
		}
		k++;
	}
	return (0);
}

/*
** an attempt to put the pieces on the map
*/

static int	add_to_map(t_game *gam, t_piece *pic)
{
	int i;
	int k;
	int let_go;

	k = 0;
	let_go = 0;
	if (gam->map[pic->y][pic->x] != TEMPTY && pic->map[0][0] != TEMPTY)
		return (0);
	while (let_go && k < pic->hight)
	{
		i = 0;
		while (let_go && i < pic->width)
		{
			if (gam->map[pic->y + k][pic->x + i] != TEMPTY &&\
					pic->map[i][k] != TEMPTY)
				let_go = 0;
			else if (gam->map[pic->y + k][pic->x + i] == TEMPTY)
				gam->map[pic->y + k][pic->x + i] = pic->map[k][i];
			i = (let_go) ? i + 1 : i;
		}
		k = (let_go) ? k + 1 : k;
	}
	if (let_go)
		return (1);
	return (revert_map(gam, pic, i, k));
}

static int	answer(t_game *game, t_piece *pic)
{
	if (!pic)
		return (1);
	pic->x = 0;
	pic->y = 0;
	while (pic->y + pic->hight <= game->size)
	{
		pic->x = 0;
		while (pic->x + pic->width <= game->size)
		{
			if (add_to_map(game, pic))
			{
				if (answer(game, pic->next))
					return (1);
				else
					revert_map(game, pic, pic->width - 1, pic->hight - 1);
			}
			pic->x++;
		}
		pic->y++;
	}
	return (0);
}

void		solution(t_game *game)
{
	int go;

	while (!answer(game, game->pieces))
	{
		game->size++;
		go = 0;
		while (go < game->size)
			ft_memset(game->map[go++], TEMPTY, game->size);
	}
}
