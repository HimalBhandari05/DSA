def GCD(a,b):
    if b==0:
        return a
    else:
        return GCD(b , a%b)
    
def main():
    a , b = int(input("Enter the two numbers a =  ")) , int(input("\nEnter the next number b = "))
    hcf = GCD(a,b)
    print(f"The hcf of {a} , {b} is {hcf}\n")

main()