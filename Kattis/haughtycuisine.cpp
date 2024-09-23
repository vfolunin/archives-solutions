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
    cin >> size >> size;

    cout << size << "\n";

    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        cout << s << "\n";
    }
}