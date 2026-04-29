class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_map={}
        t_map={}

        for char in s:
            if char not in s_map.keys():
                s_map[char]=1
            else:
                s_map[char]+=1

        for char in t:
            if char not in t_map.keys():
                t_map[char]=1
            else:
                t_map[char]+=1
        if s_map==t_map:
            return True
        else:
            return False
        