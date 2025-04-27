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

    int pageSize, rowSize, wordCount;
    cin >> pageSize >> rowSize >> wordCount;

    int rowCount = 1, curRowSize = 0;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        curRowSize += (curRowSize > 0) + word.size();
        if (curRowSize > rowSize) {
            rowCount++;
            curRowSize = word.size();
        }
    }

    cout << (rowCount + pageSize - 1) / pageSize;
}