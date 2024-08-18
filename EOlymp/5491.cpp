#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char rec(vector<long long> size, int i, int index) {
    if (!i)
        return !index ? 'm' : 'o';

    if (index < size[i - 1])
        return rec(size, i - 1, index);
    else if (index < size[i - 1] + i + 3)
        return index == size[i - 1] ? 'm' : 'o';
    else
        return rec(size, i - 1, index - size[i - 1] - i - 3);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int index;
    cin >> index;
    index--;

    vector<long long> size = { 3 };
    for (int i = 1; size.back() <= index; i++)
        size.push_back(size[i - 1] * 2 + i + 3);

    cout << rec(size, size.size() - 1, index);
}