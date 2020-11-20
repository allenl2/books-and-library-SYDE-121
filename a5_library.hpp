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

	//PURPOSE: Function to insert an instance of 'Book' with specified title, author, and date of publication into the library. Returns true if a Book is inserted, false if a duplicate is found.
	bool insert(string, string, string);

	//PURPOSE: Function to insert an instance of 'Book' into the library. Returns true if a Book is inserted, false if a duplicate is found.
	bool insert(Book);

	//PURPOSE: Function to remove an instance of 'Book' with specified title, author, and date of publication from the library. Returns true if a Book is removed, false if not.
	bool remove(string book_title, string book_author, string book_dop);

	//PURPOSE: Function to remove the specified instance of Book from the library. Returns true if a Book is removed, false if not.
	bool remove(Book book);
};

#endif