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
  LIST tab[34];
  if(file != NULL)
  {
    loadListTab(tab, file);
    fclose(file);
  }
  else
  {
    printf("Impossible d'ouvrir le fichier \n ");
  }
  printList(tab[33]);

  return 0;
}
