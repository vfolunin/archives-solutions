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
 
    vector<int> count(10);

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        count[value]++;
    }

    for (int value = 1; value < count.size(); value++)
        cout << count[value] << " ";
}