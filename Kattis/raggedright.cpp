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

    vector<int> lineSize;
    while (1) {
        string line;
        if (!getline(cin, line))
            break;
        lineSize.push_back(line.size());
    }

    int maxSize = *max_element(lineSize.begin(), lineSize.end());
    int penalty = 0;
    for (int i = 0; i + 1 < lineSize.size(); i++)
        penalty += (maxSize - lineSize[i]) * (maxSize - lineSize[i]);

    cout << penalty;
}