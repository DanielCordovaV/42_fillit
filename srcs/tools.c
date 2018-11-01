/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:55:56 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/31 22:56:46 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

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
