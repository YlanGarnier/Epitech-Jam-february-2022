/*
** EPITECH PROJECT, 2021
** sounds
** File description:
** contains all functions linked to sound
*/

#include <string.h>
#include "game.h"

void destroy_sounds(sound_td *sound)
{
    sfMusic_destroy(sound->music);
    sfSound_destroy(sound->click);
    sfSoundBuffer_destroy(sound->click_buf);
    sfSound_destroy(sound->yeah);
    sfSoundBuffer_destroy(sound->yeah_buf);
    return;
}

sound_td *all_sounds(void)
{
    sound_td *sound = malloc(sizeof(sound_td));

    sound->music = sfMusic_createFromFile("assets/music1.ogg");
    sfMusic_setLoop(sound->music, sfTrue);
    sfMusic_setVolume(sound->music, 25.f);
    sfMusic_play(sound->music);
    sound->click_played = 0;
    sound->click_path = strdup("assets/click0.ogg");
    sound->click = sfSound_create();
    sound->click_buf = sfSoundBuffer_createFromFile(sound->click_path);
    sfSound_setBuffer(sound->click, sound->click_buf);
    sound->yeah = sfSound_create();
    sound->yeah_buf = sfSoundBuffer_createFromFile("assets/yeah.ogg");
    sfSound_setBuffer(sound->yeah, sound->yeah_buf);
    return sound;
}
