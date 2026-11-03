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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int count = 0;
    do {
        count++;
    } while (count < 6 && next_permutation(a.begin(), a.end()));

    cout << (count >= 6 ? "Yes" : "No");
}