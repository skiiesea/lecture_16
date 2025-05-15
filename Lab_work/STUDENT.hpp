#include <iostream>
#include <utility>
#include <stdexcept>
#include <cstring>
class Student {
private:
    static const int MAX_NAME_LEN = 100;
    static const int MAX_GROUP_LEN = 20;
    static const int MAX_SPECIALTY_LEN = 50;
    static const int MAX_SUBJECTS = 5;
    static const int MAX_GRADES_PER_SUBJECT = 20;

    char fullName[MAX_NAME_LEN];
    char groupName[MAX_GROUP_LEN];
    char specialty[MAX_SPECIALTY_LEN];

    struct Subject {
        char name[MAX_NAME_LEN];
        int grades[MAX_GRADES_PER_SUBJECT];
        int gradeCount;
    } subjects[MAX_SUBJECTS];

    int subjectCount;

public:
    Student(const char* name, const char* group, const char* specialty);
    void setFullName(const char* name);
    void setGroupNumber(const char* group);
    void setSpecialty(const char* specialty);
    void addSubject(const char* subject);
    void addGrade(const char* subject, int grade);

    const char* getFullName() const;
    const char* getGroupNumber() const;
    const char* getSpecialty() const;

    double getAverageGradeBySubject(const char* subject) const;
    double getOverallAverage() const;
    const char* getBestSubject() const;
    const char* getWorstSubject() const;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

