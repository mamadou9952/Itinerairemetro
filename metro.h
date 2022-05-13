//
//  metro.h
//  itinerairemetro
//
//  Created by Ibrahima Ndiaye on 15/04/2022.
//
#ifndef metro_h
#define metro_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#define CHAI 80
#define MAT 80
typedef char STRING[CHAI];
typedef struct _STATION
{
  STRING nomS;
  double tempSuiv;
  double tempPrec;
} STATION;
typedef struct _NODE
{
  STATION station;
  struct _NODE *sprec;
  struct _NODE *ssuiv;
}NODE,*PNODE;
typedef struct
{
  PNODE first;
  PNODE last;
}LIST;
typedef struct _TabLigne
{
  STRING nameLigne;
  LIST list;
}TABLIGNE ,*PTABLIGNE;
void printStation(STATION station , int num);
const char* getNomStation(STATION *station);
void setName(STATION *station ,STRING name );
void appendToListSTation(LIST* list, STATION station);
void loadtabTemps(double *tab, char* str , int i);
void printList(LIST list);
void loadStation(STATION* station, char* str ,double *tab , int i);
void loadStationRER(STATION* station, char* str);
void loadrer(LIST *list,char* str , FILE* file);
void rewind(FILE *stream);
void loadmetro1a(LIST *list,char* str , FILE* file);
void loadmetro1b(LIST *list,char* str , FILE* file);
void loadmetro2a(LIST *list,char* str , FILE* file);
void loadmetro2b(LIST *list,char* str , FILE* file);
void loadmetro3a(LIST *list,char* str , FILE* file);
void loadmetro3b(LIST *list,char* str , FILE* file);
void loadmetro3bisa(LIST *list,char* str , FILE* file);
void loadmetro3bisb(LIST *list,char* str , FILE* file);
void loadmetro4a(LIST *list,char* str , FILE* file);
void loadmetro4b(LIST *list,char* str , FILE* file);
void loadmetro5a(LIST *list,char* str , FILE* file);
void loadmetro5b(LIST *list,char* str , FILE* file);
void loadmetro6a(LIST *list,char* str , FILE* file);
void loadmetro6b(LIST *list,char* str , FILE* file);
void loadmetro7a(LIST *list,char* str , FILE* file);
void loadmetro7b(LIST *list,char* str , FILE* file);
void loadmetro7bisa(LIST *list,char* str , FILE* file);
void loadmetro7bisb(LIST *list,char* str , FILE* file);
void loadmetro8a(LIST *list,char* str , FILE* file);
void loadmetro8b(LIST *list,char* str , FILE* file);
void loadmetro9a(LIST *list,char* str , FILE* file);
void loadmetro9b(LIST *list,char* str , FILE* file);
void loadmetro10a(LIST *list,char* str , FILE* file);
void loadmetro10b(LIST *list,char* str , FILE* file);
void loadmetro11a(LIST *list,char* str , FILE* file);
void loadmetro11b(LIST *list,char* str , FILE* file);
void loadmetro12a(LIST *list,char* str , FILE* file);
void loadmetro12b(LIST *list,char* str , FILE* file);
void loadmetro13a(LIST *list,char* str , FILE* file);
void loadmetro13b(LIST *list,char* str , FILE* file);
void loadmetro13c(LIST *list,char* str , FILE* file);
void loadmetro13d(LIST *list,char* str , FILE* file);
void loadmetro14a(LIST *list,char* str , FILE* file);
void loadmetro14b(LIST *list,char* str , FILE* file);
void loadListTab(LIST *tab , FILE *file);






#endif /* metro_h */
