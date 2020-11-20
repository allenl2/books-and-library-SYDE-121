#include "a5_library.hpp"

Library::Library() {
	//Reserves 100 spaces in memory for the vector if nothing is specified
	my_books.reserve(100);
}

Library::Library(vector<Book> new_books) :
	my_books(new_books) {}

bool Library::insert(string new_title, string new_authors, string new_dop) {
	// TODO: write steps for the insert function
	Book insert_book(new_title, new_authors, new_dop);
	// iterate through the vector to see if that book already exists
	// if it does not exist, insert it into the vector
	my_books.push_back(insert_book);

	return false;
}

bool Library::insert(Book new_book) {
	// TODO: write steps for the insert function

	// iterate through the vector to see if that book already exists
	if (my_books[0].get_title() == new_book.get_title() &&
		my_books[0].get_authors() == new_book.get_authors() &&
		my_books[0].get_dop() == new_book.get_dop())
	// if it does not exist, insert it into the vector
	my_books.push_back(new_book);

	my_books[0].print();
	return true;
}

bool Library::remove(string book_title, string book_author, string book_dop) {
	//iterates through all Books in the vector
	for (int i = 0; i < my_books.size(); i++) {

		Book current_book = my_books.at(i);

		//checks to see if the current book matches the specified parameters from the function call, removes the Book if all three match and return true
		if (current_book.get_title() == book_title &&
			current_book.get_authors() == book_author &&
			current_book.get_dop() == book_dop) {

			my_books.erase(my_books.begin() + i);
			return true;
		}
	}
	//if no match is found, then return false
	return false;
}

bool Library::remove(Book book) {
	//iterates through all Books in the vector
	for (int i = 0; i < my_books.size(); i++) {

		Book current_book = my_books.at(i);

		//checks to see if the current book has same details as the specified Book in the function call, removes the Book if a match is found and returns true
		if (current_book.get_title() == book.get_title() &&
			current_book.get_authors() == book.get_authors() &&
			current_book.get_dop() == book.get_dop()) {

			my_books.erase(my_books.begin() + i);
			return true;
		}
	}
	//if no match is found, return false
	return false;
}

void Library::print() {
	//iterates through the entire vector of Books, outputs the details of each to console
	for (int i = 0; i < my_books.size(); i++) {
		cout << "(" << i + 1 << ") ";
		my_books.at(i).print();
	}
}