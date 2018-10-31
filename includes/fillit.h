/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:08:38 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/30 22:15:46 by dcordova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef	struct	s_piece
{
	char	**map;
	int		placed;
	int		width;
	int		height;
	int		y;
	int		x;
}				t_piece;

typedef struct	s_fillit
{
	t_piece	**list;
	int		count;
	char	**result;
	int		size;
}				t_fillit;

int				piece_stats(t_fillit *fill);
int				algs(t_fillit *fill, char **map, t_piece **list,
					int num_placed);
char			**malloc_map(char **map, int size);
void			free_map(char **map);
char			**new_map(int size);
int				reset(t_fillit *f);
int				print_map(char **map);
void			free_all(t_fillit *fill);
int				ft_perror(char *s);
#endif
