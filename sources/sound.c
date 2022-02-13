/*
** EPITECH PROJECT, 2021
** sounds
** File description:
** contains all functions linked to sound
*/

#include "game.h"

static void init_sound(sound_td *s)
{
    s->music = sfMusic_createFromFile("assets/music2.ogg");
    sfMusic_setLoop(s->music, sfTrue);
    sfMusic_setVolume(s->music, 10.f);
    sfMusic_play(s->music);
    s->tab_sound[0].sound_buff = sfSoundBuffer_createFromFile("assets/click0.ogg");
    s->tab_sound[1].sound_buff = sfSoundBuffer_createFromFile("assets/sound1.ogg");
    s->tab_sound[2].sound_buff = sfSoundBuffer_createFromFile("assets/sound2.ogg");
    s->tab_sound[3].sound_buff = sfSoundBuffer_createFromFile("assets/sound3.ogg");
    for (int i = 0; i != 4; i++) {
        s->tab_sound[i].sound = sfSound_create();
        sfSound_setBuffer(s->tab_sound[i].sound, s->tab_sound[i].sound_buff);
    }
    return;
}

void destroy_sounds(sound_td *sound)
{
    sfMusic_destroy(sound->music);
    for (int i = 0; i != 4; i++) {
        sfSound_destroy(sound->tab_sound[i].sound);
        sfSoundBuffer_destroy(sound->tab_sound[i].sound_buff);
    }
    return;
}

sound_td *all_sounds(void)
{
    sound_td *sound = malloc(sizeof(sound_td));
    init_sound(sound);
    return (sound);
}
