#include <iostream>
#include <vector>
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

void test_library_constructor_default() {}

void test_library_constructor_vector() {
    //creates some books
    Book test_book1("Book1", "Author1", "Date1");
    Book test_book2("Book2", "Author2", "Date2");
    Book test_book3("Book3", "Author3", "Date3");
    Book test_book4("Book4", "Author4", "Date4");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books;
    my_books.push_back(test_book1);
    my_books.push_back(test_book2);
    my_books.push_back(test_book3);
    my_books.push_back(test_book4);

    //creates an instance of Library using the parametric constructor
    Library test_library(my_books);

    //prints out the library to test
    test_library.print();
}

void test_library_print() {}

void test_book_removal_parameters() {}

void test_book_removal_book() {
    //creates some books
    Book my_book1("Book1", "Author1", "Date1");
    Book my_book2("Book2", "Author2", "Date2");
    Book my_book3("Book3", "Author3", "Date3");
    Book my_book4("Book4", "Author4", "Date4");
    Book my_book5("Book5", "Author5", "Date5");
    Book my_book6("Book6", "Author6", "Date6");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books;
    my_books.push_back(my_book1);
    my_books.push_back(my_book2);
    my_books.push_back(my_book3);
    my_books.push_back(my_book4);
    my_books.push_back(my_book5);
    my_books.push_back(my_book6);

    //creates an instance of Library using the parametric constructor
    Library test_library(my_books);

    test_library.remove(my_book2);

    test_library.print();
}



void execute_tests() {
    //test_book_insertion1();
    //test_library_constructor_vector();
    test_book_removal_book();
}

int main() {
    execute_tests();
}








