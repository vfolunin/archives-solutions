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

    vector<int> book(bookCount);
    long long bookSum = 0, bookMax = 0;
    for (int &b : book) {
        cin >> b;
        bookSum += b;
        bookMax = max<long long>(bookMax, b);
    }
    
    if (bookSum - bookMax <= bookMax)
        cout << bookMax * 2;
    else
        cout << bookSum;
}