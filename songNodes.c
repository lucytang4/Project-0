#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songNodes.h"

void print_list(song_node *node) {

  if (node != 0) {
    song_node *temp = node;
    while(temp != NULL) {
      printf("Name: %s     Artist: %s\n", temp->name, temp->artist);
      temp = temp->next;
    }
    printf("\n");
  }
}

void print_node(song_node *node) {
  if (node != 0) {
      printf("Name: %s     Artist: %s\n", node->name, node->artist );
  }
  else {
      printf("");
  }
}


int list_len(song_node* node) {
  int len = 0;
  while (node){
    len++;
    node = node->next;
  }
  return len;
}

void clear_list(song_node *node) {
  if (node->next != 0) {
    node->next = 0;
    clear_list(node->next);
  }
}

song_node* insert_front(song_node *node, char *newArtist, char *newName) {
  song_node *temp = (song_node *)malloc(sizeof(song_node));
  strncpy(temp->artist, newArtist, 256);
  strncpy(temp->name, newName, 256);
  temp->next = node;
  return temp;
}


int song_cmp(song_node *node, char *artist, char *name) {
  int artistcomp = strcmp(node->artist, artist);
  if (artistcomp == 0){
    return strcmp(node->name, name);
  }
  return artistcomp;
}

song_node* insert_order(song_node *node, char *newArtist, char *newName){
  if (node == 0) {
    return insert_front(node, newArtist, newName);
  }
  if (strcmp(newArtist, node->artist) < 0) {
    return insert_front(node, newArtist, newName);
  }
  if (strcmp(newArtist, node->artist) == 0 && strcmp(newName, node->name) < 0) {
    return insert_front(node, newArtist, newName);
  }
  else {
    node->next = insert_order(node->next, newArtist, newName);
  }
  return node;
}

song_node* insert(song_node *node, char *newArtist, char *newName){
  song_node *temp = node;
  return insert_order(temp, newArtist, newName);
}

song_node* free_list(song_node *node){
  song_node *temp = node;

  if (node != 0) {
    while (node != 0) {
      node = node->next;
      free(temp);
      temp = node;
    }
  }
  return node;
}

song_node* find_song(song_node *node, char *name){
  while (node != 0) {
    if (strstr(node->name, name)) {
        break;
    }
    node = node->next;
  }
  return node;
}

song_node* find_artist_song(song_node *node, char *artist){
  while (node != 0) {
    if (strstr(node->artist, artist)) {
        break;
    }
    node = node->next;
  }
  return node;
}

song_node* random_pointer(song_node *node){
  if (node != 0) {
    int len = list_len(node);
    int seed = rand() % len;
    for (len = 0; len<seed; len++)
      node = node->next;
  }
  return node;
}

/*
void remove_node( song_node *n, song_node *removing ){
  if (n == removing){
    strcpy(n->name,n->next->name);
    strcpy(n->artist,n->next->artist);
    n->next = n->next->next;
    free(removing);
  }
}
*/