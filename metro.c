//
//  metro.c
//  itinerairemetro
//
//  Created by Ibrahima Ndiaye on 15/04/2022.
//
#include "metro.h"

void printStation(STATION station , int num )
{

  printf("***************\n");
  printf("* STATION %d  *\n",num);
  printf("***************\n");
  printf("Nom de la station : %s \n",station.nomS);
  printf("Temps pour aller à la station précédente: %.0f min\n", station.tempPrec);
  printf("Temps pour aller à la station suivante : %.0f min\n",station.tempSuiv);
}
const char* getNomStation(STATION *station)
{
  return station->nomS;
} void setName(STATION *station ,STRING name )
{
  strncpy(station->nomS,name,CHAI);
}
void loadtabTemps(double *tab, char* str , int i)
{
  char* new_str = strtok(str, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  if (new_str[0]=='*') {
    for(int j=0;new_str[j];j++)
    {
      new_str[j]=new_str[j+1];
    }
  }
  tab[i] = atof(new_str);
}
void loadStation(STATION* station, char* str ,double *tab , int i)
{
  char* new_str = strtok(str, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  strncpy(station->nomS,new_str,CHAI);
  station->tempSuiv=tab[i+1]-tab[i];
  station->tempSuiv=station->tempSuiv*100;
  if (station->tempSuiv<0) {
    station->tempSuiv=-station->tempSuiv;
  }
  station->tempPrec=tab[i]-tab[i-1];
  station->tempPrec=station->tempPrec*100;
  if (station->tempPrec<0) {
    station->tempPrec=-station->tempPrec;
  }
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  //Conversion ASCII to float
}
void loadStationRER(STATION* station, char* str)
{
  char* new_str = strtok(str, ":");
  new_str = strtok(NULL, ":");
  new_str = strtok(NULL, ":");
  strncpy(station->nomS,new_str,CHAI);

}
void appendToListSTation(LIST* list, STATION station)
{
  NODE *node;
  node = (NODE*) calloc(1 ,sizeof(NODE));
  node->station=station;
  if(list->last!=NULL && list->first!=NULL)
  {
    list->last->ssuiv=node;
    node->sprec=list->last;
    list->last=node;
  }
  else
  {
    list->first=node;
    list->last=node;
    list->first->station.tempPrec=0;
  }
//  list->first->station.tempPrec=0;
//  free(node);
}
void printList(LIST list )
{
  if(list.first==NULL && list.last==NULL)
  {
    printf("La liste est vide \n");
  }
  else
  {
    NODE* node;
    int i=1;
    node=list.first;
    while (node!=list.last)
    {
       printStation(node->station,i);
      node=node->ssuiv;
      i++;
      printf("\n");
    }
    printStation(list.last->station,i );
  }
  printf("\n");
}
void loadmetro1a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  for(int i=1;i<100;i++)
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]==':' && str[2]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  for(int i=1;i<100;i++)
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]==':' && str[2]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro1b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]==':' && str[2]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]==':' && str[2]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro2a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='2' && str[1]==':' && str[2]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='2' && str[1]==':' && str[2]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro2b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='2' && str[1]==':' && str[2]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='2' && str[1]==':' && str[2]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro3a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='3' && str[1]==':' && str[2]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='3' && str[1]==':' && str[2]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro3b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='3' && str[1]==':' && str[2]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='3' && str[1]==':' && str[2]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro3bisa(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='3' && str[1]=='b' && str[5]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='3' && str[1]=='b' && str[5]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro3bisb(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='3' && str[1]=='b' && str[5]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='3' && str[1]=='b' && str[5]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro4a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='4' && str[1]==':' && str[2]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='4' && str[1]==':' && str[2]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro4b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='4' && str[1]==':' && str[2]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='4' && str[1]==':' && str[2]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro5a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='5' && str[1]==':' && str[2]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='5' && str[1]==':' && str[2]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro5b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='5' && str[1]==':' && str[2]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='5' && str[1]==':' && str[2]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro6a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='6' && str[1]==':' && str[2]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='6' && str[1]==':' && str[2]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro6b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='6' && str[1]==':' && str[2]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='6' && str[1]==':' && str[2]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}

void loadmetro7a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='5' && str[1]==':' && str[2]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='7' && str[1]==':' && str[2]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro7b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='7' && str[1]==':' && str[2]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='7' && str[1]==':' && str[2]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro7bisa(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='7' && str[1]=='b' && str[5]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='7' && str[1]=='b' && str[5]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro7bisb(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='7' && str[1]=='b' && str[5]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='7' && str[1]=='b' && str[5]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro8a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='8' && str[1]==':' && str[2]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='8' && str[1]==':' && str[2]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro8b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='8' && str[1]==':' && str[2]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='8' && str[1]==':' && str[2]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro9a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='9' && str[1]==':' && str[2]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='9' && str[1]==':' && str[2]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro9b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='9' && str[1]==':' && str[2]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='9' && str[1]==':' && str[2]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro10a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='0' && str[3]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='0' && str[3]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro10b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='0' && str[3]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='0' && str[3]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro11a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='1' && str[3]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='1' && str[3]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro11b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='1' && str[3]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='1' && str[3]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro12a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='2' && str[3]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='2' && str[3]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro12b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='2' && str[3]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='2' && str[3]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro13a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='3' && str[3]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='3' && str[3]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro13b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='3' && str[3]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='3' && str[3]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro13c(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='3' && str[3]=='c')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='3' && str[3]=='c')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro13d(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='3' && str[3]=='d')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='3' && str[3]=='d')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro14a(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='4' && str[3]=='a')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='4' && str[3]=='a')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadmetro14b(LIST *list,char* str , FILE* file)
{
  double temps[100];
  int z=0,k=0;
  while (!feof(file)){
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='4' && str[3]=='b')
      {
        loadtabTemps(temps, str, z);
        z++;
      }
    }
  }
  rewind(file);
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='1' && str[1]=='4' && str[3]=='b')
      {
        STATION station;
        loadStation(&station, str, temps, k) ;
        k++;
        appendToListSTation(list, station);
      }
    }
  }
  list->last->station.tempSuiv=0;
}
void loadrer(LIST *list,char* str , FILE* file)
{
  while (!feof(file))
  {
    if(fgets(str,CHAI, file)!=NULL)
    {
      if(str[0]=='A' && str[1]=='1' && str[3]=='a')
      {
        STATION station;
        loadStationRER(&station, str);
        station.tempSuiv=0;
        station.tempPrec=0;
        appendToListSTation(list, station);
      }
    }
  }
}
void loadListTab(LIST *tab , FILE *file)
{
  char str[CHAI];
  for(int i=0;i<36;i++)
  {
    LIST metro={NULL, NULL};
    switch (i)
    {
      case 0:
        loadmetro1a(&metro, str, file);
        tab[i]=metro;
        break;
      case 1:
        loadmetro1b(&metro, str, file);
        tab[i]=metro;
        break;
      case 2:
        loadmetro2a(&metro, str, file);
        tab[i]=metro;
        break;
      case 3:
        loadmetro2b(&metro, str, file);
        tab[i]=metro;
        break;
      case 4:
        loadmetro3a(&metro, str, file);
        tab[i]=metro;
        break;
      case 5:
        loadmetro3b(&metro, str, file);
        tab[i]=metro;
        break;
      case 6:
        loadmetro3bisa(&metro, str, file);
        tab[i]=metro;
        break;
      case 7:
        loadmetro3bisb(&metro, str, file);
        tab[i]=metro;
      case 8:
        loadmetro4a(&metro, str, file);
        tab[i]=metro;
        break;
      case 9:
        loadmetro4b(&metro, str, file);
        tab[i]=metro;
        break;
      case 10:
        loadmetro5a(&metro, str, file);
        tab[i]=metro;
        break;
      case 11:
        loadmetro5b(&metro, str, file);
        tab[i]=metro;
        break;
      case 12:
        loadmetro6a(&metro, str, file);
        tab[i]=metro;
        break;
      case 13:
        loadmetro6b(&metro, str, file);
        tab[i]=metro;
        break;
      case 14:
        loadmetro7a(&metro, str, file);
        tab[i]=metro;
        break;
      case 15:
        loadmetro7b(&metro, str, file);
        tab[i]=metro;
        break;
      case 16:
        loadmetro7bisa(&metro, str, file);
        tab[i]=metro;
        break;
      case 17:
        loadmetro7bisb(&metro, str, file);
        tab[i]=metro;
        break;
      case 18:
        loadmetro8a(&metro, str, file);
        tab[i]=metro;
        break;
      case 19:
        loadmetro8b(&metro, str, file);
        tab[i]=metro;
        break;
      case 20:
        loadmetro9a(&metro, str, file);
        tab[i]=metro;
        break;
      case 21:
        loadmetro9b(&metro, str, file);
        tab[i]=metro;
        break;
      case 22:
        loadmetro10a(&metro, str, file);
        tab[i]=metro;
        break;
      case 23:
        loadmetro10b(&metro, str, file);
        tab[i]=metro;
        break;
      case 24:
        loadmetro11a(&metro, str, file);
        tab[i]=metro;
        break;
      case 25:
        loadmetro11b(&metro, str, file);
        tab[i]=metro;
        break;
      case 26:
        loadmetro12a(&metro, str, file);
        tab[i]=metro;
        break;
      case 27:
        loadmetro12b(&metro, str, file);
        tab[i]=metro;
        break;
      case 28:
        loadmetro13a(&metro, str, file);
        tab[i]=metro;
        break;
      case 29:
        loadmetro13b(&metro, str, file);
        tab[i]=metro;
        break;
      case 30:
        loadmetro13c(&metro, str, file);
        tab[i]=metro;
        break;
      case 31:
        loadmetro13c(&metro, str, file);
        tab[i]=metro;
        break;
      case 32:
        loadmetro14a(&metro, str, file);
        tab[i]=metro;
        break;
      case 33:
        loadmetro14b(&metro, str, file);
        tab[i]=metro;
        break;
      case 34:
        loadrer(&metro, str, file);
        tab[i]=metro;
        break;
      default:
        break;
    }
  }
    fclose(file);
  
}


