bool f(int n) {
    int root = 0;
    while (root * root < n)
        root++;
    return root * root == n;
}