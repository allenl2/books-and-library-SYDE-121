#include <iostream>
#include <vector>
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

void test_library_constructor_vector() {
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
    Library sample_library;

    //prints out the library to test
    sample_library.print();
}

void execute_tests() {
//    test_book_insertion();
    test_library_constructor_vector();
}

int main() {
    execute_tests();
}