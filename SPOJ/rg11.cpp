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

    map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    vector<int> counts;
    for (map<int, int>::iterator it = count.begin(); it != count.end(); it++)
        counts.push_back(it->second);

    sort(counts.rbegin(), counts.rend());

    for (int i = 0; i < counts.size(); i++)
        cout << counts[i] << " ";
}