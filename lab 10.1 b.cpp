#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Перелічуваний тип для спеціальностей
enum Speciality { COMPUTER_SCIENCE, INFORMATICS, MATH_ECONOMICS, PHYSICS_INFORMATICS, LABOR_TEACHING };
string specialityStr[] = { "COMPUTER_SCIENCE", "INFORMATICS", "MATH_ECONOMICS", "PHYSICS_INFORMATICS", "LABOR_TEACHING" };

// Структура для зберігання інформації про студента
struct Student {
    string surname;
    int course;
    Speciality speciality;
    int physicsGrade;
    int mathGrade;
    union {
        int programmingGrade; // Для спеціальності "Комп’ютерні науки"
        int numericalMethodsGrade; // Для спеціальності "Інформатика"
        int pedagogyGrade; // Для інших спеціальностей
    };
};

// Функція для введення інформації про студентів
void inputStudents(vector<Student>& students, int n) {
    for (int i = 0; i < n; i++) {
        Student s;
        cout << "Surname: ";
        cin >> s.surname;
        cout << "Course: ";
        cin >> s.course;
        int spec;
        cout << "Speciality (0 - COMPUTER_SCIENCE, 1 - INFORMATICS, 2 - MATH_ECONOMICS, 3 - ФPHYSICS_INFORMATICS, 4 - LABOR_TEACHING): ";
        cin >> spec;
        s.speciality = static_cast<Speciality>(spec);
        cout << "Enter a grade in Physics: ";
        cin >> s.physicsGrade;
        cout << "Enter a grade in Math: ";
        cin >> s.mathGrade;

        if (s.speciality == COMPUTER_SCIENCE) {
            cout << "Enter a grade in Programming: ";
            cin >> s.programmingGrade;
        }
        else if (s.speciality == INFORMATICS) {
            cout << "Enter Score from Numerical Methods: ";
            cin >> s.numericalMethodsGrade;
        }
        else {
            cout << "Enter a grade in Pedagogy: ";
            cin >> s.pedagogyGrade;
        }
        students.push_back(s);
    }
}

// Функція для виведення масиву студентів
void printStudents(const vector<Student>& students) {
    cout << "=============================================================================================" << endl;
    cout << "| № | Surname      | Course |Speciality        | Physic | Math | Programming |  Numerical Methods | Pedagogy |" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    for (size_t i = 0; i < students.size(); i++) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(12) << left << students[i].surname
            << " | " << setw(4) << right << students[i].course
            << " | " << setw(20) << left << specialityStr[students[i].speciality]
            << " | " << setw(6) << students[i].physicsGrade
            << " | " << setw(10) << students[i].mathGrade;

        if (students[i].speciality == COMPUTER_SCIENCE)
            cout << " | " << setw(12) << students[i].programmingGrade << " | " << setw(15) << "|" << setw(11) << "|" << endl;
        else if (students[i].speciality == INFORMATICS)
            cout << " | " << setw(15) << "|" << setw(12) << students[i].numericalMethodsGrade << " |" << setw(11) << "|" << endl;
        else
            cout << " | " << setw(15) << "|" << setw(15) << "|" << setw(10) << students[i].pedagogyGrade << " |" << endl;
    }
    cout << "=============================================================================================";
