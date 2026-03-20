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

    int size, partCount;
    string s;
    cin >> size >> partCount >> s;

    int partSize = s.size() / partCount;

    unordered_map<string, vector<int>> partIndex;
    for (int i = 0; i < partCount; i++) {
        string part;
        cin >> part;

        partIndex[part].push_back(i);
    }

    for (int i = 0; i < size; i += partSize) {
        vector<int> &indices = partIndex[s.substr(i, partSize)];

        cout << indices.back() + 1 << " ";
        indices.pop_back();
    }

}