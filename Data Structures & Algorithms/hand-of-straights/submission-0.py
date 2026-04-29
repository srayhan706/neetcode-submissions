class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand)%groupSize !=0:
            return False

        hand.sort()

        cnt=Counter(hand)
        
        for i in range(len(hand)):
            if cnt[hand[i]]:
                for i in range(hand[i],hand[i]+groupSize):
                    if not cnt[i]:
                        return False
                    cnt[i]-=1

        return True
            

        