#include "MyLibrary.h"
#include <cstdlib> 
#include <ctime>   
#include <cstring>
#include <cstdarg> 
#include <iostream> 

MyLibrary::~MyLibrary() {
    delete[] books; 
}

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream), books_count(-1), books(nullptr) {}


MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books_ids) : output_stream(output_stream), books_count(books_count) {
    books = new int[books_count]; 
    memcpy(books, books_ids, books_count * sizeof(int));
}
/*
MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values)
    : output_stream(output_stream), books_count(0) {
    const char* p = books_values;
    if (*p) books_count = 1;
    while (*p) {
        if (*p == ';') books_count++;
        p++;
    }

    books = new int[books_count];
    int index = 0;
    int currentID = 0;
    while (*books_values) {
        if (*books_values >= '0' && *books_values <= '9') {
            currentID = currentID * 10 + (*books_values - '0');
        }
        else if (*books_values == ';' || *(books_values + 1) == '\0') {
            if (*(books_values + 1) == '\0' && *books_values != ';') {
                currentID = currentID * 10 + (*books_values - '0');
            }
            books[index++] = currentID;
            currentID = 0;
        }
        books_values++;
    }
}*/


MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream), books_count(books_count) {
    books = new int[books_count];
    srand(static_cast<unsigned>(time(nullptr)));
    for (unsigned i = 0; i < books_count; ++i) {
        books[i] = min + rand() % (max - min); 
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream), books_count(books_count) {
    va_list args;
    va_start(args, books_count);
    books = new int[books_count];
    for (unsigned i = 0; i < books_count; ++i) {
        books[i] = va_arg(args, int);
    }
    va_end(args);
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(std::cout), books_count(static_cast<unsigned>(v.size())) {
    books = new int[books_count];
    unsigned i = 0;
    for (int book_id : v) {
        books[i++] = book_id;
    }
}


void MyLibrary::print_books() {
    if (books_count == static_cast<unsigned>(-1)) {
        output_stream << "Found -1 books" << std::endl;
    }
    else {
        output_stream << "Found " << books_count << " books";
        for (unsigned i = 0; i < books_count; ++i) {
            output_stream << " " << books[i];
        }
        output_stream << std::endl;
    }
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (book_index < books_count) {
        books[book_index] = book_id;
    }
}

unsigned MyLibrary::get_books_count() const {
    return books_count;
}

int MyLibrary::get_book_id_by_index(unsigned index) const {
    if (index < books_count) {
        return books[index];
    }
    return -1; //eroare
}