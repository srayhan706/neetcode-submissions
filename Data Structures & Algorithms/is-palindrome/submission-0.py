import re

class Solution:
    def normalize_string(self, s):
        # Remove all non-alphanumeric characters and convert to lowercase
        return re.sub(r'[^a-zA-Z0-9]', '', s).lower()

    def isPalindrome(self, s: str) -> bool:
        s = self.normalize_string(s)
        low, right = 0, len(s) - 1

        while low < right:
            if s[low] != s[right]:
                return False
            low += 1
            right -= 1

        return True
