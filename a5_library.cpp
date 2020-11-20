#include "a5_library.hpp"

Library::Library() {
	//Reserves 100 spaces in memory for the vector if nothing is specified
	my_books.reserve(100);
}

Library::Library(vector<Book> new_books) :
	my_books(new_books) {}

bool Library::insert(string new_title, string new_authors, string new_dop) {

	Book new_book(new_title, new_authors, new_dop);

	// iterates through books in vector for comparison 	
	for (int index = 0; index < my_books.size(); index++) {
		// checks to see if a book matching those in parameters exists; if so, new book cannot be inserted and false is returned
		if (my_books[index].get_title() == new_title &&
			my_books[index].get_authors() == new_authors &&
			my_books[index].get_dop() == new_dop) {

			//cout << "Insertion failed. A book with these details already exists in Library:" << endl;
			//my_books[index].print();
			return false;
		}
	}
	// if book with matching attributes does not already exist, insert it into the vector & return true
	my_books.push_back(new_book);
	//cout << "Thank you, the following book was inserted into Library:" << endl;
	//new_book.print();
	return true;
}

bool Library::insert(Book new_book) {

	// iterates through books in vector for comparison 	
	for (int index = 0; index < my_books.size(); index++) {
		// checks to see if a book matching those in parameters exists; if so, new book cannot be inserted and false is returned
		if (my_books[index].get_title() == new_book.get_title() &&
			my_books[index].get_authors() == new_book.get_authors() &&
			my_books[index].get_dop() == new_book.get_dop()) {

			//cout << "Insertion failed. A book with these details already exists in Library." << endl;
			//my_books[index].print();
			return false;
		}
	}
	
	// if book with matching attributes does not already exist, insert it into the vector & return true
	my_books.push_back(new_book);
	//cout << "Thank you, the following book was inserted into Library:" << endl;
	//new_book.print();
	return true;
}

bool Library::remove(string book_title, string book_author, string book_dop) {
	Book remove_book(book_title, book_author, book_dop);
	return remove(remove_book);

	/*//iterates through all Books in the vector
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
	return false;*/
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