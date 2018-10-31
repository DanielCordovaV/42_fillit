/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:33:54 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/30 20:01:39 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		valid_spot(char **map, int i, int j, t_piece *piece)
{
	int		n;
	int		m;
	int		size;

	size = ft_strlen(*map);
	if (j + piece->width > size || i + piece->height > size)
		return (0);
	n = -1;
	while (++n < piece->height)
	{
		m = -1;
		while (++m < piece->width)
		{
			if (map[i + n][j + m] != '.' &&
					piece->map[piece->y + n][piece->x + m] != '.')
				return (0);
		}
	}
	return (1);
}

void	update_map(char ***map, t_piece *piece, int size, int x)
{
	int		i;
	int		j;
	int		y;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (valid_spot(*map, i, j, piece) == 1)
			{
				y = -1;
				while (++y < piece->height)
				{
					x = -1;
					while (++x < piece->width)
						if (piece->map[y + piece->y][x + piece->x] != '.')
							(*map)[i + y][j + x] =
								piece->map[y + piece->y][x + piece->x];
				}
				i = size + 1;
			}
		}
	}
}

void	remove_piece(char ***map, int *placed, int num_placed, t_fillit *f)
{
	int i;
	int j;

	i = -1;
	while (++i < f->size)
	{
		j = -1;
		while (++j < f->size)
		{
			if ((*map)[i][j] == 'A' + num_placed)
				(*map)[i][j] = '.';
		}
	}
	*placed = 0;
}

int		algs(t_fillit *f, char **map, t_piece **list, int num_placed)
{
	int		p;
	int		i;
	int		j;

	p = -1;
	if (num_placed == f->count)
		return (print_map(map));
	while (++p < f->count)
	{
		i = -1;
		while (list[p]->placed == 0 && ++i < f->size)
		{
			j = -1;
			while (++j < f->size)
				if (valid_spot(map, i, j, list[p]) == 1)
				{
					list[p]->placed = 1;
					update_map(&map, list[p], f->size, 0);
					if (algs(f, map, list, num_placed + 1) == 1)
						return (1);
					remove_piece(&map, &(list[p]->placed), num_placed, f);
				}
		}
	}
	return (0);
}
