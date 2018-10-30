/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:08:38 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/29 21:44:37 by dcordova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef	struct		s_piece
{
	char	**map;
	int		placed;
	int		width;
	int		height;
	int		y;
	int		x;
}					t_piece;

typedef struct		s_fillit
{
	t_piece	**list;
	int		count;
	char	**result;
	int		size;
}					t_fillit;

int					piece_stats(t_fillit *fill);
#endif
