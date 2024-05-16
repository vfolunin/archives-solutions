#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Book {
    string title, author;

    friend istream &operator >> (istream &in, Book &b) {
        string s;
        getline(in, s);
        getline(in, b.title);
        getline(in, b.author);
        getline(in, s);
        return in;
    }

    friend ostream &operator << (ostream &out, Book &b) {
        return out << b.title << " by " << b.author;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int bookCount;
    cin >> bookCount;

    unordered_map<int, Book> books;

    for (int i = 0; i < bookCount; i++) {
        int id;
        cin >> id >> books[id];
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int id;
        cin >> id;

        if (books.count(id))
            cout << books[id] << "\n";
        else
            cout << "Book not found\n";
    }
}