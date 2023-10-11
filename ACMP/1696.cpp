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

    int size, drawCount;
    cin >> size >> drawCount;

    map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    int i = 0;
    for (auto it = count.begin(); it != count.end() && i < drawCount; it++, i++) {
        cout << it->first << " ";
        it->second--;
    }
    for (auto it = count.begin(); it != count.end() && i < drawCount; it++)
        for (int j = 0; j < it->second && i < drawCount; j++, i++)
            cout << it->first << " ";
}