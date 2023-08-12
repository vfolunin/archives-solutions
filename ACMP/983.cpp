#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Person {
	int steps, stepTime, index;
	long long time;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int personCount;
	cin >> personCount;

	vector<Person> persons(personCount);
	for (int i = 0; i < personCount; i++) {
		cin >> persons[i].stepTime >> persons[i].steps;
		persons[i].index = i;
		persons[i].time = 1LL * persons[i].steps * persons[i].stepTime;
	}

	sort(persons.begin(), persons.end(), [](Person &a, Person &b) {
		return a.steps < b.steps;
	});

	for (int i = 1; i < personCount; i++)
		persons[i].time = max(persons[i].time, persons[i - 1].time);

	sort(persons.begin(), persons.end(), [](Person &a, Person &b) {
		return a.index < b.index;
	});

	for (Person &person : persons)
		cout << person.time << "\n";
}