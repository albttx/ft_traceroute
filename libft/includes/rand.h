/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: world42 <world42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:59:20 by world42           #+#    #+#             */
/*   Updated: 2016/08/26 14:48:58 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAND_H
# define RAND_H

# define RAND_SIZE 			624
# define RAND_A 			397
# define MAX_RAND 			5

float	ft_frand(void);
float	ft_frrand(float a, float b);
int		*ft_getrand_array(void);
int		ft_rand(void);
int		ft_randinit(int seed);
int		ft_randint(int start, int end);
int		ft_rrand(int start, int end);

#endif
