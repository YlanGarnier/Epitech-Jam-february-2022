/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter game
*/

#include <unistd.h>
#include <string.h>
#include "game.h"

void destroy_all(window_td *window, sprite_td *sprite,
clock_td *clock, sound_td *sound)
{
    if (window->state == 3) {
        free(clock);
    }
    if (window->state != 0)
        free(window);
    free(sprite);
    destroy_sounds(sound);
}

int main(int ac, char **av)
{
    window_td *window = set_window();
    sprite_td *sprite = all_sprites();
    clock_td *clock;
    sound_td *sound = all_sounds();

    if (ac > 1 && strcmp(av[1], "-h") == 0 && strcmp(av[1], "--help") == 0) {
        destroy_all(window, sprite, clock, sound);
        return usage();
    }
    return 0;
}
