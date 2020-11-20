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

void test_library_constructor_default() {
    //creates an instance of Library using the default constructor
    Library test_library;

    //prints out the library to check
    test_library.print();
}

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

    //prints out the library to check
    test_library.print();
}

void test_library_print() {
    //creates some books
    Book my_book1("Book1", "Author1", "Date1");
    Book my_book2("Book2", "Author2", "Date2");
    Book my_book3("Book3", "Author3", "Date3");
    Book my_book4("Book4", "Author4", "Date4");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books;
    my_books.push_back(my_book3);
    my_books.push_back(my_book2);
    my_books.push_back(my_book4);
    my_books.push_back(my_book1);

    //creates an instance of Library using the parametric constructor
    Library test_library(my_books);

    //expected output
    cout << "Expected Output:" << endl;
    cout << "(1) ";  my_book3.print();    
    cout << "(2) ";  my_book2.print();
    cout << "(3) ";  my_book4.print();
    cout << "(4) ";  my_book1.print();
    cout << endl;

    test_library.print();
}

void test_book_removal_parameters() {
    //creates some books
    Book my_book1("Book1", "Author1", "Date1");
    Book my_book2("Book2", "Author2", "Date2");
    Book my_book3("Book3", "Author3", "Date3");
    Book my_book4("Book4", "Author4", "Date4");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books;
    my_books.push_back(my_book1);
    my_books.push_back(my_book2);
    my_books.push_back(my_book3);
    my_books.push_back(my_book4);

    //creates an instance of Library using the parametric constructor
    Library test_library(my_books);

    //calls remove function with details as the parameters
    assert(test_library.remove("Book1", "Author1", "Date1") && "test failed");
    assert(test_library.remove("Book3", "Author3", "Date3"));
    cout << "Successfully removed specified books by parameter." << endl;

    test_library.print();
}

void test_book_removal_book() {
    //creates some books
    Book my_book1("Book1", "Author1", "Date1");
    Book my_book2("Book2", "Author2", "Date2");
    Book my_book3("Book3", "Author3", "Date3");
    Book my_book4("Book4", "Author4", "Date4");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books;
    my_books.push_back(my_book1);
    my_books.push_back(my_book2);
    my_books.push_back(my_book3);
    my_books.push_back(my_book4);

    //creates an instance of Library using the parametric constructor
    Library test_library(my_books);

    //calls remove function with Book as the parameter
    assert(test_library.remove(my_book2));
    assert(test_library.remove(my_book1));

    cout << "Successfully removed specified books by passing Book." << endl;

    test_library.print();
}



void execute_tests() {
    //test_book_insertion1();
    //test_library_constructor_default();
    //test_library_constructor_vector();
    test_library_print();
    //test_book_removal_book();
    //test_book_removal_parameters();
}

int main() {
    execute_tests();
}








