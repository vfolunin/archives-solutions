#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

template<typename T>
unordered_set<T> read() {
    unordered_set<T> values;
    for (T value; cin.peek() != '\n'; ) {
        cin >> value;
        values.insert(value);
    }
    cin.ignore();
    return values;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    cin.ignore();

    unordered_set<char> lettersFrom = read<char>();
    unordered_set<int> positions = read<int>();

    char letterTo;
    cin >> letterTo;

    for (int i = 0; i < s.size(); i++)
        if (lettersFrom.count(s[i]) && !positions.count(i))
            s[i] = letterTo;

    cout << s;
}