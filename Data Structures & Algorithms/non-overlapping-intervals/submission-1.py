class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        cnt=0
        e=intervals[0][1]

        for i in range(1,len(intervals)):
            if e>intervals[i][0]:
                cnt+=1
                e=min(e,intervals[i][1])
            else:
                e=intervals[i][1]

        return cnt
        