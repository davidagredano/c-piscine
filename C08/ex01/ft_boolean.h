/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:54:24 by dagredan          #+#    #+#             */
/*   Updated: 2024/11/25 12:40:46 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>
# define EVEN(N) (N % 2 == 0)
# define EVEN_MSG "I have an even number of arguments.\n" 
# define ODD_MSG "I have an odd number of arguments.\n" 
# define SUCCESS 0

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

#endif
