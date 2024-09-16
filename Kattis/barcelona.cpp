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

    int size, targetValue;
    cin >> size >> targetValue;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value == targetValue) {
            if (i == 0)
                cout << "fyrst";
            else if (i == 1)
                cout << "naestfyrst";
            else
                cout << i + 1 << " fyrst";
            break;
        }
    }
}