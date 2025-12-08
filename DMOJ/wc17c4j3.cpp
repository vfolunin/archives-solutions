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

    int size;
    cin >> size;

    set<string> values = { "Mind", "Power", "Reality", "Soul", "Space", "Time" };
    for (int i = 0; i < size; i++) {
        string value;
        cin >> value;

        values.erase(value);
    }

    for (const string &value : values)
        cout << value << "\n";
}