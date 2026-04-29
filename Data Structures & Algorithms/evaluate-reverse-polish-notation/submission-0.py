class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

        def cal(op1: int, op2: int, operator: str) -> int:
            if operator == "+":
                return op1 + op2
            elif operator == "-":
                return op1 - op2
            elif operator == "*":
                return op1 * op2
            else:  # "/"
                # Truncate toward zero
                return int(op1 / op2)

        stack = []
        operators = {"+", "-", "*", "/"}

        for token in tokens:
            if token not in operators:
                stack.append(int(token))
            else:
                op2 = stack.pop()
                op1 = stack.pop()
                result = cal(op1, op2, token)
                stack.append(result)

        return stack[-1]
