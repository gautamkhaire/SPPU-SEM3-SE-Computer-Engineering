class Set():
    def __init__(self, n):
        self.lst = []
        self.n = n
        self.set_creation(n)

    def set_creation(self, n):
        for i in range(n):
            student = input("Enter name of student : ")
            if (self.is_exist(student) == False):
                self.add_element(student)

    def set_difference(self, Grp1, Grp2):
        diff = []
        for i in range(self.length(Grp1)):
            count = 0
            for j in range(self.length(Grp2)):
                if (Grp1[i] != Grp2[j]):
                    count += 1
            if(count == self.length(Grp2)):
                diff += [Grp1[i]]
        return diff

    def display_set(self, lst):
        print("{", end=" ")
        for i in range(0, self.length(lst)):
            if (lst[i] != lst[len(lst)-1]):
                print(lst[i], end=" , ")
            else:
                print(lst[i], end=" ")
        print("}")

    def set_intersection(self, Grp2):
        Intersection = []
        m = self.length(self.lst)
        n = self.length(Grp2)
        for i in range(m):
            for j in range(n):
                if (self.lst[i] == Grp2[j]):
                    Intersection += [Grp2[j]]
        return Intersection

    def set_union(self, Grp2):
        Union = []
        for i in range(self.length(self.lst)):
            Union += [self.lst[i]]
        for i in range(self.length(Grp2)):
            for i in range(self.length(Grp2)):
                count = 0
                for j in range(self.length(Union)):
                    if (Grp2[i] != Union[j]):
                        count = count + 1
                if (count == self.length(Union)):
                    Union += [Grp2[i]]
        return Union

    def length(self, lst):
        count = 0
        for i in lst:
            count += 1
        return count

    def add_element(self, item):
        self.lst += [item]

    def is_exist(self, name):
        for i in range(0, self.length(self.lst)):
            if (self.lst[i] == name):
                return True
        return False


N1 = int(input("Enter Number of student Who plays Cricket:"))
cricket = Set(N1)
N2 = int(input("Enter Number of student Who plays Badminton:"))
badminton = Set(N2)
N3 = int(input("Enter Number of student Who plays Football:"))
football = Set(N3)

print("Grp1:", end=" ")
cricket.display_set(cricket.lst)
print("Grp2:", end=" ")
badminton.display_set(badminton.lst)
print("Grp3:", end=" ")
football.display_set(football.lst)

print("MAIN MENU \n1.Students playing cricket and badminton \n2.Students playing cricket or badminton but not both")
print("3.Number of students playing neither cricket nor badminton \n4.Number of students playing cricket and football but not badminton")

while(True):
    choice = int(input("Enter choice:"))
    if(choice == 1):
        Ans1 = cricket.set_intersection(badminton.lst)
        print("Students playing cricket and badminton:", end=" ")
        cricket.display_set(Ans1)
    elif(choice == 2):
        Grp1 = cricket.set_union(badminton.lst)
        Grp2 = cricket.set_intersection(badminton.lst)
        Ans2 = cricket.set_difference(Grp1, Grp2)
        print("Students playing cricket or badminton but not both:", end=" ")
        cricket.display_set(Ans2)
    elif(choice == 3):
        Grp1 = football.lst
        Grp2 = cricket.set_union(badminton.lst)
        Ans3 = cricket.set_difference(Grp1, Grp2)
        print("Number of students playing neither cricket nor badminton:",
              cricket.length(Ans3))
    elif(choice == 4):
        Grp1 = cricket.set_intersection(football.lst)
        Grp2 = badminton.lst
        Ans4 = cricket.set_difference(Grp1, Grp2)
        print("Number of students playing cricket and football but not badminton:",
              cricket.length(Ans4))

    else:
        print("Enter correct choice")
