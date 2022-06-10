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
    int dayOfYear(string s) {
        Date b(s);
        Date a(b.y, 1, 1);
        
        int res = 1;
        while (a < b) {
            a++;
            res++;
        }
        
        return res;
    }
};