#include <iostream>
#include "Student.h"
using namespace std;

void menu()
{
    cout << "\n\n\tMENU\n";
    cout << "1.Add a student\n";
    cout << "2.Show average performance of students born in March\n";
    cout << "3.Show the student with highest performance\n";
    cout << "4.Exit\n";
    cout << "--Enter an option: ";
}

void resizeArr(Student*& students, size_t& capacity, size_t size)
{
    if (size >= capacity)
    {
        Student* newArr = new Student[capacity * 2];
        capacity *= 2;
        for (size_t i = 0; i < size; i++) {
            newArr[i] = students[i];
        }

        delete[] students;

        students = newArr;
    }

}

int main()
{
    Student* students = new Student[1];
    size_t capacity = 1;
    size_t size = 0;

    menu();

    size_t cmd;
    cin >> cmd;

    while (cmd != 4)
    {
        cin.ignore();
        switch (cmd)
        {
        case 1:
            resizeArr(students, capacity, size);
            if (addStudent(students, size)) {
                size++;
            }
            break;
        case 2:
            printStudentsInMarch(students, size);
            break;
        case 3:
            printHighestGrade(students, size);
            break;
        case 4:
            break;

        default:
            break;
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        deleteStudent(students[i]);
    }

    return 0;
}