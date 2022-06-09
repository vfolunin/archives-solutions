class Solution {
    struct Date {
        int y, m, d;

        static bool isLeap(int y) {
            return y % 400 == 0 || y % 4 == 0 && y % 100;
        }

        static int daysInMonth(int m, int y) {
            static vector<int> d = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            return d[m] + (m == 2 && isLeap(y));
        }
        
        Date(const string &s) {
            stringstream ss(s);
            char dash;
            ss >> y >> dash >> m >> dash >> d;
        }
        
        Date(int y, int m, int d) : y(y), m(m), d(d) {}

        bool operator < (const Date &that) const {
            if (y != that.y)
                return y < that.y;
            if (m != that.m)
                return m < that.m;
            return d < that.d;
        }

        Date &operator ++(int) {
            d++;
            if (d > daysInMonth(m, y)) {
                d = 1;
                m++;
                if (m > 12) {
                    m = 1;
                    y++;
                }
            }
            return *this;
        }
    };
    
public:
    string dayOfTheWeek(int day, int month, int year) {
        Date a(1971, 1, 1);
        Date b(year, month, day);
        
        int res = 5;
        while (a < b) {
            a++;
            res++;
        }
        
        static vector<string> days = {
            "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
        };
        return days[res % 7];
    }
};