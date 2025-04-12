#include "Gradebook.hpp"

void Gradebook::addOrUpdateStudent(const string &studentName, double grade){
    studentGrades[studentName] = grade;
}

bool Gradebook::removeStudent(const string &studentName) {
    if (studentExists(studentName)) { 
        studentGrades.erase(studentName);
        return true;
    }
    return false;
}

bool Gradebook::getGrade(const string &studentName, double &grade) const {
    auto it = studentGrades.find(studentName);
    if (it != studentGrades.end()) {
        grade = it->second; // it->first adalah keynya, it->second adalah valuenya
        return true;
    }
    return false;
}

bool Gradebook::studentExists(const string &studentName) const {
    auto it = studentGrades.find(studentName); // it adalah iterator yang menunjuk ke pair dalam map
    if (it != studentGrades.end()) { // studentName ada di map
        return true;
    }
    return false;
}

void Gradebook::printGrades() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong" << endl;
        return;
    }
    int i = 1;
    for (const auto& it : studentGrades) {
        cout << i++ << ". " << it.first << ": " << it.second << endl;
    }
}

void Gradebook::printGradesRank() const {
    vector<pair<string, double>> v(studentGrades.begin(), studentGrades.end());

    sort(v.begin(), v.end(), [](const auto &a, const auto &b) { // descending
        return a.second > b.second;
    });

    int i = 1;
    for (const auto& p : v) {
        cout << i++ << ". " << p.first << ": " << p.second << endl;
    }
}

vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
    vector<string> diAtas;
    for (const auto& it : studentGrades) {
        if (it.second > threshold) {
            diAtas.push_back(it.first);
        }
    }
    sort(diAtas.begin(), diAtas.end());
    return diAtas;
}

double Gradebook::getAverageGrade() const {
    if (studentGrades.empty()) {
        return 0.0;
    }

    double num = 0.0;
    int n = 0;
    for (const auto& it : studentGrades) {
        num += it.second;
        n++;
    }
    return num / n;
}

size_t Gradebook::getNumberOfStudents() const {
    return studentGrades.size();
}