/*
 *  This file was generated by the SOM Compiler and Emitter Framework.
 *  Generated using: 
 *      SOM Emitter emitxtm: somc/smmain.c
 */

#define Car_Class_Source
#define MetaCar_Class_Source
#include <car.xih>

SOM_Scope void  SOMLINK printCarSpec(Car *somSelf,  Environment *ev)
{
    CarData *somThis = CarGetData(somSelf);
    CarMethodDebug("Car","printCarSpec");

    somPrintf("Make %s Model %s Price %d\n",
              somThis->make, somThis->model, somThis->price);
}


SOM_Scope Car*  SOMLINK createCar(MetaCar *somSelf,  Environment *ev, 
                                  string make, string model, 
                                  long price)
{
    Car *car;
/*    MetaCarData *somThis = MetaCarGetData(somSelf);  */
    MetaCarMethodDebug("MetaCar","createCar");
   
    car = somSelf->somNew();

    car->_set_make(ev,make);
    car->_set_model(ev,model);
    car->_set_price(ev,price);
                                                      
    return car;
}

