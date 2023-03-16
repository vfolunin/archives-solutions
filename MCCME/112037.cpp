#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    cin.get();

    unordered_map<string, int> count;
    for (int i = 0; i < size; i++) {
        string line;
        getline(cin, line);

        string value;
        for (char c : line)
            if (isdigit(c))
                value += c;

        count[value]++;
    }

    vector<string> res;
    for (auto &[value, count] : count)
        if (count <= 5)
            res.push_back(value);

    cout << res.size() << "\n";
    for (string value : res)
        cout << value << "\n";
}