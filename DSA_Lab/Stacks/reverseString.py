# class Reverse:
#     def __init__(self , string):
#         self.string = string
#         self.stack = []
    
#     def reverseString(self):
#         return self.string
    

# reversed = Reverse("HimalBhandari")
# print(reversed.reverseString)


def reverseString(value):
    stack = []
    return_string = ''
    value = list(value)
    print(value)
    for val in value:
        stack.append(val)
    
    print(stack)
    while stack:
        return_string += stack.pop()
    
    print(return_string)
    return return_string

val = reverseString('Himal Bhandari')
print(val)