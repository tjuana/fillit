/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:09:46 by tjuana            #+#    #+#             */
/*   Updated: 2019/05/15 15:38:57 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_map(t_game *game)
{
	int		i;
	t_piece	*arr;

	i = 0;
	if (game->map)
	{
		while (i < 4 * game->nb_pieces)
			ft_memdel((void **)&(game->map[i++]));
		ft_memdel((void **)&(game->map));
	}
	while (!(game->pieces == NULL))
	{
		i = 0;
		arr = game->pieces->next;
		while (i < game->pieces->hight)
			ft_memdel((void **)&(game->pieces->map[i++]));
		ft_memdel((void **)&(game->pieces->map));
		ft_memdel((void **)&(game->pieces));
		game->pieces = arr;
	}
	ft_memdel((void **)&(game->pieces));
}

/*
** print the valid map
*/

void			put_the_map(t_game *game)
{
	int i;
	int k;

	k = 0;
	while (k < game->size)
	{
		i = 0;
		while (i < game->size)
			ft_putchar(game->map[k][i++]);
		ft_putchar('\n');
		k++;
	}
}

int				main(int c, char **v)
{
	t_game game;

	if (c != 2)
	{
		print_error(1);
		return (0);
	}
	if (game_in(&game, v[1]))
	{
		solution(&game);
		put_the_map(&game);
		free_map(&game);
	}
	else
		print_error(2);
	return (1);
}
