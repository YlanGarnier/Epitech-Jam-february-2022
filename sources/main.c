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
    if (window->state == 3)
        free(window);
    free(clock);
    free(sprite);
    destroy_sounds(sound);
}

void success_clicker(window_td *window, sprite_td *sprite,
clock_td *clock, sound_td *sound)
{
    if (window->state == 3) {
        set_time(clock);
        analyse_clocks(window, sprite, clock, sound);
    }
    return;
}

void game(window_td *window, sprite_td *sprite, clock_td *clock,
sound_td *sound)
{
    analyse_events(window, sprite, clock, sound);
    success_clicker(window, sprite, clock, sound);
    display(window, sprite);
}

int main(int ac, char **av)
{
    window_td *window = set_window();
    sprite_td *sprite = all_sprites();
    clock_td *clock = all_clocks();;
    sound_td *sound = all_sounds();
    //music(sound);
    //init_sound(sound);
    //sfSound_play(sound->sound);
    if (ac > 1 && (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0)) {
        destroy_all(window, sprite, clock, sound);
        return usage();
    }
    window->window = create_window("Success Clicker", window->event);
    window->state = 3;
    while (sfRenderWindow_isOpen(window->window))
        game(window, sprite, clock, sound);
    destroy_all(window, sprite, clock, sound);
    return 0;
}
