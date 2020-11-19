#ifndef SYDE121_A5_LIBRARY_HPP
#define SYDE121_A5_LIBRARY_HPP

#include <vector>
#include "a5_book.hpp"

using namespace std;

class Library {
	vector<Book> my_books;
public:
	// default/empty constructor is included explicitly
	Library();
	Library(vector<Book> new_books);

	bool insert(string, string, string);
	bool insert(Book);

	bool remove(string, string, string);
	bool remove(Book);

	void print();

};
#endif