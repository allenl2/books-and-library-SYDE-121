#include <iostream>
#include "a5_book.hpp"
#include "a5_library.hpp"

using namespace std;

void test_book_insertion() {
    Library my_library;
    Book my_book("test1", "test2", "test3");
    my_book.print();
}

void test_book_removal() {

}

void execute_tests() {
    test_book_insertion();
}

int main() {
    execute_tests();
}