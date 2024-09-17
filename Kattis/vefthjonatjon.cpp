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

    int size;
    cin >> size;

    vector<int> count(3);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            char c;
            cin >> c;
            count[j] += c == 'J';
        }
    }

    cout << *min_element(count.begin(), count.end());
}