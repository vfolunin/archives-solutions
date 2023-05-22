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

    vector<int> count(11);
    double sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
        sum += value;
    }

    for (int value = 1; value < count.size(); value++)
        for (int i = 0; i < count[value]; i++)
            cout << value << " ";

    cout.precision(3);
    cout << "\n" << fixed << sum / size;
}