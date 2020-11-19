#include "a5_library.hpp"

Library::Library() {}

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

bool Library::remove(Book new_book) {
	// TODO: write steps for the remove function

	// find the location for the entered book
	// swap that location with the last location in the vector
	// remove the last element in the vector
	swap(my_books[2], my_books[5]);
	my_books.pop_back();

	my_books.erase(my_books.begin() + 5);

	return true;
}

void Library::print() {
	// iterate through elements of the library
		// call my_books[index].print(); on each book
}

