#include <iostream>
#include <cassert>
#include "a5_book.hpp"
#include "a5_library.hpp"

using namespace std;

void test_book_insertion1() {
    // setup
    Library my_library;
    Book my_book1("test1", "atest2", "dptest3");
    Book my_book2("test2", "atest2", "dptest3");
    Book my_book3("test3", "atest2", "dptest3");

    // test scenario
    assert(my_library.insert(my_book1));
    assert(my_library.insert(my_book2));
    assert(my_library.insert(my_book3));

    my_library.print();

    // teardown
    // automatic destruction (freeing of memory) of these objects
}

void test_book_removal() {

}

void execute_tests() {
    test_book_insertion();
}

int main() {
    execute_tests();
}