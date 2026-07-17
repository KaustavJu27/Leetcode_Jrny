class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> mp;

        // Correct: Accurately counts frequencies of all characters
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        bool odd = false;
        int res = 0;

        for (auto i : mp) {
            int val = i.second;

            if (val % 2 == 0) {
                res += val; // Correct: Even numbers can completely form pairs
            } else {
                odd = true; // BUG: You set the flag, but you discard the even
                            // pairs hidden inside the odd number here (e.g., if
                            // val is 3, you should add 2 to res right now, but
                            // you add 0).
            }
        }

        // BUG: If there are no odd numbers, you return correctly.
        // But if there ARE odd numbers, you skip this and move to the next
        // loop.
        if (odd == false) {
            return res;
        }

        // BUG: This loop tries to make up for the discarded counts, but it
        // breaks down if you have mixed combinations of evens and multiple
        // odds.
        for (auto i : mp) {
            int val = i.second;

            if (val % 2 == 1) {
                res += val -
                       1; // Miscalculation: Because the first loop completely
                          // skipped this character, adding val-1 here works,
                          // but doing it in a separate loop makes code fragile.
            }
        }

        return res +
               1; // Correct concept: Adding 1 for the center odd character.
    }
};
