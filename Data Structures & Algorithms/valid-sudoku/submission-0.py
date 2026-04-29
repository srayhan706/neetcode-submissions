from collections import defaultdict
from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_map = defaultdict(set)
        col_map = defaultdict(set)
        sqr_map = defaultdict(set)  # key = (row // 3, col // 3)

        for i in range(9):
            for j in range(9):
                val = board[i][j]
                if val == ".":
                    continue

                sqr_index = (i // 3, j // 3)
                
                # Check duplicates
                if (val in row_map[i] or 
                    val in col_map[j] or 
                    val in sqr_map[sqr_index]):
                    return False

                # Add value to sets
                row_map[i].add(val)
                col_map[j].add(val)
                sqr_map[sqr_index].add(val)

        return True
