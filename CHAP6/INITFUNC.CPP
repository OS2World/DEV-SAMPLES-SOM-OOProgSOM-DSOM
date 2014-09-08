#include "workitem.xh"
#include "caldir.xh"
#include "day.xh"

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

   DayNewClass(Day_MajorVersion, Day_MinorVersion);
   WorkItemNewClass(WorkItem_MajorVersion, WorkItem_MinorVersion);
   CalendarDirNewClass(CalendarDir_MajorVersion, 
                       CalendarDir_MinorVersion);
}
