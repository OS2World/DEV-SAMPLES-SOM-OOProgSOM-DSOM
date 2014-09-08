#include "employee.xh"
#include "company.xh"
#include <iostream.h>

testSequence()
{
  Environment *ev = somGetGlobalEnvironment();    
  Employee *emp1, *emp2;
  Company  *comp;
  _IDL_SEQUENCE_Employee list;
  short i;

  emp1 = new Employee;
  emp1->_set_name(ev, "Mary");

  emp2 = new Employee;
  emp2->_set_name(ev, "John");

  comp = new Company;
  comp->addEmployee(ev, emp1);
  comp->addEmployee(ev, emp2);
  
  list = comp->_get_empList(ev);
                                                 
  for (i=0; i < sequenceLength(list); i++)
  {
    cout << sequenceElement(list,i)->_get_name(ev) << "\n";
  }
}

main(int argc, char *argv[], char *envp[])
{
   testSequence();
}
