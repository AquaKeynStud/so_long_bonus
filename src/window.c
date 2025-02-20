#include "mlx.h"
#include <stdlib.h>

// Fonction pour fermer proprement la fenêtre et libérer MLX
int close_window(void *param)
{
    void **data = (void **)param;
    void *mlx = data[0];
    void *win = data[1];

    if (win)
        mlx_destroy_window(mlx, win);
    if (mlx)
    {
        mlx_destroy_display(mlx); // Uniquement sous Linux
        free(mlx);
    }
    exit(0);
}

// Gestion des touches (ESC pour fermer)
int handle_keypress(int keycode, void *param)
{
    if (keycode == 65307) // ESC (Mac = 53)
        close_window(param);
    return (0);
}

int main(void)
{
    void *mlx;
    void *win;
    void *param[2];

    mlx = mlx_init();
    if (!mlx)
        return (1);

    win = mlx_new_window(mlx, 800, 600, "so_long");
    if (!win)
    {
        free(mlx);
        return (1);
    }

    param[0] = mlx;
    param[1] = win;

    // Fermer avec la croix
    mlx_hook(win, 17, 0, close_window, param);
    // Fermer avec ESC
    mlx_key_hook(win, handle_keypress, param);

    mlx_loop(mlx);
    return (0);
}
