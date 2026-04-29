class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {')': '(', '}': '{', ']': '['}

        for brac in s:
            if brac in mapping.values():  # opening brackets
                stack.append(brac)
            elif brac in mapping:  # closing brackets
                if not stack or stack[-1] != mapping[brac]:
                    return False
                stack.pop()
            else:
                return False  # in case of any invalid character

        return not stack  # valid if stack is empty at the end
