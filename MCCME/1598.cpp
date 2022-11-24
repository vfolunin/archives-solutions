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

    bool first = 1;
    string word;
    while (cin >> word) {
        if (first)
            first = 0;
        else
            cout << " ";
        cout << word;
    }
}