class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        vector<int> t_freq(128, 0);
        vector<int> window_freq(128, 0);

        // Count required characters from t
        for (char c : t) t_freq[c]++;

        int low = 0;
        int min_len = INT_MAX;
        int start_idx = -1;
        int matched_count = 0; // Number of characters fully matched

        for (int high = 0; high < s.length(); high++) {
            char right_char = s[high];
            window_freq[right_char]++;

            // If the character is needed and we haven't over-contributed to the match
            if (t_freq[right_char] > 0 && window_freq[right_char] <= t_freq[right_char]) {
                matched_count++;
            }

            // Shrink the window from the left as much as possible when a valid window is found
            while (matched_count == t.length()) {
                int current_window_len = high - low + 1;
                
                // Update the minimum window data
                if (current_window_len < min_len) {
                    min_len = current_window_len;
                    start_idx = low;
                }

                char left_char = s[low];
                window_freq[left_char]--;

                // If removing this character breaks our match requirements
                if (t_freq[left_char] > 0 && window_freq[left_char] < t_freq[left_char]) {
                    matched_count--;
                }
                low++;
            }
        }

        return start_idx == -1 ? "" : s.substr(start_idx, min_len);
    }
};
