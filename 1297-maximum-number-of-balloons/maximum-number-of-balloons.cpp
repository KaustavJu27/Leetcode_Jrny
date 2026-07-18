class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        // Count frequencies of all characters
        for (char c : text) {
            mp[c]++;
        }

        // 'l' and 'o' appear twice in "balloon", so divide their availability by 2
        int b = mp['b'];
        int a = mp['a'];
        int l = mp['l'] / 2;
        int o = mp['o'] / 2;
        int n = mp['n'];

        // The bottleneck (minimum) determines how many full words we can make
        return min({b, a, l, o, n});
    }
};
