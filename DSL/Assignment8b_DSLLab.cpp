#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    Student *next;

public:
    Student()
    {
        name = " ";
        next = NULL;
    }

    Student(string name)
    {
        this->name = name;
        next = NULL;
    }

    void printStudentData()
    {
        cout << endl
             << name;
    }

    friend class Set;
};

class Set
{
private:
    Student *start ;

public:
    Set()
    {
        start = NULL;
    }

    void AddStudent(string name)
    {
        Student *s = new Student(name);
        if (start == NULL)
        {
            start = s;
        }
        else
        {
            s->next = start;
            start = s;
        }
    }

    void onlySet(Set *list2)
    {
        Student *temp2 = list2->start;
        Student *temp1 = this->start;
        while (temp1 != NULL)
        {
            bool isPresent = false;
            temp2 = list2->start;
            while (temp2 != NULL)
            {
                if (temp1->name == temp2->name)
                {
                    isPresent = true;
                    break;
                }
                temp2 = temp2->next;
            }
            if (!isPresent)
            {
                temp1->printStudentData();
            }
            temp1 = temp1->next;
        }
    }

    Set *unionSet(Set *list2)
    {
        Student *temp1 = start;
        Student *temp2 = list2->start;
        Set *temp3 = new Set;
        while (temp1 != NULL)
        {
            temp3->AddStudent(temp1->name);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            bool isPresent = false;
            temp1 = start;
            while (temp1 != NULL)
            {
                if (temp1->name == temp2->name)
                {
                    isPresent = true;
                    break;
                }
                temp1 = temp1->next;
            }
            if (!isPresent)
            {
                temp3->AddStudent(temp2->name);
            }
            temp2 = temp2->next;
        }
        return temp3;
    }

    void displayNone(Set *unionSetAB)
    {
        Student *temp1 = start;
        Student *temp2 = unionSetAB->start;
        while (temp1 != NULL)
        {
            bool isPresent = false;
            temp2 = unionSetAB->start;
            while (temp2 != NULL)
            {
                if (temp1->name == temp2->name)
                {
                    isPresent = true;
                    break;
                }
                temp2 = temp2->next;
            }
            if (!isPresent)
            {
                temp1->printStudentData();
            }
            temp1 = temp1->next;
        }
    }

    void intersection(Set *list2)
    {
        Student *temp1 = start;
        Student *temp2 = NULL;
        while (temp1 != NULL)
        {
            temp2 = list2->start;
            while (temp2 != NULL)
            {
                if (temp1->name == temp2->name)
                {
                    temp1->printStudentData();
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }

    void displayStudents()
    {
        Student *temp = start;
        cout << endl
             << "Names";
        while (temp != NULL)
        {
            temp->printStudentData();
            temp = temp->next;
        }
    }
};

int main()
{
    Set *A, *B, *universalSet, *temp = NULL;
    A = new Set;
    B = new Set;
    universalSet = new Set;
    int option, flavour;
    string name;

    while (true)
    {
        cout << endl;
        cout << "--------Second Year Student Database--------";
        cout << endl
             << "1.Enter student\n2.Display students\n3.Display Students(like-Vanilla)";
        cout << "\n4.Display Students(like-Butterscotch)"
             << "\n5.Display Students(like-both Vanilla and ButterScotch)";
        cout << "\n6.Display Students(like-none of them)\n7.Display Students(like-either Vanilla or ButterScotch or Both)\n8.Exit";
        cout << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "\nEnter the name of student : ";
            cin >> name;
            cout << "\nEnter the flavour liked:\n1.ButterScotch\n2.Vanilla\n3.Both\n4.None : ";
            cin >> flavour;
            switch (flavour)
            {
            case 1:
                B->AddStudent(name);
                break;
            case 2:
                A->AddStudent(name);
                break;
            case 3:
                A->AddStudent(name);
                B->AddStudent(name);
                break;
            case 4:
                break;
            default:
                "Wrong option";
            }
            if (flavour >= 1 && flavour <= 4)
            {
                universalSet->AddStudent(name);
            }
            break;
        
        case 2:
            universalSet->displayStudents();
            break;
        case 3:
            A->onlySet(B);
            break;
        case 4:
            B->onlySet(A);
            break;
        case 5:
            A->intersection(B);
            break;
        case 6:
            temp = A->unionSet(B);
            universalSet->displayNone(temp);
            delete temp;
            break;
        case 7:
            temp = A->unionSet(B);
            temp->displayStudents();
            delete temp;
            break;

        case 8:
            break;

        default:
            cout << "Wrong option";
            break;
        }
    }
    delete A,B,universalSet;
}