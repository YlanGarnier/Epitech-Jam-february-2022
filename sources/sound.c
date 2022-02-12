/*
** EPITECH PROJECT, 2021
** sounds
** File description:
** contains all functions linked to sound
*/

#include "game.h"


void music(sound_td *s)
{
    s->musique = sfMusic_createFromFile("assets/music1.ogg");
    sfMusic_setLoop(s->musique, sfTrue);
    sfMusic_play(s->musique);
}

void init_sound(sound_td *s)
{
    s->sound_buff = sfSoundBuffer_createFromFile("assets/son.ogg");
    s->sound = sfSound_create();
    sfSound_setBuffer(s->sound, s->sound_buff);
    return;
}

void destroy_sounds(sound_td *sound)
{
    sfMusic_destroy(sound->musique);
    //sfSound_destroy(sound->leson);
    //sfSoundBuffer_destroy(sound->lebuffer_duson);
    return;
}

sound_td *all_sounds(void)
{
    sound_td *sound = malloc(sizeof(sound_td));

    return (sound);
}
