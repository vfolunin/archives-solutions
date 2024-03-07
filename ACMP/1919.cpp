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
    long long sum = 0;

    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    for (int value : a)
        if (value != sum / 2)
            cout << value << " ";
    cout << sum / 2;
}