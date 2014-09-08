#include <stdlib.h>
#include <string.h>
#include <somd.xh>
#include <implrep.xh>
#include <stdio.h>

main(int argc, char **argv)
{
  Environment       *ev;
  ImplementationDef *implDef;
  sequence(string)  classes;
  short             i;

  if (argc != 2) 
  {
     printf("You must specify an Implementation alias (e.g. Chris)\n");
     return;
  } 
  
  ev = SOM_CreateLocalEnvironment();
  SOMD_Init(ev);

  implDef = SOMD_ImplRepObject->find_impldef_by_alias(
                                                  ev, argv[1]);
  if (implDef) 
  {
    classes = SOMD_ImplRepObject->find_classes_by_impldef(ev,
                                        implDef->_get_impl_id(ev));

    printf("Server : %s\n", argv[1]);
    printf("Program Name: %s\n", implDef->_get_impl_program(ev));
    printf("Server Class: %s\n", implDef->_get_impl_server_class(ev));
    printf("Host Name: %s\n", implDef->_get_impl_hostname(ev));
 
    for (i=0; i < sequenceLength(classes); i++)
    {
        printf("%s\n", sequenceElement(classes,i) );
    }
  }
  else
  {
     printf("Implementation Alias not found in Implementation Repository\n");
  }

  SOMD_Uninit(ev);
  SOM_UninitEnvironment(ev);
  return;
}
