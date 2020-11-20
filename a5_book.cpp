#include "a5_book.hpp"

Book::Book() :  // default, all attributes set to n/a 
	book_title("n/a"),
	book_authors("n/a"),
	date_of_publication("n/a") {}

Book::Book(string new_title) : // only title is provided, authors & date of publication are n/a
	book_title(new_title),
	book_authors("n/a"),
	date_of_publication("n/a") {}

Book::Book(string new_title, string new_authors) : // only title & authors provided, date of publication is n/a
	book_title(new_title),
	book_authors(new_authors),
	date_of_publication("n/a") {}

Book::Book(string new_title, string new_authors, string new_dop) : // all attributes specified
	book_title(new_title),
	book_authors(new_authors),
	date_of_publication(new_dop) {}

void Book::print() { // prints the current values stored inside book object
	cout << "Title: " << book_title << endl;
	cout << "Author(s): " << book_authors << endl;
	cout << "Publication Date: " << date_of_publication << endl;
}

string Book::get_title() {
	return book_title;
}

string Book::get_authors() {
	return book_authors;
}

string Book::get_dop() {
	return date_of_publication;
}
