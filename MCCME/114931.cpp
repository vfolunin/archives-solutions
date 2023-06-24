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

    long long a, b, n, c;
	cin >> a >> b >> n >> c;
	
	long long ratio = n / (c + 1), remainder = n % (c + 1);
	cout << min(a * c, b * (c + 1)) * ratio + min(a, b) * remainder;
}