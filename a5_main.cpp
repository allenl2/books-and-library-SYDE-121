/* SYDE 121 ASSIGNMENT 5 - Allen Liu & Suhyma Rahman
* Nov 20, 2020
* 
* TESTING SCENARIOS
*  1) Library Print Function - creates several instances of Book, adds them to a vector, then creates an instance of Library using the vector parametric constructor. The print function is then called. The test also outputs the expected values for comparison. Another test is done for an instance of Library that is empty (ie. created with default constructor). The library is printed and expected values (nothing) are also printed.
* 
*  2) Library Constructors - create instances of Library using the vector parametric constructor (once with a vector containing Books, the other with an empty vector), and default constructor. Then prints out each of the libraries for verification.
* 
*  3) Library Removal - creates two instances of Library filled with instances of Books.  It first checks the remove function (by details - title, author, date) by removing the first Book, a general Book, and the last Book. Then checks the same function but with  a title, author, and date that is not correspond to any Book. Then checks the remove   function (by Book) by removing the first Book, a general Book, and the last Book. Then checks the same function but with an instance of Book that is not in the Library. For  each test, output the results to console.
* 
*  5) Library Insertion - creates two instances of Library filled with vectors holding Book instances. First, checks if the insert function works using passed Book attributes in both Library instances. Then, checks insert function with passed Book instances in each Library instance. Next, ensure that a Book already in the Library instance can't be added again. All results from these tests are printed to the console, as well as the final Library instances after new books are inserted. 
* 
*  5) Book Print Function - creates an instance of Book with default constructor, then calls print function in Book, ensuring that all attributes are printed regardless of whether or not they are specified.
* 
*  6) Book Constructors - creates four instances of Book for each constructor, then calls the Book print function for each.  
* 
* LIMITATIONS
* - during the ininitalization of Library, the vector is not checked for duplicates, so they may exist in the final result (this may lead to errors in insert/remove)
* - does not consider that different books may be entered without any attributes (n/a); for insertion, would be considered duplicate books and cannot be added if one already exists (causes program to abort).
*/

#include <iostream>
#include <vector>
#include <cassert>
#include "a5_book.hpp"
#include "a5_library.hpp"

using namespace std;

void test_book_print() {
    Book my_book1;
    my_book1.print();
}

void test_book_constructors() {
    Book my_book1;
    Book my_book2("Book2");
    Book my_book3("Book3", "Author3");
    Book my_book4("Book4", "Author4", "Date4");
    
    cout << "Book 1 - Default constructor: " << endl;
    my_book1.print();
    cout << "Book 2 - Only title provided: " << endl;
    my_book2.print();
    cout << "Book 3 - Only title & author provided: " << endl;
    my_book3.print();
    cout << "Book 4 - All attributes provided: " << endl;
    my_book4.print();
}

void test_book_insertion() {
    // setup by creating some books and a Library vector
    vector <Book> my_books;
    Book my_book1("Title1", "Author1", "Date1");
    Book my_book2("Title2", "Author2", "Date2");
    Book my_book3("Title3", "Author3", "Date3");
    Book my_book4("Title4", "Author4", "Date4");
    Book my_book5("Title5", "Author5", "Date5");

    // add some books into Library vector
    my_books.push_back(my_book1);
    my_books.push_back(my_book2);
    my_books.push_back(my_book3);

    // add vector into different instances of Library
    Library test_library1(my_books);
    Library test_library2(my_books);

    // test scenario: insert using string attributes
    assert(test_library1.insert("Title4", "Author4", "Date4"));
    assert(test_library1.insert("Title5", "Author5", "Date5"));
    cout << "New books were successfully inserted by passing string attributes." << endl;

    // test scenario: insert using Book instances
    assert(test_library2.insert(my_book4)); 
    assert(test_library2.insert(my_book5)); 
    cout << "New books were successfully inserted by passing Book instances." << endl;

    // test scenario: try inserting an existing book using both attributes and Book instance
    cout << (test_library1.insert(my_book1) ? "Duplicate book added to library" : "Could not add duplicate book to library") << endl;
    cout << (test_library1.insert("Title2", "Author2", "Date2") ? "Duplicate book added to library" : "Could not add duplicate book to library") << endl;
  
    cout << "Library 1:" << endl;
    test_library1.print();

    cout << "Library 2:" << endl;
    test_library2.print();

    // teardown
    // automatic destruction (freeing of memory) of these objects
}

void test_library_constructors() {
    //creates some books
    Book test_book1("Book1", "Author1", "Date1");
    Book test_book2("Book2", "Author2", "Date2");
    Book test_book3("Book3", "Author3", "Date3");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books1;
    my_books1.push_back(test_book1);
    my_books1.push_back(test_book2);
    my_books1.push_back(test_book3);

    //an empty vector to test
    vector<Book> my_books2;

    //creates instances of Library using both constructors
    Library test_library1(my_books1);
    Library test_library2(my_books2);
    Library test_library3;

    //prints out the each instance of library to check results
    cout << "Library 1 Test (Vector): " << endl;
    test_library1.print();

    cout << "Library 2 Test (Empty Vector): " << endl;
    test_library2.print();

    cout << "Library 3 Test (Default): " << endl;
    test_library3.print();
}

void test_library_print() {
    //creates some books
    Book my_book1("Book1", "Author1", "Date1");
    Book my_book2("Book2", "Author2", "Date2");

    //creates a vector and fills it with instances of Book
    vector<Book> my_books1;
    my_books1.push_back(my_book2);
    my_books1.push_back(my_book1);

    //creates an instance of Library using the vector parametric and default constructors
    Library test_library1(my_books1);
    Library test_library2;

    //expected output
    cout << "Test 1 Expected Output:" << endl;
    cout << "(1) " << endl;  my_book2.print();    
    cout << endl <<"(2) " << endl;  my_book1.print();
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
    //test_book_print();
    //test_book_constructors();
    test_book_insertion();
    //test_library_constructors();
    test_library_print();
    //test_book_removal();
}

int main() {
    execute_tests();
}
