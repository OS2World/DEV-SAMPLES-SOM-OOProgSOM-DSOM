#include <iostream.h>
#include "mgr.xh"
#include "prg.xh"

calc(Employee *emp)
{
   SOMClass    *mgrClass;
   SOMClass    *empClass;
   Environment *ev;

   ev = somGetGlobalEnvironment();

   //****************************************************
   // Use <className>ClassData.classObject to get
   // pointer to class object
   // Alternatively, use _Programmer
   //****************************************************
   if (emp->somIsA(ProgrammerClassData.classObject))
   {
      cout << "Programmer salary: " ;
      cout << (emp->salary(ev) + ( (Programmer *) emp)->overtime(ev));
   }

   //************************************************
   // Create a Manager Class Object
   //************************************************
   mgrClass = ManagerNewClass(0,0);
   if ( emp->somIsA(mgrClass) )
   {
      cout << "Manager salary: " ;
      cout << (emp->salary(ev) + ((Manager *) emp)->bonus(ev));
   }
   cout << "\n";
}

main(int argc, char *argv[], char *envp[])
{
   Manager    *mgr;
   Programmer *prg;

   mgr = new Manager();
   prg = new Programmer();

   calc(mgr);
   calc(prg);
}
