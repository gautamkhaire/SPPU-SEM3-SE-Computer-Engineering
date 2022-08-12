class SearchOperation:
    arr=[]
    n=0
    def __init__(self):
        self.arr=[]
        self.n=0
        self.sortarr=[]
    
    def inputarr(self):
        self.n=int(input("Enter the number of elements in the array :"))
        print("Enter the elements :")
        for i in range(self.n):
            elem=int(input())
            self.arr.append(elem)
        print(self.arr)


    def linearsearch(self,x):
        for i in range(self.n):
            if(self.arr[i]==x):
                return i

        return -1        

    def binarysearch(self,x):
        self.sortarr=self.arr
        self.sortarr.sort()
        start=0
        end=self.n-1
        while start<=end:
            mid=int((start+end)/2)
            if(self.sortarr[mid]==x):
                return mid
            elif(x<self.sortarr[mid]):
                end=mid-1
            else:
                start=mid+1               
        return -1;    

    def sentinelsearch(self,x):
        end=self.arr[self.n-1]
        self.arr[self.n-1]=x
        i=0
        while self.arr[i] != x:
            i=i+1
        self.arr[self.n-1]=end
        if((i<self.n-1) or (x==self.arr[self.n-1])):
            return i
        else:
            return -1

    @staticmethod
    def rfibonacci(n):
        a=b=c=1
        if(n==0 or n==1):
            return 0
        else:
            while(c<n):
                c=a+b
                a=b
                b=c
        return a    
    
    def fibonaccisearch(self,x):
        self.sortarr=self.arr
        self.sortarr.sort()
        start=0
        end=self.n-1
        flag=0
        loc=-1
        index=0
        while(flag != 0 and start<=end):
            index=SearchOperation.rfibonacci(self.n)
            if(x == self.sortarr[index+start]):
                flag=1
                loc=index
                break
            elif(x > self.sortarr[index+start]):
                start=start+index+1
            else:
                end=start+index+1
            self.n=end-start+1
        if(flag==1):
            return (loc+start+1)
        else:
           return -1

    

obj1=SearchOperation()
obj1.inputarr()
x=int(input("Enter the element to be serached in array :")) 
print('''-------Menu-------
1.Linear Search
2.Binary Search
3.Sentinel Search
4.Fibonacci Serach''')
choice=int(input("Enter the choice :"))
if(choice == 1):
    print("Linear Search")
    print("The element "+str(x)+" is at index : ",obj1.linearsearch(x) )
elif(choice ==2):
    print("Binary Serach")
    print("The element "+str(x)+" is at index : ",obj1.binarysearch(x) )
elif(choice ==3):
    print("Sentinel Serach")
    print("The element "+str(x)+" is at index : ",obj1.sentinelsearch(x) )
elif(choice ==4):
    print("Fibonacci Serach")
    print("The element "+str(x)+" is at index : ",obj1.fibonaccisearch(x) )
else:
    print("Invalid Choice")
       