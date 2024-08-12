#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

struct Book {
    int book_id;
    std::string author_name;
    double price;
    int no_of_pages;
    std::string publisher;
    int year_of_publishing;
};

// Function to split a string into tokens based on a delimiter
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to read books from a file
std::vector<Book> readBooks(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        // Skip the header line
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            Book book;
            book.book_id = std::stoi(tokens[0]);
            book.author_name = tokens[1];
            book.price = std::stod(tokens[2]);
            book.no_of_pages = std::stoi(tokens[3]);
            book.publisher = tokens[4];
            book.year_of_publishing = std::stoi(tokens[5]);
            books.push_back(book);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
    return books;
}

// Function to sort books by author name
void sortBooks(std::vector<Book>& books) {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.author_name < b.author_name;
    });
}

// Function to write books to a file
void writeBooks(const std::vector<Book>& books, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "# book_id, author_name, price, no_of_pages, publisher, year_of_publishing\n";
        for (const Book& book : books) {
            file << book.book_id << ", " << book.author_name << ", " << book.price << ", " << book.no_of_pages << ", " << book.publisher << ", " << book.year_of_publishing << "\n";
        }
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}

int main() {
    std::vector<Book> books = readBooks("books.txt");
    sortBooks(books);
    writeBooks(books, "sorted_books.txt");
    return 0;
}
