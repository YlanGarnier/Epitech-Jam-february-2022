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

void get_count(sfText *text, int count)
{
    char *str_count = malloc(sizeof(char) * 6);

    str_count[5] = '\0';
    sprintf(str_count, "Count: %d", count);
    sfText_setString(text, str_count);
    free(str_count);
}

window_td *set_window(void)
{
    window_td *window = malloc(sizeof(window_td));

    window->state = 1;
    window->count = 0;
    window->count_text = sfText_create();
    window->count_font = sfFont_createFromFile("fonts/bubblegum.ttf");
    sfText_setFont(window->count_text, window->count_font);
    sfText_setCharacterSize(window->count_text, 100);
    sfText_setFillColor(window->count_text, sfColor_fromRGB(0, 204, 0));
    get_count(window->count_text, window->count);
    return window;
}
