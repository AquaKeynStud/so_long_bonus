/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:42:02 by arocca            #+#    #+#             */
/*   Updated: 2025/02/18 18:01:51 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

int close_window(void *param)
{
    (void)param;
    exit(0);
}

int handle_keypress(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307) // 65307 = touche ESC en X11 (macOS : 53)
        exit(0);
    return (0);
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx)
        return (1);
    win = mlx_new_window(mlx, 800, 600, "so_long");
    if (!win)
        return (1);
    mlx_hook(win, 17, 0, close_window, NULL);
    mlx_key_hook(win, handle_keypress, NULL);
    mlx_loop(mlx);
    return (0);
}

// Free avant d'exit !!!
