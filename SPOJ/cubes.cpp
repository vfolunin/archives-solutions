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

	for (int sum = 6; sum <= 100; sum++)
		for (int a = 2; a <= sum; a++)
			for (int b = a + 1; b <= sum; b++)
				for (int c = b + 1; c <= sum; c++)
					if (sum * sum * sum == a * a * a + b * b * b + c * c * c)
						cout << "Cube = " << sum << ", Triple = (" << a << "," << b << "," << c << ")\n";
}