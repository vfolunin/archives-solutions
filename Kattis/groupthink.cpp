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

    vector<vector<int>> op(size, vector<int>(size));
    for (int i = 0; i < size * size; i++) {
        int ai, bi;
        cin >> ai >> bi >> op[ai][bi];
    }

    bool isAssociative = 1;
    for (int ai = 0; ai < size; ai++)
        for (int bi = 0; bi < size; bi++)
            for (int ci = 0; ci < size; ci++)
                isAssociative &= op[op[ai][bi]][ci] == op[ai][op[bi][ci]];

    int identity = -1;
    for (int ai = 0; ai < size; ai++) {
        bool isIdentity = 1;
        for (int bi = 0; bi < size; bi++)
            isIdentity &= op[ai][bi] == bi && op[bi][ai] == bi;
        if (isIdentity)
            identity = ai;
    }

    bool isInversive = identity != -1;
    for (int ai = 0; ai < size; ai++) {
        bool hasInverse = 0;
        for (int bi = 0; bi < size; bi++)
            hasInverse |= op[ai][bi] == identity;
        isInversive &= hasInverse;
    }

    if (isInversive)
        cout << "group";
    else if (identity != -1)
        cout << "monoid";
    else if (isAssociative)
        cout << "semigroup";
    else
        cout << "magma";
}