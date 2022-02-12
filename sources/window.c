/*
** EPITECH PROJECT, 2021
** create_window
** File description:
** create a window ready to be displayed and titled by given string
*/

#include "game.h"

sfRenderWindow *create_window(char *title, sfEvent event)
{
    sfVideoMode res = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(res, title, sfDefaultStyle,
NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

window_td *set_window(void)
{
    window_td *window = malloc(sizeof(window_td));

    window->state = 1;
    return window;
}
