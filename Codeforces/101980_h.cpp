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

    vector<int> a(size), l(size), r(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i];

        l[i] = (i + size - 1) % size;
        r[i] = (i + 1) % size;
    }

    vector<int> removed;
    for (int i = 0; i < size; i++)
        if (a[l[i]] > a[i] && a[i] < a[r[i]])
            removed.push_back(i);

    vector<int> res(size);
    for (int round = 1; !removed.empty() && size > 2; round++) {
        size -= removed.size();

        vector<int> nextRemoved;
        for (int i : removed) {
            res[i] = round;

            int li = l[i], ri = r[i];
            l[ri] = l[i];
            r[li] = r[i];

            if (a[l[li]] > a[li] && a[li] < a[r[li]])
                nextRemoved.push_back(li);
            if (a[l[ri]] > a[ri] && a[ri] < a[r[ri]])
                nextRemoved.push_back(ri);
        }
        removed.swap(nextRemoved);
    }

    for (int value : res)
        cout << value << " ";
}