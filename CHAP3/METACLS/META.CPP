#include "animal.xh"
#include "robin.xh"
#include <stdio.h>

main(int argc, char *argv[], char *envp[])
{
   Animal      *cat, *dog;
   Robin       *bird;
   SOMClass    *birdClass;
   SOMClass    *birdClassClass;

   MetaAnimal  *mcat;
   Environment *ev;

   ev = somGetGlobalEnvironment();

   //***************************************
   // Create the Animal class object
   //***************************************
   mcat = AnimalNewClass(0,0);

   //******************************************
   // Create the Animal object with name Spot
   //******************************************
   cat = mcat->createAnimal(ev, "Spot");
   cat->sleep(ev);
   somPrintf("Spot class is %s\n", cat->somGetClassName() );

   //*************************************************
   // Create another Animal object with name Lassie
   //*************************************************
   dog = mcat->createAnimal(ev,"Lassie");
   dog->sleep(ev);

   printf("total number of Animal objects: %d\n", mcat->_get_count(ev) );

   //**************************************** 
   // Create a Bird object
   //****************************************
   printf("\nCreate a Robin object\n");
   bird = new Robin;
   birdClass = bird->somGetClass();
   somPrintf("Robin meta class is: %s\n", birdClass->somGetClassName());
}
