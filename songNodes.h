#ifndef SONG_NODES_H
#define SONG_NODES_H

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

//print a song node
void print_node(song_node *node);

//print entire list
void print_list(song_node *node);

//insert nodes at front
song_node* insert_front(song_node *node, char *newArtist, char *newName);

int list_len(song_node *node);
void clear_list(song_node *node);

//insert nodes in order
song_node* insert_ordered(song_node *node, char *newArtist, char *newName);
song_node* insert(song_node *node, char *newArtist, char *newName);

//find and return a pointer to an individual song based on song name
song_node* find_song(song_node *node, char *name);

//find and return a pointer to the first song of an artist based on artist name
song_node* find_artist_song(song_node *node, char *artist);

//Return a pointer to random element in the list
song_node* random_pointer(song_node *node);

//remove a single node from the list
//void remove_node( song_node *n, song_node *removing );

//free entire list
song_node* free_list(song_node *node);

#endif