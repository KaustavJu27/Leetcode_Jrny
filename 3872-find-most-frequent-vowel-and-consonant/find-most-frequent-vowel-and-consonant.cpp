class Solution {
public:
    int maxFreqSum(string s) {

        // Arrays sized 26 to safely fit all lowercase English characters
        vector<int> freq_vowel(26, 0);
        vector<int> freq_consonant(26, 0);

        for (int i = 0; i < s.size(); i++) {
            // Subtract 'a' to map character indices from 0 to 25
            int idx = s[i] - 'a';

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                freq_vowel[idx]++;
            } else {
                freq_consonant[idx]++;
            }
        }

        int max1 = -1; // Fixed broken string syntax
        for (int i = 0; i < freq_vowel.size(); i++) {
            max1 = max(max1, freq_vowel[i]);
        }

        int max2 = -1; // Fixed broken string syntax
        for (int i = 0; i < freq_consonant.size(); i++) {
            max2 = max(max2, freq_consonant[i]);
        }

        return max1 + max2;
    }
};
