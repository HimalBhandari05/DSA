count =0
def TOH(n , src , dst , temp):
    global count
    if n==1:
        print(f"Move {n} from {src} to {dst}")
        count+=1
    else:
        TOH(n-1 , src , temp , dst)
        print(f"Move {n} from {src} to {dst}")
        TOH(n-1 , temp , dst , src )
        count+=1

def main():
    n = int(input('Enter the value of n: \n'))
    TOH(n , 'A' , 'C' ,'B')
    print(f"The count is {count}")
main()