#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isAvailable;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isAvailable = true;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added successfully: " << book.title << endl;
    }

    void removeBook(int bookId) {
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].id == bookId) {
                cout << "Book removed successfully: " << books[i].title << endl;
                books.erase(books.begin() + i);
                return;
            }
        }
        cout << "Book with ID " << bookId << " not found." << endl;
    }

    void updateBook(int bookId, const string& newTitle, const string& newAuthor) {
        for (Book& book : books) {
            if (book.id == bookId) {
                book.title = newTitle;
                book.author = newAuthor;
                cout << "Book updated successfully: " << bookId << endl;
                return;
            }
        }
        cout << "Book with ID " << bookId << " not found." << endl;
    }

    void borrowBook(int bookId) {
        for (Book& book : books) {
            if (book.id == bookId && book.isAvailable) {
                book.isAvailable = false;
                cout << "Book borrowed successfully: " << book.title << endl;
                return;
            }
        }
        cout << "Book with ID " << bookId << " not available for borrowing." << endl;
    }

    void returnBook(int bookId) {
        for (Book& book : books) {
            if (book.id == bookId && !book.isAvailable) {
                book.isAvailable = true;
                cout << "Book returned successfully: " << book.title << endl;
                return;
            }
        }
        cout << "Book with ID " << bookId << " not found or not borrowed." << endl;
    }

    void displayBooks() {
        cout << "Library Books:" << endl;
        for (const Book& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
        }
    }

    Book* searchBook(int bookId) {
        for (Book& book : books) {
            if (book.id == bookId) {
                cout << "Book found: " << book.title << endl;
                return &book;
            }
        }
        cout << "Book with ID " << bookId << " not found." << endl;
        return nullptr;
    }
};

int main() {
    Library library;
    library.addBook(Book(1, "Breadfast", "Mostafa Amin"));
    library.addBook(Book(2, "Excel", "Ahmed Hamed"));

    library.displayBooks();
    library.borrowBook(1);
    library.returnBook(1);
    library.updateBook(2, "Excel Revised", "Ahmed Hamed");
    library.displayBooks();

    library.searchBook(2);

    library.removeBook(1);
    library.displayBooks();

}
