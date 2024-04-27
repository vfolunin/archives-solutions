long long solve(int h, int w, int) {
    long long res = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res += getValue(y + 1, x + 1);
    return res;
}