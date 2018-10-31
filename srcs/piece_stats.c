/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:43:46 by dcordova          #+#    #+#             */
/*   Updated: 2018/10/30 21:42:09 by dcordova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	ft_getx(t_piece *piece)
{
	int	x;
	int	y;

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
}

static void	ft_getwidth(t_piece *piece)
{
	int	y;
	int	x;

	x = 4;
	ft_getx(piece);
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

static void	ft_gety(t_piece *piece)
{
	int	x;
	int	y;

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
}

static void	ft_getheight(t_piece *piece)
{
	int	y;
	int	x;

	ft_gety(piece);
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
		ft_getwidth(fill->list[i]);
		ft_getheight(fill->list[i]);
	}
	return (0);
}
