class SortTech:
    def __init__(self):
        self.arr = []
        self.n = 0

    def input_List(self):
        self.n = int(input("Enter the number of elements in the array :"))
        print("Enter the elements :")
        for i in range(self.n):
            elem = int(input())
            self.arr.append(elem)
        print(self.arr)

    def selectionsort(self):
        for i in range(len(self.arr)):
            min_index = i
            for j in range(i+1, len(self.arr)):
                if(self.arr[min_index] > self.arr[j]):
                    min_index = j
            temp = self.arr[i]
            self.arr[i] = self.arr[min_index]
            self.arr[min_index] = temp
        print("Selection sort :", self.arr)

    def bubblesort(self):
        for i in range(len(self.arr)-1):
            for j in range(len(self.arr)-1-i):
                if(self.arr[j] > self.arr[j+1]):
                    temp = self.arr[j]
                    self.arr[j] = self.arr[j+1]
                    self.arr[j+1] = temp
        print("Bubble sort :", self.arr)

    def insertionsort(self):
        for i in range(1,len(self.arr)):
            temp=self.arr[i]
            j=i-1
            while(temp<self.arr[j] and j>=0):
                self.arr[j+1]=self.arr[j]
                j=j-1
            self.arr[j+1]=temp
        print("Insertion sort :",self.arr)

    def shellsort(self):
        n=len(self.arr)
        gap=int(n/2)    
        while gap > 0:
            for i in range(gap,n):
                temp=self.arr[i]
                j=i
                while j>=gap and self.arr[j-gap]>temp:
                    self.arr[j]=self.arr[j-gap]
                    j=j-gap

                self.arr[j]=temp    
            gap=int(gap/2)
        print("Shell sort :",self.arr)

obj1 = SortTech()
obj1.input_List()
print('''-------Menu-------
1.Selection Sort
2.Bubble Sort
3.Insertion Sort
4.Shell Sort''')
choice = int(input("Enter the choice :"))
if(choice == 1):
    obj1.selectionsort()
elif(choice == 2):
    obj1.bubblesort()
elif(choice == 3):
    obj1.insertionsort()
elif(choice == 4):
    obj1.shellsort()
