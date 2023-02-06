class Solution {
    char buf4[4];
    int buf4Index = 0, read4Count = 0;

public:
    int read(char *buf, int targetCount) {
        int bufIndex = 0;
        for ( ; buf4Index < read4Count && targetCount; targetCount--)
            buf[bufIndex++] = buf4[buf4Index++];

        while (targetCount) {
            read4Count = read4(buf4);
            for (buf4Index = 0; buf4Index < read4Count && targetCount; targetCount--)
                buf[bufIndex++] = buf4[buf4Index++];
            if (read4Count < 4)
                break;
        }

        buf[bufIndex] = 0;
        return bufIndex;
    }
};