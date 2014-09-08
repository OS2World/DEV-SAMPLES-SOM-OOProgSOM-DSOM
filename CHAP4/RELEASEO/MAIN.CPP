#include "a.xh"

main(int argc, char *argv[], char *envp[])
{
   Environment *ev;
   A *myObj;

   ev = somGetGlobalEnvironment();
   myObj = new A;

   myObj->_set_val1(ev,5);
   myObj->_set_val2(ev,100);

   myObj->display(ev);
}
