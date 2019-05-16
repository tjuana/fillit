/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:23:29 by tjuana            #+#    #+#             */
/*   Updated: 2019/05/15 14:08:51 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define TBLOCK '#'
# define TEMPTY '.'

# define ERROR1 "usage: ./fillit source_file\n"
# define ERROR2 "error\n"

typedef struct	s_coord
{
	int t;
	int r;
	int b;
	int l;
}				t_coord;

typedef struct	s_piece
{
	int				x;
	int				y;
	int				width;
	int				hight;
	char			**map;
	char			letter;
	struct s_piece	*next;
}				t_piece;

typedef struct	s_game
{
	t_piece		*pieces;
	int			nb_pieces;
	int			size;
	char		**map;
}				t_game;

int				check_file(t_game *game, char *file);
void			print_error(int c);
void			store(t_game *game, char *buff);
char			*buff_piece(const char *s, unsigned int start, size_t len, \
							char l);
int				game_in(t_game *game, char *file);
void			piece_to_back(t_game *game, t_piece *piece);
void			put_the_map(t_game *game);
void			solution(t_game *game);

#endif
