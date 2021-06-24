#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;

    bool operator < (const Book &that) const {
        if (author != that.author)
            return author < that.author;
        return title < that.title;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    set<Book> books, taken, shelf;
    map<string, string> authorOf;

    while (1) {
        string line;
        getline(cin, line);

        if (line == "END")
            break;

        int q = line.find("\"", line.find("\"") + 1);
        string title = line.substr(0, q + 1);
        string author = line.substr(q + 3);

        books.insert({ title, author });
        authorOf[title] = author;
    }

    while (1) {
        string type;
        cin >> type;

        if (type == "END")
            break;

        if (type == "SHELVE") {
            for (auto &[title, author] : shelf) {
                auto [it, _] = books.insert({ title, author });
                cout << "Put " << title << " ";
                if (it == books.begin())
                    cout << "first\n";
                else
                    cout << "after " << (--it)->title << "\n";
            }
            cout << "END\n";
            shelf.clear();
            continue;
        }

        cin.ignore();
        string title;
        getline(cin, title);

        if (type == "BORROW") {
            books.erase({ title, authorOf[title] });
            taken.insert({ title, authorOf[title] });
        } else {
            taken.erase({ title, authorOf[title] });
            shelf.insert({ title, authorOf[title] });
        }
    }
}