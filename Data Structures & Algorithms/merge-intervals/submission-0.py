class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        res=[]
        res.append(intervals[0])
        e=intervals[0][1]

        for i in range(1,len(intervals)):
            if e>=intervals[i][0]:
                res[-1][1]=max(e,intervals[i][1])
                e=res[-1][1]
            else:
                res.append(intervals[i])
                e=intervals[i][1]

        return res
        