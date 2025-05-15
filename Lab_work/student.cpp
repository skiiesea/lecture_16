#include "STUDENT.hpp"
Student::Student(const char* name, const char* group, const char* specialty) : subjectCount(0) {
    setFullName(name);
    setGroupNumber(group);
    setSpecialty(specialty);
}


void Student::setFullName(const char* name) {
    if (strlen(name) >= MAX_NAME_LEN) {
        throw
        std::invalid_argument("Full name is too long.");
    }
    strcpy(fullName, name);
}

void  Student::setGroupNumber(const char* group) {
    if (strlen(group) >= MAX_GROUP_LEN) {
        throw
        std::invalid_argument("Group number is too long.");
    }
    strcpy(this -> specialty, specialty);
}

void Student::setSpecialty(const char* specialty){
    if (subjectCount >= MAX_SUBJECTS) {
        throw
        std::out_of_range("Cannot add more than 5 subjects.");
    }
    if (strlen(subject) >= MAX_NAME_LEN) {
        throw
        std::invalid_argument("Subject name is too long.");
    }
strcpy(subjects[subjectCount].name, subject);
subjects[subjectCount].gradeCount = 0;
    subjectCount++;
}

void Student::addGrade(const char* subject, int grade) {
    if (grade < 1 || grade > 5) {
        throw
        std::invalid_argument("Grade must be between 1 and 5.");
    }

    int subjectIndex = -1;
    for(i = 0; i < subjectCount; ++i) {
        if (strcmp(subjects[i].name, subject) == 0) {
            subjectIndex = i;
            break;
        }
    }

    if (subjectIndex == -1) {
        throw
        std::invalid_argument("Subject not found.");
    }
    if (subjects[subjectIndex].gradeCount >= MAX_GRADES_PER_SUBJECT) {
        throw
        std::out_of_range("Cannot add more than 20 grades for a subject");
    }
subjects[subjectIndex].grades[subjects[subjectIndex].gradeCount++] = grade;
}

const char* Student::getFullName() const {
    return fullName;
}
const char* Student::getGroupNumber() const {
    return groupNumber;
}
const char* Student::getSpecialty() const {
    return specialty;
}
double Student::getAverageGradeBySubject(const char* subject) const {
    int subjectIndex = -1;
    for(int i = 0; i < subjectCount; ++i) {
        if (strcmp(subjects[i].name, subject) == 0) {
            subjectIndex = i;
            break;
        }
    }
    if (subjectIndex == -1) {
        throw
        std::invalid_argument("Subject not found.")
    }
    if  (subjects[subjectIndex].gradeCount == 0) {
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < subject[subjectIndex].gradeCount; ++i){
        sum += subjects[subjectIndex].grades[i];
    }
    return sum / subject[subjectIndex].gradeCount;
}

double Student::getOverallAverage() const {
    if (subjectCount == 0) {
        return 0.0;
    }
    double totalSum = 0.0;
    int totalGrades = 0;
    for (int i = 0; i < subjectCount; ++i){
        for (int j = 0; j < subjects[i].gradesCount; ++j) {
            totalSum += subjects[i].grades[j];
            totalGrades += subjects[i].gradeCount;
        }
        if (totalGrades == 0) {
            return 0.0;
        } 
        return totalSum / totalGrades;
    }
const char* Student::getBestSubject() const{
    if (subjectCount == 0) {
        throw
        std::runtime_error("No subjects available.");
    }
    int bestIndex = 0;
    double bestAverage = getAverageGradeBySubject(subjects[0].name);
    int maxGrades = subjects[0].gradeCount;
    for (int i = 0; i < subjectCount; ++i) {
        double currentAverage = getAverageGradeBySubject(subjects[i].name);
        int currentGrades = subjects[i].gradeCount;
        if (currentAverage > bestAverage) {
            bestAverage = currentAverage;
            bestIndex = i;
            maxGrades = currentGrades;
        }
    }
    return subjects[bestIndex].name;
    }
const char* Student::getWorstSubject() const {
    if (subjectCount == 0) {
        throw
        std::runtime_error("No subjects available.");
    }
    int worstIndex = 0;
    double worstAverage = getAverageGradeBySubject(subjects[0].name);
    int maxGrades = subjects[0].gradeCount;
    for (int i = 0; i < subjectCount; ++i) {
        double currentAverage = getAverageGradeBySubject(subjects[i].name);
        int currentGrades = subjects[i].gradeCount;
        if(currentAverage < worstAverage) {
            worstAverage = currentAverage;
            worstIndex = i;
            maxGrades = currentGrades;
        } else if (currentAverage == worstAverage && currentGrades > maxGrades) {
            worstIndex = i;
            maxGrades = currentGrades;
            }
        }
        return subject[worstIndex].name;
    }
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student: " << student.fullName << "\n";
    os << "Group: " << student.groupName << "\n";
    os << "Specialty: " << student.specialty << "\n";
    os << "Subjects and grades: \n";

    for (int i = 0; i < student.subjectCount; ++i) {
        os << " " << student.subjects[i].name << ": ";
        for (int j = 0; j < student.subject[i].gradeCount; ++j) {
            os << student.subjects[i].grades[j] << " ";
        }
        os << "(Avg: )" << student.getAverageGradeBySubject(student.subjects[i].name) << ")\n";
    }
    os << "Overall average: " << student.getOverallAverage() << "\n";
    os << "Best subject: " << student.getBestSubject() << "\n";
    os << "Worst subject: " << student.getWorstSubject() << "\n";
    }
    return os;
}