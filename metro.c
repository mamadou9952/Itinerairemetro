//
//  metro.c
//  itinerairemetro
//
//  Created by Ibrahima Ndiaye on 15/04/2022.
//

#include "metro.h"


void printStation(STATION station)
{
  printf("**************\n");
  printf("* STATION *\n");
  printf("**************\n");
  printf("Nom de la station : %s",station.nomS);
  printf("Temps pour aller à la station précédente: %lf",station.tempPrec);
  printf("Temps pour aller à la station suivante : %lf",station.tempSuiv);
  
}
const char* getNomStation(STATION *station)
{
  return station->nomS;
}
void setName(STATION *station ,STRING name )
{
  strncpy(station->nomS,name,CHAI);
}

//const char* getTempsPrec(STATION *station )
//{
//  return ;
//}
//unsigned int getTempsSuiv(STATION *station)
//{
//  return ;
//}
void loadStationpourTemps(TEMPSTATION* station, char* str , TEMPSTATION temps)
{
  char* new_str = strtok(str, ";");
  new_str = strtok(NULL, ";");
  new_str = strtok(NULL, ";");
  strncpy(station->nomS,new_str,CHAI);
  new_str = strtok(NULL, ";");
  new_str = strtok(NULL, ";");
  new_str = strtok(NULL, ";");
  station->Hdebut=atof(new_str);
  new_str = strtok(NULL, ";");
  station->HFin=atof(new_str);
  //Conversion ASCII to float
}
void appendToListTempsSTation(LISTemps *list, TEMPSTATION temps)
{
  NODET *node;
  node = (NODET*) calloc(1 ,sizeof(NODET));
  node->tstation=temps;
  if(list->last!=NULL)
  {
    list->last->ssuiv=node;
    node->sprec=list->last;
    list->last=node;
  }
  else
  {
    list->first=node;
    list->last=node;
  }
}
void loadStationpourTemps(TEMPSTATION* station, char* str ,LISTemps *list )
{
  NODET* node;
  node=list->first;
  while (node!=NULL) {
    n
  }
  
}
