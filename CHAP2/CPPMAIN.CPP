#include "hello.xh"

main(int argc, char *argv[], char *envp[])
{
   Hello       *myhello;
   Environment *ev;

   ev = somGetGlobalEnvironment();
   myhello = new Hello();
 
   myhello->_set_msg(ev, "Hello World from SOM");
   myhello->printHello(ev);

   delete myhello;
}
