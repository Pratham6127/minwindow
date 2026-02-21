#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        int left = 0;
        int right = 0;
        vector<int> freq(256, 0);
        int minlen = INT_MAX;
        int start = 0;

        for (char c : t) {
            freq[c]++;
        }

        if (t.size() > s.size()) {
            return "";
        }

        int count = t.size();

        for (int right = 0; right < s.size(); right++) {

            if (freq[s[right]] > 0) {
                count--;
            }
            freq[s[right]]--;

            while (count == 0) {

                if (right - left + 1 < minlen) {
                    minlen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        if (minlen == INT_MAX) {
            return "";
        } else {
            return s.substr(start, minlen);
        }
    }
};

int main() {
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}