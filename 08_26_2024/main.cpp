#include "person.h"
#include "employee.h"

int main()
{
    person p("john", "doe");
    employee e("jane", "doe", "123-45-6789", "2024-02-26");
    p.fname;
    e.fname;
    p.getFname();
    e.getFname();

    return 0;
}