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
    sprintf(str_count, "%d$", count);
    sfText_setString(text, str_count);
    free(str_count);
}

window_td *set_window(void)
{
    window_td *window = malloc(sizeof(window_td));

    window->state = 1;
    window->count = 0;
    window->textures_updated = 1;
    window->lvl = 0;
    window->multiplier = 2;
    window->count_text = sfText_create();
    window->count_font = sfFont_createFromFile("fonts/badaboom.ttf");
    sfText_setFont(window->count_text, window->count_font);
    sfText_setCharacterSize(window->count_text, 100);
    sfText_setFillColor(window->count_text, sfColor_fromRGB(0, 204, 0));
    get_count(window->count_text, window->count);
    sfText_setPosition(window->count_text, get_offset(15, 0));
    sfText_setOutlineThickness(window->count_text, 3);
    window->quote_text = sfText_create();
    window->quote_font = sfFont_createFromFile("fonts/badaboom.ttf");
    sfText_setFont(window->quote_text, window->quote_font);
    sfText_setCharacterSize(window->quote_text, 70);
    sfText_setFillColor(window->quote_text, sfBlue);
    sfText_setPosition(window->quote_text, get_offset(200, 250));
    sfText_setOutlineThickness(window->count_text, 3);
    sfText_setString(window->quote_text, "I could either watch it happen or be a part of it. - Elon Musk");
    return window;
}
