//
//  main.c
//  itinerairemetro
//
//  Created by Ibrahima Ndiaye on 15/04/2022.
//
#include <stdio.h>
#include "metro.h"

int main(void)
{
  FILE* file =NULL;
  file=fopen("/Users/ibrahimandiaye/Documents/INFO/itinerairemetro/itinerairemetro/metro.csv","r");
  char str[CHAI];
  LIST metro={NULL, NULL};
  if(file != NULL)
  {
    loadrer(&metro, str, file);
    fclose(file);
  }
  else
  {
    printf("Impossible d'ouvrir le fichier \n ");
  }
  printList(metro);

  return 0;
}

