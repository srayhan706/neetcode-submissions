class Solution:

    def chkpal(self, pal:str)->bool:
        l=len(pal)
        for i in range(l//2):
            if pal[i]!=pal[-(i+1)]:
                return False
        return True

    def countSubstrings(self, s: str) -> int:
        l=len(s)

        count=0
        
        for i in range(l):
            for j in range(i,l):
                if self.chkpal(s[i:j+1]):
                    count+=1
        return count
        