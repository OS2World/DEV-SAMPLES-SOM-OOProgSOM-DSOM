#include <somtcnst.xh>
#include <stdio.h>

main(int argc, char *argv[], char *envp[])
{
   any myany;
   float val = 1.2;

   myany._type = TC_float;
   myany._value = &val;

   printf("%f\n", *((float *) myany._value));
}
