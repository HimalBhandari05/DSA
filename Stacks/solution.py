# def evaluate_postfix(postfix):
#     stack = []
#     split_value = postfix.split()
#     val = ''.join(split_value)
#     for token in val:
#         if token.isdigit():
#             stack.append(float(token))
#         else:
#             if len(stack) == 0:
#                 return
#             else:
#                 op1 = stack.pop()
#                 op2 = stack.pop()

#             if token == '**':
#                 stack.append(op2 ^ op1) 
#             if token == '*':
#                 stack.append(op2 * op1) 
#             if token == '+':
#                 stack.append(op2 + op1) 
#             if token == '-':
#                 stack.append(op2 - op1) 
#             if token == '/':
#                 stack.append(op2 / op1) 
#     value = stack.pop()
#     return value

# postfix = input("Enter the expression: ")
# answer = evaluate_postfix(postfix)
# print(f"The answer is {answer}")


import math
def evaluate(postfix):
    stack = []
    # goal to scan element from left to right
    split_value = postfix.split()   # return a list -> and then join it to make it a string 
    for val in split_value:
        if val.isdigit():
            stack.append(int(val))
        else:
            op1 = int(stack.pop())
            op2 = int(stack.pop())
            if val == "+":
                stack.append(op2+op1)
            if val == "*":
                stack.append(op2*op1)
            if val == "-":
                stack.append(op2-op1)
            if val == "/":
                stack.append(op2/op1)
            if val == "^":
                stack.append(math.pow(op2,op1))

    result = stack.pop()
    return result


postfix = input('Enter the expressions! \n')
result = evaluate(postfix)
print(f"The result of {postfix} is --> {result}\n")