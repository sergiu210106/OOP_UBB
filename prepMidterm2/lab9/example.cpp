#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>

using namespace std;

class Student {
    private:
        std::string m_name;
        double m_gpa;
    
    public:
        Student(const std::string& name, double gpa) : m_name (name), m_gpa (gpa) {}

        std::string name() const {
            return m_name;
        }

        double gpa() const {
            return m_gpa;
        }

        void setGpa(double gpa) {
            m_gpa = gpa;
        }

        friend ostream& operator<<(ostream& os, const Student& s) {
            os << s.m_name << " " << s.m_gpa << "; ";
            return os;
        }
};

void display (const vector<Student> &students) {
            
    std::for_each(students.begin(), students.end(), 
    // lambda function to display a student
    [](const Student& stud) {
        std::cout << stud << " ";
    }
    );

    std::cout << std::endl;
}

int main () {
    std::vector<Student> students = {
        { "Alice", 3.7 },
        { "Bob", 2.9 },
        { "Charlie", 3.2 },
        { "David", 3.9 },
        { "Emma", 3.8 }
    };

    // lambda function to sort by name ascending
    auto sort_by_name_ascending = [] (const Student& a, const Student & b) {
        return a.name() < b.name();
    };

    // lambda function to sort by gpa descending
    auto sort_by_gpa_descending = [] (const Student& a, const Student& b) {
        return a.gpa() > b.gpa();
    };

    // sort by name in increasing order
    std::sort(students.begin(), students.end(), sort_by_name_ascending);

    std::cout << "By name ascending:" << std::endl;
    display(students);

    std::cout << std::endl;

    // sort by name decreasing
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {return a.name() > b.name();});

    std::cout << "By name descending:" << std::endl;
    display(students);

    std::cout << std::endl;

    // sort by gpa increasing

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {return a.gpa() < b.gpa();});

    std::cout << "By gpa increasing:" << std::endl;
    display(students);

    std::cout << std::endl;

    // sort by gpa decreasing

    std::sort(students.begin(), students.end(), sort_by_gpa_descending);

    std::cout << "By gpa decreasing:" << std::endl;
    display(students);

    std::cout << std::endl;

    // increase the gpa by gpaAdd points
    double gpaAdd = 0.5;
    
    std::transform(students.begin(), students.end(), students.begin(),
    // lambda function to increase the gpa of each student by gpaAdd -> gpaAdd in capture clause
    [gpaAdd](Student& s) {
        s.setGpa(s.gpa() + gpaAdd);
        return s;
    });

    std::cout << "After increasing gpa with " << gpaAdd << std::endl;
    display(students);
    std::cout << std::endl;
    return 0;
}