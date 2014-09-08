#include "cat.xh"
#include "dog.xh"

#ifdef __IBMC__
  #pragma linkage(SOMInitModule,system)
#endif

SOMEXTERN void SOMLINK SOMInitModule(long majorVersion,
                                     long minorVersion,
                                     string className)
{
   SOM_IgnoreWarning(majorVersion);
   SOM_IgnoreWarning(minorVersion);
   SOM_IgnoreWarning(className);

   CatNewClass(Cat_MajorVersion, Cat_MinorVersion);
   DogNewClass(Dog_MajorVersion, Dog_MinorVersion);

}
