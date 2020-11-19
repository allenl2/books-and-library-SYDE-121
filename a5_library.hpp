#ifndef SYDE121_A5_LIBRARY_HPP
#define SYDE121_A5_LIBRARY_HPP

#include <vector>
#include "a5_book.hpp"

using namespace std;

class Library {
	vector<Book> my_books;
public:
	//PURPOSE: Default constructor with no parameters, implicitly initializes the library
	Library();

	//PURPOSE: Parametric constructor with a vector of type <Book>, stores all values in the vector in the library
	Library(vector<Book> new_books);

	//PURPOSE: Service function that outputs all the books stored in the library
	void print();

	bool insert(string, string, string);
	bool insert(Book);

	//PURPOSE: Function to remove the Book with specified title, author, and date of publication from the library
	bool remove(string book_title, string book_author, string book_dop);

	//PURPOSE: Function to remove the specified instance of Book from the library
	bool remove(Book book);


};

#endif