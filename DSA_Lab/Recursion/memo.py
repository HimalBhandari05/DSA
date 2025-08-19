def memoFibo(n , table={}):
    if n==1 or n==2:
        return 1
    else:
        if n not in table:
            table[n] = memoFibo(n-1) + memoFibo(n-2)
            print(f"Computed fibo({n}) = {table[n]}")
        return table[n]
    

n = int(input("Enter the number n = "))
value = memoFibo(n)
print(f"The fibo term is {value}\n")