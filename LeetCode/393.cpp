class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int i = 0;
        while (i < data.size()) {
            if ((data[i] & 0x80) == 0x00)
                i++;
            else if ((data[i] & 0xe0) == 0xc0 && i + 1 < data.size() &&
                     (data[i + 1] & 0xc0) == 0x80)
                i += 2;
            else if ((data[i] & 0xf0) == 0xe0 && i + 2 < data.size() &&
                     (data[i + 1] & 0xc0) == 0x80 && (data[i + 2] & 0xc0) == 0x80)
                i += 3;
            else if ((data[i] & 0xf8) == 0xf0 && i + 3 < data.size() &&
                     (data[i + 1] & 0xc0) == 0x80 && (data[i + 2] & 0xc0) == 0x80 && (data[i + 3] & 0xc0) == 0x80)
                i += 4;
            else
                return 0;
        }
        return 1;
    }
};