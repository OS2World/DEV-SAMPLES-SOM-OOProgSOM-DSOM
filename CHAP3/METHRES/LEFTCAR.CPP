/*
 *  This file was generated by the SOM Compiler and Emitter Framework.
 *  Generated using: 
 *      SOM Emitter emitxtm: 2.7
 */

#define LeftSteeringCar_Class_Source
#include <leftcar.xih>
#include <stdio.h>

SOM_Scope void  SOMLINK printCarSpec(LeftSteeringCar *somSelf, 
                                      Environment *ev)
{
    /* LeftSteeringCarData *somThis = LeftSteeringCarGetData(somSelf); */
    LeftSteeringCarMethodDebug("LeftSteeringCar","printCarSpec");

    printf("\nEnter Left Steering Car\n");
    LeftSteeringCar_parent_Car_printCarSpec(somSelf, ev);
}

