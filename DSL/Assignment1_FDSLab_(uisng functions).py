# def get_number_of_elements(list):
#     count=0
#     for element in list:
#         count +=1
#     return count 
 
def removeDuplicate(d):
    lst=[]
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst

def intersection(lst1,lst2):
    lst3=[]
    for val in lst1:
        if val in lst2:
            lst3.append(val)
    return lst3

def union(lst1,lst2):
    lst3=lst1.copy()
    for val in lst2:
        if val not in lst3:
            lst3.append(val)
    return lst3

def diff(lst1,lst2):
    lst3=[]
    for val in lst1:
        if val not in lst2:
            lst3.append(val)
    return lst3

def sym_diff(lst1,lst2):
    lst3=[]
    D1=diff(lst1,lst2)
    print("Difference between Cricket and Badminton (C-B) is : ", D1)
    D2=diff(lst2,lst1)
    print("Difference between Badminton and Cricket (B-C) is : ", D2)
    lst3=union(D1,D2) 
    return lst3

def CB(lst1,lst2):
    lst3=intersection(lst1,lst2)
    print("\n\nList of students who play both cricket and badminton is : ", lst3)
    # print("Number of elements in the list :",get_number_of_elements(lst3)) 
    return len(lst3)    

def CrB(lst1,lst2):
    lst3=sym_diff(lst1,lst2)
    print("\nList of students who play either cricket or badminton but not both is : ",lst3)
    # print("Number of elements in the list :",get_number_of_elements(lst3))
    return len(lst3)

def CnB(lst1,lst2,lst3):
    lst4=diff(lst1,union(lst2,lst3))
    print("\n\nList of students who play neither cricket nor badminton is : ",lst4)
    # print("Number of elements in the list :",get_number_of_elements(lst4))
    return len(lst4)


def CBnF(lst1,lst2,lst3):
    lst4=diff(intersection(lst1,lst2),lst3)
    print("\n\nList of students who play cricket and football but not badminton is : ",lst4)
    # print("Number of elements in the list :",get_number_of_elements(lst4))
    return len(lst4)

SEComp = []
Cricket = []
Football = []
Badminton = []

n = int(input("\nEnter number of students in SE Computer: "))
print("Enter the names of",n,"students :")
for i in range(n):
    names = input()
    SEComp.append(names)  
print("Original list of students in SEComp : " + str(SEComp)) 

n = int(input("\n\nEnter number of students who play cricket : "))
print("Enter the names of",n,"students who play cricket:")
for i in range(n):
    names = input()
    # if names not in list:
    Cricket.append(names)  
print("Original list of students playing cricket is :" +str(Cricket))
Cricket=removeDuplicate(Cricket)
print("The list of students playing cricket after removing duplicates : " +str(Cricket))


n = int(input("\n\nEnter number of students who play football : "))
print("Enter the name of",n,"students who play football :")
for i in range(n):
    names = input()
     # if names not in list:
    Football.append(names)  
print("Original list of students playing football :" +str(Football))
Football=removeDuplicate(Football)
print("The list of students playing football after removing duplicates : " +str(Football))

n = int(input("\n\nEnter number of students who play badminton : "))
print("Enter the name of",n,"students who play badminton :")
for i in range(n):
    names = input()
     # if names not in list:
    Badminton.append(names)  
print("Original list of students playing badminton :" +str(Badminton))
Badminton=removeDuplicate(Badminton)
print("The list of students playing badminton after removing duplicates : " +str(Badminton))
   
print("1. List of students who play both cricket and badminton")
print("2. List of students who play either cricket or badminton but not both")
print("3. List of students who play neither cricket nor badminton")
print("4. Number of students who play cricket and football but not badminton")
ch=int(input("Enter your Choice :"))
if ch==1:
    print("Number of students who play both cricket and badminton : ", CB(Cricket,Badminton))
elif ch==2:
    print("Number of students who play either cricket or badminton but not both : ", CrB(Cricket, Badminton))
elif ch==3:
    print("Number of students who play neither cricket nor badminton : ", CnB(SEComp,Cricket,Badminton))
elif ch==4:
    print("Number of students who play cricket and football but not badminton : ", CBnF(Cricket,Football,Badminton))
else:
    print("Wrong Choice")
            