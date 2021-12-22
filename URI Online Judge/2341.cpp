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

    int labelCount, typeCount;
    cin >> labelCount >> typeCount;

    vector<int> count(typeCount);
    for (int i = 0; i < labelCount; i++) {
        int type;
        cin >> type;
        count[type - 1]++;
    }

    cout << *min_element(count.begin(), count.end()) << "\n";
}