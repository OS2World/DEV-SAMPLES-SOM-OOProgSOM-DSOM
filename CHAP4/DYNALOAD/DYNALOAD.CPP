#include <iostream.h>
#include <som.xh>    
#include <somobj.xh>
#include <somcm.xh>

main(int argc, char *argv[], char *envp[])
{
   SOMClass      *myClass;
   somId         classId;

   somEnvironmentNew();
   classId = somIdFromString(argv[1]);

   //******************************************************
   // The following path has to be modified depending on
   // where you install the "domestic" DLL
   //******************************************************
   myClass = SOMClassMgrObject->somFindClsInFile(classId,
                                   0,0,
                                   "C:\\CLAU\\BOOK\\CHAP4\\DYNALOAD\\DOMESTIC.DLL");

   if (myClass)
   {
      SOMObject *myObj;
      Environment *ev;
 
      ev = somGetGlobalEnvironment();
      myObj = myClass->somNew();  // create an object

      if (myObj)
      {
//      somPrintf("class name %s\n", myObj->somGetClassName() );

        myObj->somDispatch((somToken*)0,
                           somIdFromString("display"),
                           myObj,
                           ev);
      }
   } 
   else
   {
      cout << "Can't load class " << argv[1] << "\n";
   } 
}
