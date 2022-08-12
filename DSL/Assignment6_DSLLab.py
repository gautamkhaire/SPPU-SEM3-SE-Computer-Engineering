class Percentage:
    def __init__(self):
        self.arr=[]
        self.n=0

    def input_List(self):
        self.n = int(input("Enter the number of  students in FE :"))
        print("Enter the Percentages :")
        for i in range(self.n):
            elem = int(input())
            self.arr.append(elem)
        print(self.arr)
    
    def display(self):
        print("\n Sorted array of percentages :",self.arr)
        print("\n Top five Percentages are :")
        for i in range(1,6):
            print(i," ",self.arr[-i])

    def quickSort(self,start,end):
        if(start>=end):
            return
        else:
            pivot=self.arr[start]
            i=start+1
            j=end
            while(i<=j):
                while self.arr[i]<pivot and i<=end :
                    i=i+1
                while self.arr[j]>pivot and j>=start :
                    j=j-1    
                if i<j:
                    temp=self.arr[i]
                    self.arr[i]=self.arr[j]
                    self.arr[j]=temp
                    i=i+1
                    j=j-1
            temp=self.arr[start]
            self.arr[start]=self.arr[j]
            self.arr[j]=temp
            Percentage.quickSort(self,start,j-1)
            Percentage.quickSort(self,j+1,end)

obj=Percentage()
obj.input_List()
obj.quickSort(0,obj.n-1)
obj.display()
