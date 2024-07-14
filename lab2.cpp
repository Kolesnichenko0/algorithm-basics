#include <iostream>

using std::ostream;

class Interval {
    friend ostream& operator<<(ostream& out, Interval& interval);
private:
    double start; //початок інтервалу
    double end; //кінець інтервалу
    double middle; //середина інтервалу
    int number; //номер інтервалу
    int incidence = 0; //частота, кількість спостережень, що належить інтервалу 
public:
    //Конструктор для створення об'єкту інтервалу
    Interval(int number, double start, double end, int k) : 
        number(number), start(k * start), end(k * end) {
        this->middle = k* (start + end) / 2;
    }
    //Сеттер для встановлення значення частоти
    void setIncidence(double** temp_matrix, const int rows, const int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (temp_matrix[i][j] >= start && temp_matrix[i][j] <= end) {
                    incidence += 1;
                }
            }
        }
    }
    
};

//Перевантаження операції виведення інмаорції про інтервал
ostream& operator<<(ostream& out, Interval& interval) {
    out << "       " << interval.number << "\t      " << "[" << interval.start << ", " << interval.end << "]\t       " << interval.middle << "\t\t " << interval.incidence << "\n";
    return out;
}

void createIntervals(Interval* intervals[], int k) {
    //Створення об'єктів інтервалів у динамічній пам'яті 
    intervals[0] = new Interval(1, 10, 12, k);
    intervals[1] = new Interval(2, 12, 14, k);
    intervals[2] = new Interval(3, 14, 16, k);
    intervals[3] = new Interval(4, 16, 18, k);
    intervals[4] = new Interval(5, 18, 20, k);
    intervals[5] = new Interval(6, 20, 22, k);
    intervals[6] = new Interval(7, 22, 24, k);
}

int main()
{
    //Створення можливості записання на тексту у консоль на українській мові
    setlocale(LC_ALL, "UKR");

    //Ініціалізування розмірів необхідної матриці та кількість інтервалів
    const int rows = 8;
    const int cols = 7;
    const int number_of_intervals = 7;

    //Ініціалізування початкової матриці у вигляді масиву
    double first_matrix[rows][cols] = { {20.3, 15.4, 17.2, 19.2, 23.3, 18.1, 21.9},
                                        {15.3, 16.8, 13.2, 20.4, 16.5, 19.7, 20.5},
                                        {14.3, 20.1, 16.8, 14.7, 20.8, 19.5, 15.3},
                                        {19.3, 17.8, 16.2, 15.7, 22.8, 21.9, 12.5},
                                        {10.1, 21.1, 18.3, 14.7, 14.5, 18.1, 18.4},
                                        {13.9, 19.1, 18.5, 20.2, 23.8, 16.7, 20.4},
                                        {19.5, 17.2, 19.6, 17.8, 21.3, 17.5, 19.4},
                                        {17.8, 13.5, 17.8, 11.8, 18.6, 19.1, 19.5} };

    //Ініціалізування числа k та введення числа k через консоль
    int k;
    std::cout << "Введiть k з запронованих {12, 16, 31}:" << std::endl;
    std::cin >> k;

    //Перевірка числа k на валідність
    if (k != 12 && k != 16 && k != 31) {
        //Виведення помилки у консоль
        std::cout << "Неправильне значення k" << std::endl;
        //Завершення виконування програми
        return 0;
    }
    std::cout << "Розрахунок..." << std::endl;

    //Ініціалізування матриці A у вигляді масиву
    double **temp_matrix = new double*[rows]; //виділення пам'яті під рядки

    //Множення початкової матриці на k для знаходження матриці А
    for (int i = 0; i < rows; i++) {
        temp_matrix[i] = new double[cols]; //виділення пам'яті під елементи рядка i
        for (int j = 0; j < cols; j++) {
            temp_matrix[i][j] = k * first_matrix[i][j];
        }
    }

    //Виведення матриці А у консоль
    std::cout << "Матриця, з якою працює програма:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << temp_matrix[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //Створення масиву вказівників на інтервали
    Interval *intervals[number_of_intervals];

    //Створення інтервалів 
    createIntervals(intervals, k);

    //Розрахунок частот
    for (int i = 0; i < number_of_intervals; i++) {
        intervals[i]->setIncidence(temp_matrix, rows, cols);
    }

    std::cout << "Частота - кiлькiсть спостережень, що належать певному iнтервалу\n";
    std::cout << "Таблиця частот:\n";
    std::cout << "Номер iнтервалу     Межi iнтервалу     Середина iнтервалу     Частота\n\n";

    //Вивід інтервалів у консоль
    for (int i = 0; i < number_of_intervals; i++) {
        std::cout << *intervals[i] << std::endl;
    }

    //Видалення з динамічної пам'яті temp_matrix
    for (int i = 0; i < rows; i++) {
        delete[] temp_matrix[i];
    }
    delete[] temp_matrix;

    //Видалення з динамічної пам'яті об'єктів інтервалів
    for (int i = 0; i < number_of_intervals; i++) {
        delete intervals[i];
    }

    return 0;
}
