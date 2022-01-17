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

    int cardCount, targetCard, setCount;
    cin >> cardCount >> targetCard >> setCount;

    for (int i = 0; i < setCount; i++) {
        int setSize;
        cin >> setSize;

        vector<int> set(setSize);
        for (int &card : set)
            cin >> card;

        cout << (count(set.begin(), set.end(), targetCard) ? "KEEP\n" : "REMOVE\n");
    }
}