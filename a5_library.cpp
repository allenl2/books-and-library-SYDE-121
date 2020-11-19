#include "a5_library.hpp"

Library::Library() {
	my_books.reserve(100);
}

Library::Library(vector<Book> new_books) :
	my_books(new_books){
}

void Library::print() {
	for (int i = 0; i < my_books.size(); i++) {
		cout << i + 1 << ") ";
		my_books.at(i).print();
	}
}
