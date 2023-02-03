class Solution {
public:
    bool validWordAbbreviation(string &s, string &a) {
        stringstream ss(s), as(a);
        while (as.peek() != EOF) {
            if (isalpha(as.peek())) {
                if (ss.get() != as.get())
                    return 0;
            } else if (as.peek() == '0') {
                return 0;
            } else {
                int count;
                as >> count;
                for (int i = 0; i < count; i++)
                    if (ss.get() == EOF)
                        return 0;
            }
        }
        return ss.peek() == EOF;
    }
};