#include "error.xh"
#include <iostream.h>

main()
{
  Environment   *ev;
  ErrorExample  *ex1;
  char          *exId;
  BadCall       *bc;
  StExcep       *stExVal;

  ev = somGetGlobalEnvironment();
  ex1 = new ErrorExample;
  ex1->execute(ev);

  switch(ev->_major)
  {
    case SYSTEM_EXCEPTION:
       exId = somExceptionId(ev);
       stExVal = (StExcep *) somExceptionValue(ev);
       cout << "Minor Code " << stExVal->minor;
       cout << "Status " << stExVal->completed;
       somExceptionFree(ev);
       break;
     
    case USER_EXCEPTION:
        exId = somExceptionId(ev);
        if (strcmp(exId, ex_ErrorExample_BadCall) == 0)
        {
           bc = (BadCall *) somExceptionValue(ev);
           cout << bc->errorCode << "\n";
           cout << bc->reason << "\n";
           somExceptionFree(ev);         // Free exception memory
        }
       break;
     
    case NO_EXCEPTION:
       break;
  } 
}
