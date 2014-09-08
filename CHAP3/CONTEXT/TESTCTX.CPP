#include <somd.xh>
#include <cntxt.xh>
#include "context.xh"
#include <iostream.h>
#include <stdio.h>
main()
{
  Environment     *ev;
  ContextExample  *ex1;
  Context         *ctx;

  ev = somGetGlobalEnvironment();

  ctx = new Context;
  ctx->set_one_value(ev, "userid", "chris");

  ex1 = new ContextExample;
  ex1->startup(ev,ctx);

}
