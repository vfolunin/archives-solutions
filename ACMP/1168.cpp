#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
	string surname;
	int sum = 0;

	bool operator < (const Student &that) const {
		if (sum != that.sum)
			return sum > that.sum;
		return surname > that.surname;
	}

	friend istream &operator >> (istream &in, Student &student) {
		in >> student.surname;
		for (int i = 0; i < 3; i++) {
			int mark;
			in >> mark;
			student.sum += mark;
		}
		return in;
	}

	friend ostream &operator << (ostream &out, Student &student) {
		return out << student.surname << " " << student.sum;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int studentCount, limit;
	cin >> studentCount >> limit;

	vector<Student> students(studentCount);
	for (Student &student : students)
		cin >> student;

	sort(students.begin(), students.end());

	cout << students[limit - 1];
}