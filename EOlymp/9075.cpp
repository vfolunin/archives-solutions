double solve(point a, point b, point c) {
    double abx = b.x - a.x, aby = b.y - a.y;
    double acx = c.x - a.x, acy = c.y - a.y;
    return abs(abx * acy - acx * aby) / 2;
}