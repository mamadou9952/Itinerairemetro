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
  LIST tab[40];
//  char str[CHAI];
//  LIST metro={NULL, NULL};
  if(file != NULL)
  {
    loadListTab(tab, file);
    
//    loadmetroX(&metro, str, file, '1', ':', 'a');
//    loadmetroXbis(&metro, str, file, '3', 'b', 'a');
//    loadmetroXX(&metro, str, file, '1', '4', 'a');
//    loadmetroX(&metro, str, file, '4', ':', 'b');
      fclose(file);
  }
  else
  {
    printf("Impossible d'ouvrir le fichier \n ");
  }
//  printList(metro);
  printList(tab[4]);
  return 0;
}

