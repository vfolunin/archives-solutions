#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long size;
    cin >> size;

    cout << "?";
    for (int i = 0; i < size; i++)
        cout << " " << i;
    cout << endl;

    long long sum;
    cin >> sum;

    cout << "! " << sum - size * size * (size - 1) / 2 + 1 << endl;
}