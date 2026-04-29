class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        ans=defaultdict(list)

        for w in strs:
            k="".join(sorted(w))
            ans[k].append(w)
        return list(ans.values())

        