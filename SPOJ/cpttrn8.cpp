#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w, size;
    cin >> h >> w >> size;

    for (int y = 0; y < h; y++) {
        for (int i = 0; i < 2; i++) {
            for (int ii = 0; ii < size; ii++) {
                for (int x = 0; x < w; x++) {
                    for (int j = 0; j < 2; j++) {
                        for (int jj = 0; jj < size; jj++) {
                            if (!i) {
                                if (!j) {
                                    if (ii + jj == size - 1)
                                        cout << "/";
                                    else if (ii + jj > size - 1)
                                        cout << "*";
                                    else
                                        cout << ".";
                                } else {
                                    if (ii == jj)
                                        cout << "\\";
                                    else if (ii > jj)
                                        cout << "*";
                                    else
                                        cout << ".";
                                }
                            } else {
                                if (!j) {
                                    if (ii == jj)
                                        cout << "\\";
                                    else if (ii < jj)
                                        cout << "*";
                                    else
                                        cout << ".";
                                } else {
                                    if (ii + jj == size - 1)
                                        cout << "/";
                                    else if (ii + jj < size - 1)
                                        cout << "*";
                                    else
                                        cout << ".";
                                }
                            }
                        }
                    }
                }
                cout << "\n";
            }
        }
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}