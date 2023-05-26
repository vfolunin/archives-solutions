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

    string word;
    for (int i = 0; cin >> word; i++) {
        if (i)
            cout << " ";
        cout << "\"" << word << "\"";
    }
}