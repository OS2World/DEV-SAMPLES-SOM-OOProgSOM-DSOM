#include <stdlib.h>
#include <string.h>
#include <somd.xh>
#include <somoa.xh>
#include <implrep.xh>
#include <stdio.h>

void cleanup(Environment *);

#define checkEv(ev) ((ev)->_major != NO_EXCEPTION)

int main(int argc, char **argv)
{
    Environment ev;
    long count=0;
    long rc;

    //*************************************
    // Initialize DSOM environment
    //*************************************
    SOM_InitEnvironment(&ev);
    SOMD_Init(&ev);

    //*************************************
    // Initialize SOM Object Adaptor
    //*************************************
    SOMD_SOMOAObject = new SOMOA;

    /* parse arguments */
    switch (argc) {

    /* implementation id passed */
    case 2:
        /* get ImplementationDef from Implementation Repository */
        SOMD_ImplDefObject = SOMD_ImplRepObject->find_impldef(
                                            &ev, (ImplId) argv[1]);
        if (checkEv(&ev)) 
        {
          somPrintf("find_impldef failed, exception = %s\n",
                     somExceptionId(&ev));
          cleanup(&ev);
          exit(1);
        }
        break;

    /* alias passed */
    case 3:
        if ((argv[1][0] == '-') &&
            ((argv[1][1] == 'a') || (argv[1][1] == 'A'))) 
        {
          /* get ImplementationDef from input alias */
          SOMD_ImplDefObject = SOMD_ImplRepObject->find_impldef_by_alias(
                                                &ev, (ImplId) argv[2]);
          if (checkEv(&ev)) 
          {
            somPrintf("find_impldef_by_alias failed, exception = %s\n",
                      somExceptionId(&ev));
            cleanup(&ev);
            exit(1);
          }
        }
        else 
        {
          somPrintf("invalid arguments\n");
          cleanup(&ev);
          exit(1);
        }
        break;

    /* invalid number of arguments */
    default:
        somPrintf("invalid number of arguments\n");
        cleanup(&ev);
        exit(1);
        break;
    } 

    //**********************************************
    // server now ready to process requests
    //***********************************************
    SOMD_SOMOAObject->impl_is_ready(&ev, SOMD_ImplDefObject);
    
    for (; ;) 
    {
       count++;
       rc = SOMD_SOMOAObject->execute_next_request(&ev, SOMD_WAIT);
       printf("looping %d\n", count);
    }

    SOMD_SOMOAObject->deactivate_impl(&ev, SOMD_ImplDefObject);
    delete SOMD_ImplDefObject; 
    cleanup(&ev);
    return 0;
}

/*
 *  Frees local and global DSOM objects.  
 */

void cleanup(Environment *ev)
{
    delete SOMD_SOMOAObject;
    SOMD_Uninit(ev);
    SOM_UninitEnvironment(ev);
    return;
}
