#include <iostream>
#include "Student.hpp"

int main()
{
    // Создание объекта класса Student
    Students student;

    std::string name;
    std::string last_name;

    // Ввод имени с клавиатуры
    std::cout << "Name: ";
    getline(std::cin, name);

    // Ввод фамилии
    std::cout << "Last name: ";
    getline(std::cin, last_name);

    // Сохранение имени и фамилии в объект класса Students
    student.set_name(name);
    student.set_last_name(last_name);

    // Оценки
    int scores[5];
    // Сумма всех оценок
    int sum = 0;

    // Ввод промежуточных оценок 
    for (int i = 0; i < 5; ++i) {
        std::cout << "Score " << i+1 << ": ";
        std::cin >> scores[i];
        // суммирование
        sum += scores[i];
    }

    // Сохраняем промежуточные оценки в объект класса Student
    student.set_scores(scores);
    // Считаем средний балл
    float average_ball = sum / 5.0;
    // Сохраняем средний балл в объект класса Students
    student.set_average_ball(average_ball);
    // Выводим данные по студенту
    std::cout << "Average ball for " << student.get_name() << " "
         << student.get_last_name() << " is "
         << student.get_average_ball() << std::endl;

    return 0;
}