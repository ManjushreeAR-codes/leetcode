class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> map;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            if (map.find(s[right]) != map.end()) {
                left = std::max(left, map[s[right]] + 1);
            }

            map[s[right]] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};