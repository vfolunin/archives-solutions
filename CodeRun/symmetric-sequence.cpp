#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(vector<int> &a, int l, int r) {
    for (; l < r; l++, r--)
        if (a[l] != a[r])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = 0;
    while (!isPalindrome(a, res, a.size() - 1))
        res++;

    cout << res << "\n";
    for (int i = res - 1; i >= 0; i--)
        cout << a[i] << " ";
}