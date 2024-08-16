#include <iostream>
#include <string>

using namespace std;

class Book  {
public:
  
  string author;
  int number_pages;
  Book(const string& aut = "Erich Maria Remarque", int n = 597) : author(aut), number_pages(n){};
};

ostream& operator<< (ostream& os, Book book) {
  cout << "Author: " << book.author << "\nNumber of pages: " << book.number_pages << endl;
  return os;
}
