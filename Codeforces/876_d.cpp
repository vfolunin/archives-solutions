#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size;
    cin >> size;

    cout << "1 ";

    unordered_set<int> onePos;
    int lastPos = size;

    for (int i = 0; i < size; i++) {
        int pos;
        cin >> pos;

        onePos.insert(pos);
        while (onePos.count(lastPos))
            onePos.erase(lastPos--);

        cout << onePos.size() + 1 << " ";
    }
}