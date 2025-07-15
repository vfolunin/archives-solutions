class Solution {
public:
    char processStr(string &s, long long index) {
        long long size = 0;
        for (char c : s) {
            if (c == '*')
                size = max(size - 1, 0LL);
            else if (c == '#')
                size *= 2;
            else if (c != '%')
                size++;
        }

        if (index >= size)
            return '.';

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                size++;
            } else if (s[i] == '#') {
                size /= 2;
                if (index >= size)
                    index -= size;
            } else if (s[i] == '%') {
                index = size - 1 - index;
            } else {
                if (index == size - 1)
                    return s[i];
                size--;
            }
        }

        return '.';
    }
};