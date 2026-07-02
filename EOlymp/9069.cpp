#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    vector<int> count;
    int negativeCount = 0;

    Counter() : count(26) {}

    void add(int value, int delta) {
        negativeCount -= count[value] < 0;
        count[value] += delta;
        negativeCount += count[value] < 0;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    string a, b;
    cin >> size >> a >> b;

    if (a.size() < size || b.size() < size) {
        cout << "NO";
        return 0;
    }

    Counter counter;
    for (char c : b)
        counter.add(c - 'a', 1);

    for (int i = 0; i < size; i++)
        counter.add(a[i] - 'a', -1);

    if (!counter.negativeCount) {
        cout << "YES";
        return 0;
    }

    for (int i = size; i < a.size(); i++) {
        counter.add(a[i - size] - 'a', 1);
        counter.add(a[i] - 'a', -1);

        if (!counter.negativeCount) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}