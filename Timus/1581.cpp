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
    
    vector<pair<int, int>> parts;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (parts.empty() || parts.back().second != value)
            parts.push_back({ 1, value });
        else
            parts.back().first++;
    }

    for (auto &[count, value] : parts)
        cout << count << " " << value << " ";
}