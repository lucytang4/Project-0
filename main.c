#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "songNodes.h"
#include "songLibrary.h"

int main(){

  srand(time(NULL));

  printf("\nADDING SONGS...\n");
  addSong("bts", "blood, sweat & tears");
  addSong("got7", "hard carry");
  addSong("bts", "boy meets evil");
  addSong("monsta x", "all in");
  addSong("f(x)", "all mine");
  addSong("bts", "lost");
  printLib();

  printf("\nFINDING SONG LIB:\n");
  findSongLib("blood, sweat & tears");
  findSongLib("all in");
  findSongLib("wubba");

  printf("\nFINDING ARTIST LIB\n");
  findArtistLib("bts");
  findArtistLib("monsta x");
  findArtistLib("shinee");

  printf("\nPRINTING SONGS:\n");
  printLetterSongs('a');
  printLetterSongs('b');

  printf("\nPRINTING SONGS OF ARTIST:\n");
  printArtist("bts");
  printArtist("monsta x");

  printf("\nSHUFFLE:\n");
  //shuffle();

  printf("\nDELETING...\n");
  //removeSong("all mine", "f(x)");
  //removeSong("lost", "bts");
  //printLib();
  printf("\n");

  printf("\nCLEARING...\n");
  clearLibrary();
  printLib();
  printf("\n");

  song_node *bubbletea = insert_front(0, "bts", "blood, sweat & tears");
  bubbletea = insert_order(bubbletea, "got7", "hard carry");
  bubbletea = insert_order(bubbletea, "bts", "boy meets evil");
  bubbletea = insert_order(bubbletea, "monsta x", "all in");
  bubbletea = insert_order(bubbletea, "f(x)", "all mine");
  bubbletea = insert_order(bubbletea, "bts", "lost");

  printf("LIBRARY:\n");
  print_list(bubbletea);

  print_node(find_song(bubbletea, "blood, sweat & tears"));
  print_node(find_song(bubbletea, "boy meets evil"));
  print_node(find_song(bubbletea, "lubb"));
  print_node(find_artist_song(bubbletea, "bts"));
  print_node(find_artist_song(bubbletea, "got7"));
  print_node(find_artist_song(bubbletea, "wubb"));

  printf("\nSONG OF THE DAY:\n");
  print_node(random_pointer(bubbletea));

  printf("\nFREEDOMMM!\n");
  free_list(bubbletea);
  return 0;

}