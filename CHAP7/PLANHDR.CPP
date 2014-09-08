#include "planhdr.hpp"
#include <stdio.h>

Boolean PlannerHandler :: dispatchHandlerEvent(IEvent &evt)
{
   if (evt.eventId() == WM_REFRESH                ||
       evt.eventId() == WM_STAND_ALONE            ||
       evt.eventId() == WM_CONNECTION_LOST        ||
       evt.eventId() == WM_CONNECTION_REESTABLISH ||
       evt.eventId() == WM_LOST_RECOVER)
   {
      //************************************************
      // events that are of interest to DayPlannerWindow
      //************************************************
      return plannerMessage(evt);
   } 
   return false;
}

Boolean PlannerHandler :: plannerMessage(IEvent& evt)
{
   // Provides default return
   return false;
}
