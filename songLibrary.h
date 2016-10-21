#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H
#include "songNodes.h"

song_node *table[26];

//add song
void addSong(char *newArtist, char *newName);

//search for a song
song_node* findSongLib(char *name);

//search for an artist
song_node* findArtistLib(char *artist);

//print out all the entries under a certain letter
void printLetterSongs(char letter);

//print out entire library
void printLib();

//print out all the songs of a certain artist
void printArtist(char *artist);

//shuffle - print out a series of randomly chosen songs
//void shuffle();

//delete a song
//void removeSong(char *artist, char *name);

//delete all the nodes
void clearLibrary();

#endif