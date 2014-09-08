#include "hello.h"

main(int argc, char *argv[], char *envp[])
{
   Hello       myhello;
   Environment *ev;

   ev = somGetGlobalEnvironment();
   myhello = HelloNew();
 
   __set_msg(myhello, ev, "Hello World from SOM");
   _printHello(myhello,ev);

   _somFree(myhello);
}
