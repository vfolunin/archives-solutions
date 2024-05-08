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

    long long res = 0;
    for (int l = 0, r = a.size() - 1; l < r; ) {
        res = max(res, 1LL * (r - l) * min(a[l], a[r]));

        if (a[l] < a[r])
            l++;
        else
            r--;
    }

    cout << res;
}