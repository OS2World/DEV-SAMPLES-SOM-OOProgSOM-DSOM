/*
 *  This file was generated by the SOM Compiler and Emitter Framework.
 *  Generated using: 
 *      SOM Emitter emitxtm: somc/smmain.c
 */

#define Hello_Class_Source
#include <hello.xih>
#include <iostream.h>

SOM_Scope void  SOMLINK printHello(Hello *somSelf,  Environment *ev)
{
    HelloData *somThis = HelloGetData(somSelf);
    HelloMethodDebug("Hello","printHello");

    cout << somThis->msg << "\n";
}

