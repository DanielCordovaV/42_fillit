/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:33:54 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/31 22:40:39 by jdiaz            ###   ########.fr       */
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

void	update_map(char ***map, t_piece *piece, int y_off, int x_off)
{
	int		i;
	int		j;

	i = -1;
	while (++i < piece->height)
	{
		j = -1;
		while (++j < piece->width)
		{
			if (piece->map[i + piece->y][j + piece->x] != '.')
				(*map)[i + y_off][j + x_off] =
					piece->map[i + piece->y][j + piece->x];
		}
	}
}

void	remove_piece(char ***map, int *placed, char remove, t_fillit *f)
{
	int i;
	int j;

	i = -1;
	while (++i < f->size)
	{
		j = -1;
		while (++j < f->size)
		{
			if ((*map)[i][j] == remove)
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
					update_map(&map, list[p], i, j);
					if (algs(f, map, list, num_placed + 1) == 1)
						return (1);
					remove_piece(&map, &(list[p]->placed), 'A' + p, f);
				}
		}
	}
	return (0);
}
