/*
Implement a class template for a Vector of elements that has the following methods:
- insert(index, element): inserts the element at the specified index (must be between 0 and size)
- remove(index): removes an element at the specified index
- sort(cmp): sorts the vector by using a comparison function; add an overload that takes no parameters and uses
operator< instead
- print: prints the vector elements
The vector should also have a copy/move constructor, along with an operator[] defined, which returns the element at the
given index.
You MUST have the implementation in the header.
*/
#include <iostream>
#include "template.h"

int compare_ints(int x, int y) {
    // return -1, x < y
    // return 1, x > y
    // return 0, x == y
    if (x < y) { return -1; }
    else if (x > y) { return 1; }
    else return 0;
}

int main() {
    Vector<int> v;

    // index, element
    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);
    v.print();

    Vector<int> w = v;
    v.print();
    // index
    printf("remove: \n");
    v.remove(0);
    printf("compare_ints: \n");
    v.sort(compare_ints);
    printf("%d\n", w[0]);
    v.print();
}