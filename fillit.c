/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:09:46 by tjuana            #+#    #+#             */
/*   Updated: 2019/05/11 17:00:23 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (i < 4 * game->nb_pieces)
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
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
