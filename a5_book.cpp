#include "a5_book.hpp"

Book::Book(string new_title, string new_authors, string new_dop) :
	book_title(new_title),
	book_authors(new_authors),
	date_of_publication(new_dop) {}

void Book::print() {
	cout << book_title << " "
		<< book_authors << " "
		<< date_of_publication << endl;
}
