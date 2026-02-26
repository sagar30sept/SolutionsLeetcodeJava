class Solution {
    public int lengthOfLongestSubstring(String s) {

        int i = 0;             // Left pointer of sliding window
        int j = 0;             // Right pointer of sliding window
        int N = s.length();    // Length of the string
        int ans = 0;           // Stores the maximum length found so far
        int[] count = new int[128]; // Frequency array for ASCII characters
        int dup = 0;           // Tracks number of duplicate characters in window

        for (; j < N; j++) {

            // Expand window by including s[j]
            // If its count becomes 2, it's a new duplicate → increment dup
            dup += ++count[s.charAt(j)] == 2 ? 1 : 0;

            // Shrink window from left until no duplicates remain
            while (i <= j && dup > 0) {
                // Decrease count of s[i] and move left pointer
                // If count drops to 1, duplicate is resolved → decrement dup
                dup -= --count[s.charAt(i++)] == 1 ? 1 : 0;
            }

            // Update answer with current window size
            ans = Math.max(ans, j - i + 1);
        }

        return ans;
    }
}


// ### Dry Run Example
// s = "abcabcbb"

// j=0: add 'a' → count[a]=1, dup=0 | window="a"       | ans=1
// j=1: add 'b' → count[b]=1, dup=0 | window="ab"      | ans=2
// j=2: add 'c' → count[c]=1, dup=0 | window="abc"     | ans=3
// j=3: add 'a' → count[a]=2, dup=1 | shrink → remove 'a', i=1, dup=0
//                                   | window="bca"     | ans=3
// j=4: add 'b' → count[b]=2, dup=1 | shrink → remove 'b', i=2, dup=0
//                                   | window="cab"     | ans=3
// j=5: add 'c' → count[c]=2, dup=1 | shrink → remove 'c', i=3, dup=0
//                                   | window="abc"     | ans=3
// j=6: add 'b' → count[b]=2, dup=1 | shrink → remove 'a','b', i=5, dup=0
//                                   | window="cb"      | ans=3
// j=7: add 'b' → count[b]=2, dup=1 | shrink → remove 'c','b', i=7, dup=0
//                                   | window="b"       | ans=3

// Result = 3 ✅  ("abc")
