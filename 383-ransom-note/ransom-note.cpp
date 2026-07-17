class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counts;

        // Count frequencies of characters in magazine
        for (char c : magazine) {
            counts[c]++;
        }

        // Match and decrement frequencies using ransomNote
        for (char c : ransomNote) {
            if (counts[c] <= 0) {
                return false; // Not enough characters available
            }
            counts[c]--;
        }

        return true;
    }
};
