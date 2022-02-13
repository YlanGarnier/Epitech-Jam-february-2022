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

void check_level(window_td *window, sprite_td *sprite,
clock_td *clock, sound_td *sound)
{
    if (window->lvl < 5 && window->textures_updated == 0 && window->count % (100 * window->multiplier) == 0) {
        window->lvl++;
        window->multiplier *= 5;
        update_textures(window, sprite, sound);
        window->textures_updated = 1;
        sfSound_play(sound->whoosh);
    }
    else if (window->count % (100 * window->multiplier) != 0)
        window->textures_updated = 0;
    if (window->lvl == 5) {
        sfSound_play(sound->yeah);
        sfSound_play(sound->gorilla);
        sfText_setCharacterSize(window->count_text, 200);
        sfText_setString(window->count_text, "SUCCESS IS YOURS!");
        sfText_setFillColor(window->count_text, sfRed);
        sfText_setPosition(window->count_text, get_offset(300, 25));
        window->lvl++;
    }
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
    check_level(window, sprite, clock, sound);
    analyse_events(window, sprite, clock, sound);
    success_clicker(window, sprite, clock, sound);
    display(window, sprite);
}

int main(int ac, char **av)
{
    window_td *window = set_window();
    sprite_td *sprite = all_sprites();
    clock_td *clock = all_clocks();
    sound_td *sound = all_sounds();

    if (ac > 1 && (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0)) {
        destroy_all(window, sprite, clock, sound);
        return usage();
    }
    window->window = create_window("Success Clicker", window->event);
    window->state = 3;
    sfMusic_play(sound->music);
    while (sfRenderWindow_isOpen(window->window))
        game(window, sprite, clock, sound);
    destroy_all(window, sprite, clock, sound);
    return 0;
}
