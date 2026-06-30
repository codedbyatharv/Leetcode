class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {

        // Rook attacks horizontally
        if (a == e) {
            if (!(c == a && min(b, f) < d && d < max(b, f)))
                return 1;
        }

        // Rook attacks vertically
        if (b == f) {
            if (!(d == b && min(a, e) < c && c < max(a, e)))
                return 1;
        }

        // Bishop attacks diagonally
        if (abs(c - e) == abs(d - f)) {

            bool blocked = false;

            if (abs(a - c) == abs(b - d) &&
                min(c, e) < a && a < max(c, e) &&
                min(d, f) < b && b < max(d, f))
                blocked = true;

            if (!blocked)
                return 1;
        }

        return 2;
    }
};