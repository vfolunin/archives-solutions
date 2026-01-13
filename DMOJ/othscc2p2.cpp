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

    int limit, size;
    cin >> limit >> size;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value >= limit) {
            cout << "fight";
            return 0;
        }
    }

    cout << "run away";
}