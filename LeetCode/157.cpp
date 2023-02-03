class Solution {
public:
    int read(char *buf, int targetCount) {
        char buf4[4];
        int bufIndex = 0, totalReadCount = 0;

        while (targetCount) {
            int readCount = read4(buf4);
            for (int i = 0; i < readCount && targetCount; i++, targetCount--)
                buf[bufIndex++] = buf4[i];
            totalReadCount += readCount;
            if (readCount < 4)
                break;
        }

        buf[bufIndex] = 0;
        return totalReadCount;
    }
};