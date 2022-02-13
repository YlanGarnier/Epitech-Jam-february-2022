/*
** EPITECH PROJECT, 2021
** sounds
** File description:
** contains all functions linked to sound
*/

#include "game.h"

void destroy_sounds(sound_td *sound)
{
    sfMusic_destroy(sound->music1);
    sfSound_destroy(sound->click0);
    sfSoundBuffer_destroy(sound->click0_buf);
    return;
}

sound_td *all_sounds(void)
{
    sound_td *sound = malloc(sizeof(sound_td));

    sound->click_played = 0;
    sound->music1 = sfMusic_createFromFile("assets/music2.ogg");
    sfMusic_setLoop(sound->music1, sfTrue);
    sound->click0 = sfSound_create();
    sound->click0_buf = sfSoundBuffer_createFromFile("assets/click0.ogg");
    sfSound_setBuffer(sound->click0, sound->click0_buf);
    return (sound);
}
