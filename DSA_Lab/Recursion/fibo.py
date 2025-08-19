def fibo(n):
    if n==1 or n==2:
        return 1
    else:
        return fibo(n-1) +fibo(n-2)


def main():
    n = int(input("Enter n = "))
    value = fibo(n)
    print(f"\nThe value is = {value} ")

main()