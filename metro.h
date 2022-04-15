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
#define CHAI 80
#define MAT 80
typedef char STRING[CHAI];
typedef struct _TEMPSTATION
{
  STRING nomS;
  double Hdebut;
  double HFin;
}TEMPSTATION;
typedef struct _NODET
{
  TEMPSTATION tstation;
  struct _NODET *sprec;
  struct _NODET *ssuiv;
}NODET,*PNODET;
typedef struct
{
  PNODET first;
  PNODET last;
}LISTemps;

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
  NODET first;
  NODET last;
}LIST;

void printStation(STATION station);
#endif /* metro_h */
