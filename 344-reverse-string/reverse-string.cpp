class Solution {
public:
    void reverseString(vector<char>& s) {
        int maper = s.size() - 1; // Start at the last valid index
        
        // Loop through only the first half
        for (int i = 0; i < s.size() / 2; i++) {
            // Swap the front element with the back element
            swap(s[i], s[maper]); 
            maper--; // Move the back pointer inward
        }
    }
};
