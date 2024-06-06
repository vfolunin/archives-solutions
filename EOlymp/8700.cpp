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
    for (int value; cin >> value && value; )
        count[value]++;

    int value = max_element(count.begin(), count.end()) - count.begin();

    cout << value << "\n" << count[value];
}