/* SYDE 121 ASSIGNMENT 5 - Allen Liu & Suhyma Rahman
* Nov 20, 2020
* 
* TESTING SCENARIOS
*  1) Library Print Function - creates several instances of Book, adds them to a vector, then creates an instance of Library using the vector parametric constructor. The print function is then called. The test also outputs the expected values for comparison. Another test is done for an instance of Library that is empty (ie. created with default constructor). The library is printed and expected values (nothing) are also printed.
* 
*  2) Library Constructors - create instances of Library using the vector parametric constructor (once with a vector conntaining Books, the other with an empty vector), and default constructor. Then prints out each of the libraries for verification.
* 
*  3) Library Removal - creates two instances of Library filled with instances of Books.  It first checks the remove function (by details - title, author, date) by removing the first Book, a general Book, and the last Book. Then checks the same function but with  a title, author, and date that is not correspond to any Book. Then checks the remove   function (by Book) by removing the first Book, a general Book, and the last Book. Then checks the same function but with an instance of Book that is not in the Library. For  each test, output the results to console.
* 
* LIMITATIONS
* - during the ininitalization of Library, the vector is not checked for duplicates, so they may exist in the final result (this may lead to errors in insert/remove)
*/

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

void test_library_constructors() {
    //creates some books
    Book test_book1("Book1", "Author1", "Date1");
    Book test_book2("Book2", "Author2", "Date2");
    Book test_book3("Book3", "Author3", "Date3");
    Book test_book4("Book4", "Author4", "Date4");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books1;
    my_books1.push_back(test_book1);
    my_books1.push_back(test_book2);
    my_books1.push_back(test_book3);
    my_books1.push_back(test_book4);

    //an empty vector to test
    vector<Book> my_books2;

    //creates instances of Library using both constructors
    Library test_library1(my_books1);
    Library test_library2(my_books2);
    Library test_library3;

    //prints out the each instance of library to check results
    cout << "Library 1 Test (Vector): " << endl;
    test_library1.print();
    cout << endl;

    cout << "Library 2 Test (Empty Vector): " << endl;
    test_library2.print();
    cout << endl;

    cout << "Library 3 Test (Default): " << endl;
    test_library3.print();
    cout << endl;
}

void test_library_print() {
    //creates some books
    Book my_book1("Book1", "Author1", "Date1");
    Book my_book2("Book2", "Author2", "Date2");
    Book my_book3("Book3", "Author3", "Date3");
    Book my_book4("Book4", "Author4", "Date4");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books1;
    my_books1.push_back(my_book3);
    my_books1.push_back(my_book2);
    my_books1.push_back(my_book4);
    my_books1.push_back(my_book1);

    //creates an instance of Library using the vector parametric and default constructors
    Library test_library1(my_books1);
    Library test_library2;

    //expected output
    cout << "Test 1 Expected Output:" << endl;
    cout << "(1) ";  my_book3.print();    
    cout << "(2) ";  my_book2.print();
    cout << "(3) ";  my_book4.print();
    cout << "(4) ";  my_book1.print();
    cout << endl << "Test 1 Actual: " << endl;
    test_library1.print();

    cout << endl << "Test 2 Expected Output: " << endl;
    cout << "Test 2 Actual Output: " << endl;
    test_library2.print();
}

void test_book_removal() {
    //creates some books
    Book my_book1("Book1", "Author1", "Date1");
    Book my_book2("Book2", "Author2", "Date2");
    Book my_book3("Book3", "Author3", "Date3");
    Book my_book4("Book4", "Author4", "Date4");
    Book my_book9("Book9", "Author9", "Date9");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books;
    my_books.push_back(my_book1);
    my_books.push_back(my_book2);
    my_books.push_back(my_book3);
    my_books.push_back(my_book4);

    //creates an instance of Library using the parametric constructor
    Library test_library1(my_books);
    Library test_library2(my_books);

    //calls remove function with details as the parameters
    assert(test_library1.remove("Book1", "Author1", "Date1")); //tries removing first 
    assert(test_library1.remove("Book3", "Author3", "Date3")); //general test
    assert(test_library1.remove("Book4", "Author4", "Date4")); //tries removing last
    cout << "Successfully removed specified books by parameter." << endl;

    //calls remove function by details parameters, with a Book that does not exist
    cout << (test_library1.remove("Book10", "Author10", "Date10") ? "Non-existent book was removed" : "Book not found, successfully not removed") << endl << endl;

    //calls remove function with Book as the parameter
    assert(test_library2.remove(my_book1)); //tries removing first 
    assert(test_library2.remove(my_book3)); //general test
    assert(test_library2.remove(my_book4)); //tries removing last
    cout << "Successfully removed specified books by passing Book." << endl;

    //calls remove function with Book as parameter, with a Book not in Library
    cout << (test_library1.remove(my_book9) ? "Non-existent book was removed" : "Book not found, successfully not removed") << endl;
}

void execute_tests() {
    //test_book_insertion1();
    //test_library_constructors();
    //test_library_print();
    test_book_removal();
}

int main() {
    execute_tests();
}