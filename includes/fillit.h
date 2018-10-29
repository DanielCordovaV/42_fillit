/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:08:38 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/28 20:50:54 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef	struct		s_piece
{
	char	**map;
	int		placed;
}					t_piece;

typedef struct		s_fillit
{
	t_piece	**list;
	int		count;
	char	**result;
	int		size;
}					t_fillit;
#endif
