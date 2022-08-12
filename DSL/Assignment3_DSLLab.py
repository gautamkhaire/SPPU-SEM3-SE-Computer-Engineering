class MyMatrix:

    def __init__(self,r,c) :
        self.row=r
        self.col=c
        self.mat=[]
        

    def acceptmat(self) :
        for i in range(self.row) :
            row=[]
            for j in range(self.col):
                print("Enter the elements :",end=" ")
                row.append(int(input()))
            self.mat.append(row)    
           

    def displaymat(self):
        print("Printing in Matrix form :")
        for row in self.mat:
            for y in row:
                print(y,end=" ")
            print()
         
    
    def additionmat(self,obj2):
        obj3=MyMatrix(self.row,self.col)
        if self.row==obj2.row and self.col==obj2.col:
            for i in range(self.row):
                lst=[]
                for j in range(self.col):
                    lst.append(self.mat[i][j]+obj2.mat[i][j])
                obj3.mat.append(lst) 
            return obj3    
        else :
            print("Invalid Matrix Addition")              
            return None
         

    def subtractionmat(self,obj2):
        obj4=MyMatrix(self.row,self.col)
        if self.row==obj2.row and self.col==obj2.col:
            for i in range(self.row):
                lst=[]
                for j in range(self.col):
                    lst.append(self.mat[i][j]-obj2.mat[i][j])
                obj4.mat.append(lst) 
            return obj4     
        else :
            print("Invalid Matrix Subtraction")           
            return None

    def multiplicationmat(self,obj2):
        obj5=MyMatrix(self.row,self.col)
        if self.col==obj2.row :
            for i in range(self.row):
                lst=[]
                for j in range(obj2.col):
                    elem=0
                    for k in range(obj2.row):
                        elem=elem+(self.mat[i][k]*obj2.mat[k][j])
                    lst.append(elem)
                obj5.mat.append(lst)
            return obj5     
        else :
            print("Invalid Matrix Multiplication")           
            return None
           
    def transposemat(self):
        self.row=len(self.mat)
        self.col=len(self.mat[0])
        matrix_T=[]
        for j in range(self.col):
            row=[]
            for i in range(self.row):
                row.append(self.mat[i][j])
            matrix_T.append(row)
        return matrix_T

rowno=int(input("Enter the RowNo :"))
colno=int(input("Enter the ColNo :"))
obj1=MyMatrix(rowno,colno)
obj1.acceptmat() 
obj1.displaymat()
rowno=int(input("Enter the RowNo :"))
colno=int(input("Enter the ColNo :"))
obj2=MyMatrix(rowno,colno)
obj2.acceptmat() 
obj2.displaymat()

print('''   
    1.Addition of two Matrix
    2.Subtraction of two Matrix
    3.Multiplication of two Matrix
    4.Transpose of a Matrix    ''')
choice = int(input("Enter the choice : "))
if choice ==1:
    obj3=obj1.additionmat(obj2)
    obj3.displaymat()
elif choice ==2:
    obj4=obj1.subtractionmat(obj2)
    obj4.displaymat()
elif choice ==3:
    obj5=obj1.multiplicationmat(obj2)
    obj5.displaymat()
elif choice ==4:
    obj1.transposemat()
    obj1.transposemat()
    obj2.transposemat() 
    obj2.displaymat() 
else:
    print("Invalid Choice")      





   