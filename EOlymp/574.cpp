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

    int size, limit;
    cin >> size >> limit;

    map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    for (auto it = count.rbegin(); it != count.rend(); it++)
        if (it->second <= limit)
            for (int i = 0; i < it->second; i++)
                cout << it->first << " ";
}