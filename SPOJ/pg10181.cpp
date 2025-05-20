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

    map<int, int> count;

    for (int i = 0; i < 2; i++) {
        int size;
        cin >> size;

        for (int j = 0; j < size; j++) {
            int value;
            cin >> value;

            count[value]++;
        }
    }

    for (map<int, int>::iterator it = count.begin(); it != count.end(); it++)
        if (it->second == 2)
            cout << it->first << " ";
}