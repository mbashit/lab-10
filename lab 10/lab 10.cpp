// lab 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int course;
};

int main() {
    ifstream infile("student.dat");
    ofstream outfile("updated_student.dat");
    if (!infile || !outfile) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    Student student;
    while (infile >> student.name >> student.course) {
        // Increment course number
        student.course++;
        // Write to file if not on fourth course
        if (student.course != 4) {
            outfile << student.name << " " << student.course << endl;
        }
    }

    infile.close();
    outfile.close();

    return 0;
}
