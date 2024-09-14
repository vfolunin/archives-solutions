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

    string letters;
    getline(cin, letters);

    string indexes;
    cin >> indexes;

    for (int i = 0; i < indexes.size(); i += 3)
        cout << letters[stoi(indexes.substr(i, 3)) - 1];
}