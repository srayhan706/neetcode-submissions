class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0);
        vector<int> window(26, 0);

        for (char c : s1) {
            s1Count[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {

            window[s2[right] - 'a']++;

            // keep window size equal to s1 length
            if (right - left + 1 > s1.size()) {
                window[s2[left] - 'a']--;
                left++;
            }

            if (window == s1Count) {
                return true;
            }
        }

        return false;
    }
};