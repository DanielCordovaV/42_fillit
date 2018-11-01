/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:43:46 by dcordova          #+#    #+#             */
/*   Updated: 2018/10/31 22:43:53 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	ft_getwidth(t_piece *piece, int y, int x)
{
	x = -1;
	while (++x < 4)
	{
		y = 0;
		while (y < 4 && piece->map[y][x] == '.')
			y++;
		if (y < 4)
		{
			piece->x = x;
			break ;
		}
	}
	x = 4;
	while (--x >= piece->x)
	{
		y = 0;
		while (y < 4 && piece->map[y][x] == '.')
			y++;
		if (y < 4)
		{
			piece->width = x - piece->x + 1;
			break ;
		}
	}
}

static void	ft_getheight(t_piece *piece, int y, int x)
{
	y = -1;
	while (++y < 4)
	{
		x = 0;
		while (x < 4 && piece->map[y][x] == '.')
			x++;
		if (x < 4)
		{
			piece->y = y;
			break ;
		}
	}
	y = 4;
	while (--y >= piece->y)
	{
		x = 0;
		while (x < 4 && piece->map[y][x] == '.')
			x++;
		if (x < 4)
		{
			piece->height = y - piece->y + 1;
			break ;
		}
	}
}

int			piece_stats(t_fillit *fill)
{
	int i;

	i = -1;
	while (++i < fill->count)
	{
		ft_getwidth(fill->list[i], 0, 0);
		ft_getheight(fill->list[i], 0, 0);
	}
	return (0);
}

int			get_size(int count)
{
	int i;

	count *= 4;
	i = 1;
	while (++i)
	{
		if (count >= 32 && i * i == count)
			return (i + 1);
		if (i * i >= count)
			return (i);
	}
	return (0);
}

int			valid_piece(t_piece *piece, int i, int j)
{
	int count;
	int curr;

	count = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (piece->map[i][j] != '.')
			{
				curr = 0;
				if (i != 0 && piece->map[i - 1][j] != '.')
					curr++;
				if (i != 3 && piece->map[i + 1][j] != '.')
					curr++;
				if (j != 0 && piece->map[i][j - 1] != '.')
					curr++;
				if (j != 3 && piece->map[i][j + 1] != '.')
					curr++;
				count += curr > 1 ? 1 : 0;
			}
		}
	}
	return (count > 0 ? 1 : -1);
}
