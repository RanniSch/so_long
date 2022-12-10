/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_launch_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:28:28 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/09 08:29:13 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* initializes a window which will stay open (CTRL + C to close in terminal).
Done by mlx_new_window function, which will return a pointer to the window we
have created. We can give the window height, width and a title. 
We then will have to call mlx_loop to initiate the window rendering.
int main(void)
{
    void    *mlx;
    //void    *mlx_win;

    mlx = mlx_init();
    mlx_new_window(mlx, 800, 600, "Hello World!");
    mlx_loop(mlx);
}*/
