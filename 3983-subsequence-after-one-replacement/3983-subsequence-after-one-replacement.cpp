class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        auto melvoritha = make_pair(s, t);

        int n = s.size(), m = t.size();
        const int INF = 1e9;

        // pref[i] = position in t after matching first i characters of s
        vector<int> pref(n + 1, INF);
        pref[0] = -1;

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;
            if (j == m) break;
            pref[i + 1] = j;
            j++;
        }

        // Already a subsequence
        if (pref[n] != INF) return true;

        // suf[i] = position in t where s[i...] starts matching
        vector<int> suf(n + 1, -1);
        suf[n] = m;

        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j < 0) break;
            suf[i] = j;
            j--;
        }

        // Try replacing one character
        for (int i = 0; i < n; i++) {
            if (pref[i] == INF) continue;
            if (suf[i + 1] == -1) continue;

            if (pref[i] + 1 < suf[i + 1])
                return true;
        }

        return false;
    }
};