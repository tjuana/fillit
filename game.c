/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:33:19 by tjuana            #+#    #+#             */
/*   Updated: 2019/05/11 13:06:01 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*buff_piece(const char *s, unsigned int start, size_t len, char l)
{
	char			*res;
	unsigned int	ind;

	if (!s)
		return (NULL);
	if (!(res = ft_strnew(len)))
		return (NULL);
	ind = 0;
	while (ind < len)
	{
		if (s[start + ind] == TBLOCK)
			res[ind] = l;
		else
			res[ind] = s[start + ind];
		ind++;
	}
	return (res);
}

static int		ft_sqrt(int n)
{
	int s;

	s = 1;
	while (s * s < n)
		s++;
	return (s);
}

static int		map(t_game *game, int size)
{
	int	i;

	if (!(game->map = (char **)malloc(size * sizeof(char *))))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(game->map[i] = (char *)malloc(size * sizeof(char))))
			return (0);
		ft_memset(game->map[i++], TEMPTY, size);
	}
	return (1);
}

int				game_in(t_game *game, char *file)
{
	game->pieces = NULL;
	game->nb_pieces = 0;
	game->map = NULL;
	if (check_file(game, file))
	{
		map(game, 4 * game->nb_pieces);
		game->size = 2 * ft_sqrt(game->nb_pieces) - 1;
		return (1);
	}
	return (0);
}
