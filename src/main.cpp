#include <iostream>
#include <vector>

#include "hashMap.h"

int main()
{
    HashMap hash;

    Person mauro = {.name = "Mauro Pires", .age = 28};
    Person qwerty = {.name = "Qwerty Treq", .age = 23};
    Person das = {.name = "Das Treq", .age = 12};
    Person asc = {.name = "Asc Asg", .age = 32};
    Person vasjf = {.name = "Vasjf Vbas ", .age = 922};
    Person dsca = {.name = "Dsca Vaeq", .age = 62};

    // std::vector<Person> people = {mauro, qwerty, das, asc, vasjf, dsca};

    // for (auto p : people)
    //     hash.add(p.name, &p);


    hash.add(mauro.name, "Pires");
    hash.add(qwerty.name, "Data");

    hash.print();
    std::cout << "\tDONE" << std::endl;

    return 0;
}