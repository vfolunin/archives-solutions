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

    vector<int> count(26);

    char c;
    while (cin >> c)
        if (isalpha(c))
            count[tolower(c) - 'a']++;

    for (int value : count)
        cout << value << " ";
}