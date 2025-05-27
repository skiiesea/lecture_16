#include <string>

class Students {
    public:
        // Установка группы студента
        void set_group(std::string student_group)
        {
            group = student_group;
        }
        // Получение группы студента
        std::string get_group()
        {
            return group;
        }
        // Установка имени студента
        void set_name(std::string student_name)
        {
            name = student_name;
        }
        // Получение имени студента
        std::string get_name()
        {
            return name;
        }
        // Установка фамилии студента
        void set_last_name(std::string student_last_name)
        {
            last_name = student_last_name;
        }
        // Получение фамилии студента
        std::string get_last_name()
        {
            return last_name;
        }
        // Установка отчества студента
        void set_patronymic(const std::string& student_patronymic)
        {
            patronymic = student_patronymic;
        }
        // Получение отчества студента
        std::string get_patronymic() const {
            return patronymic;
        }
        // Установка промежуточных оценок
        void set_scores(int student_scores[])
        {
            for (int i = 0; i < 5; ++i) {
                scores[i] = student_scores[i];
            }
        }
        // Установка среднего балла
        void set_average_ball(float ball)
        {
            average_ball = ball;
        }
        // Получение среднего балла
        float get_average_ball()
        {
            return average_ball;
        }

    private:
        // Промежуточные оценки
        int scores[5];
        // Средний балл
        float average_ball; 
        // Имя
        std::string name;
        // Фамилия
        std::string last_name;
        // Отчество
        std::string patronymic;
        // Группа
        std::string group;
};