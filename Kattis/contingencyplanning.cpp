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

    vector<long long> count = { 1 };
    for (int i = 1; count.back() <= 1e9; i++)
        count.push_back(count.back() * i + 1);

    if (size < count.size() && count[size] - 1 <= 1e9)
        cout << count[size] - 1;
    else
        cout << "JUST RUN!!";
}