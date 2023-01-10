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

    vector<long long> fib(size);
    fib[0] = fib[1] = 1;
    for (int i = 2; i < size; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    for (long long &value : fib)
        cout << value << " ";
}