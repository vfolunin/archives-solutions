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

    for (int value : a) {
        int count = 0;
        for (int divisor : a)
            count += value % divisor == 0;

        if (count == 1)
            cout << value << " ";
    }
}