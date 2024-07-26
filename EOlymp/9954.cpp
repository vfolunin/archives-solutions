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

    vector<int> count(20);
    for (long long i = 1; i < 4e6; i++)
        count[to_string(i * i).size()]++;

    cout << count[size];
}