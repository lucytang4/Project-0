#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songLibrary.h"

void addSong(char *newArtist, char *newName) {
  table[tolower(newArtist[0]) - 98] = insert(table[tolower(newArtist[0]) - 98], newArtist, newName);
}

song_node* findSongLib(char *name){
  int ctr = 0;
  song_node *ret = 0;
  while(!ret && ctr < 26) {
    ret = find_song(table[ctr], name);
    ctr++;
  }
  print_list(ret);
  return ret;
}

song_node* findArtistLib(char *artist){
  song_node *ret = table[tolower(artist[0]) - 98];
  ret = find_artist_song(ret, artist);
  print_node(ret);
  return ret;
}

void printLetterSongs(char letter){
  print_list(table[tolower(letter)-98]);
}

void printLib(){
  printf("\nLIBRARY:\n");
  int ctr = 0;
  while (ctr < 26) {
    print_list(table[ctr]);
    ctr++;
  }
}

void printArtist(char *artist){
  printf("%s list:\n", artist);
  song_node *letter = find_artist_song(table[tolower(artist[0])-98], artist);
  while(letter && strcmp(artist, letter->artist) == 0) {
    if(strcmp(letter->artist, artist) == 0)
      printf("%s\n", letter->name, letter->artist);
    letter = letter->next;
  }
  printf("\n");
}

/*
void removeSong(char *artist, char *name){
  table[tolower(artist[0])-98] = remove_node(find_song(table[tolower(artist[0])-98], name));
  printLib();
}
*/

void clearLibrary() {
  int ctr = 0;
  while(ctr < 26) {
    if (table[ctr] != NULL) {
      table[ctr] = free_list(table[ctr]);
    }
    ctr++;
  }
}

/*
void shuffle(){
  printf("Shuffled:\n");
  song_node *temp = 0;
  int ctr = 0;
  while(ctr < 26) {
    song_node *a = table[ctr];
    while (a != 0) {
      temp = insert_front(temp, a->artist, a->name);
      a = a->next;
    }
    ctr++;
  }
  while(temp != 0) {
    song_node *rand = random_pointer(temp);
    printf("Name: %s     Artist: %s\n", rand->name, rand->artist);
    temp = remove_node(find_song(temp, rand->name));
  }
  printf("\n");
}
*/