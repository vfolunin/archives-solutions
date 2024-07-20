#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getFib() {
    vector<long long> res = { 1, 1 };
    for (int i = 2; res.size() < 40; i++)
        res.push_back(res[i - 2] + res[i - 1]);
    return res;
}

char getChar(int level, int index) {
    if (level <= 1)
        return 'b' - level;

    static vector<long long> fib = getFib();
    if (index < fib[level - 1])
        return getChar(level - 1, index);
    else
        return getChar(level - 2, index - fib[level - 1]);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int level, index, size;
    cin >> level >> index >> size;
    level--;
    index--;

    static vector<long long> fib = getFib();

    for (int i = 0; i < size && index + i < fib[level]; i++)
        cout << getChar(level, index + i);
}