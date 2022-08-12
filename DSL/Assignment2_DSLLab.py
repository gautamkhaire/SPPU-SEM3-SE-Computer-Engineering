class MyString:
    def __init__(self):
        self.listwords = []
        self.listchar = []
        self.lengthword = 0
        self.lengthchar = 0

    def accept(self):
        global string
        string = input("Enter the sentence :")
        print(f"The sentence is -> {string}")
        self.listwords = list(string.split(' '))
        print(self.listwords)
        self.listchar = list(character for character in string)
        print(self.listchar)

    def longestword(self):
        w = ' '
        for word in self.listwords:
            if(len(word) > self.lengthword):
                self.lengthword = len(word)
                w = word
        print("Longest word is ", w, " and its length is ", self.lengthword)

    def frequencyoccurence(self, character):
        count = 0
        for i in character:
            if i == character:
                count = count+1
        return count

    def palindrome(self):
        if (list(string)[::-1] == list(string)):
            return True
        else:
            return False

    def displayindexfirst(self, substr):
        count = MyString.len(substr.listchar)
        for i in range(self.lengthchar):
            index, indexsub, temp = 0, 0, []
            if self.listchar[i] == substr.listchar[indexsub]:
                index = i
                while True:
                    temp.append(self.listchar[index])
                    if temp == substr.listchar:
                        print("The substring is found at index: ", index-(count-1))
                        break
                    index += 1
                    indexsub += 1
                    if index > (self.lengthchar-1):
                        break
                    elif self.listchar[index] == substr.listchar[indexsub]:
                        continue
                    else:
                        break

    def countoccurence(self):
        wcount = []
        for i in range(len(self.listwords)):
            wcount.append(0)
            for word in self.listwords:
                if (word == self.listwords[i]):
                    wcount[i] = wcount[i]+1
            if (self.listwords[i] not in self.listwords[i+1::]):
                print("The word ",
                      self.listwords[i], "occurs ", wcount[i], "times.")


a = MyString()
a.accept()


print('''   
    1.Longest word
    2.Frequency of occurence of a character
    3.Check if the string is a palindrome
    4.Find the index of substring
    5.Display occurrences of each word in the string    ''')
choice = int(input("Enter the choice : "))
if choice == 1:
    a.longestword()
elif choice == 2:
    character = input("Enter the character : ")
    print("\nThe frequency of occurrence of the character is: ",
          a.frequencyoccurence(character))
elif choice == 3:
    if (a.palindrome()):
        print("\nYes, the string is a palindrome.")
    else:
        print("\nNo, the string is not a palindrome.")
elif choice == 4:
    sub = MyString()
    sub.listwords = list(input("\nEnter the substring: ").split(" "))
    for i in sub.listwords:
        for j in i:
            sub.listchars.append(j)
    a.displayindexfirst(sub)
elif choice == 5:
    a.countoccurence()
else:
    print("Invalid Operation")
