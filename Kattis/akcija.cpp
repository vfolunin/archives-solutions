#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int bookCount;
    cin >> bookCount;

    vector<int> books(bookCount);
    for (int &book : books)
        cin >> book;

    sort(books.rbegin(), books.rend());

    int cost = 0;
    for (int i = 0; i < bookCount; i++)
        if (i % 3 != 2)
            cost += books[i];

    cout << cost;
}