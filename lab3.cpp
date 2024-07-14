#include <iostream>

int main()
{
    //Створення можливості записання на тексту у консоль на українській мові
    setlocale(LC_ALL, "UKR");

    //Ініціалізування розмірів необхідної матриці
    const int rows = 16;
    const int cols = 7;

    //Ініціалізування початкової матриці у вигляді масиву
    double first_matrix[rows][cols] = { {20.3, 15.4, 17.2, 19.2, 23.3, 18.1, 21.9},
                                        {15.3, 16.8, 13.2, 20.4, 16.5, 19.7, 20.5},
                                        {14.3, 20.1, 16.8, 14.7, 20.8, 19.5, 15.3},
                                        {19.3, 17.8, 16.2, 15.7, 22.8, 21.9, 12.5},
                                        {10.1, 21.1, 18.3, 14.7, 14.5, 18.1, 18.4},
                                        {13.9, 19.1, 18.5, 20.2, 23.8, 16.7, 20.4},
                                        {19.5, 17.2, 19.6, 17.8, 21.3, 17.5, 19.4},
                                        {17.8, 13.5, 17.8, 11.8, 18.6, 19.1, 19.5},
                                        {20.3, 15.4, 17.2, 19.2, 23.3, 18.1, 21.9},
                                        {15.3, 16.8, 13.2, 20.4, 16.5, 19.7, 20.5},
                                        {14.3, 20.1, 16.8, 14.7, 20.8, 19.5, 15.3},
                                        {19.3, 17.8, 16.2, 15.7, 22.8, 21.9, 12.5},
                                        {10.1, 21.1, 18.3, 14.7, 14.5, 18.1, 18.4},
                                        {13.9, 19.1, 18.5, 20.2, 23.8, 16.7, 20.4},
                                        {19.5, 17.2, 19.6, 17.8, 21.3, 17.5, 19.4},
                                        {17.8, 13.5, 17.8, 11.8, 18.6, 19.1, 19.5} 
    };

    //Ініціалізування числа k та введення числа k через консоль
    int k;
    std::cout << "Введiть k з запронованих {4, 12, 16}:" << std::endl;
    std::cin >> k;

    //Перевірка числа k на валідність
    if (k != 4 && k != 12 && k != 16) {
        //Виведення помилки у консоль
        std::cout << "Неправильне значення k" << std::endl;
        //Завершення виконування програми
        return 0;
    }
    std::cout << "Розрахунок..." << std::endl;

    //Ініціалізування матриці A у вигляді масиву
    double temp_matrix[rows][cols];

    //Множення початкової матриці на k для знаходження матриці А
    for (int i = 0; i < rows; i++) {
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

    //Ініціалізування результуючого кортежу
    double result[5];

    //Знаходження максимального та мінімального елементу матриці А
    int counter1 = 0;
    double max_all = temp_matrix[0][0];
    double min_all = temp_matrix[0][0];
    int i;
    for (i = 0; i < rows; i++, counter1++) {
        for (int j = 0; j < cols; j++, counter1++) {
            if (temp_matrix[i][j] > max_all)
                max_all = temp_matrix[i][j];
            if (temp_matrix[i][j] < min_all)
                min_all = temp_matrix[i][j];
            counter1+=2;
        }
    }

    //Знаходження розмаху вибірки усієї матриці та запис у кортеж
    double range_minall_maxall = max_all - min_all;
    result[0] = range_minall_maxall;

    std::cout << "counter1 = " << counter1 <<std::endl;
    getchar();

    //Ініціалізування змінних max_temp та min_temp для подальшого використання ,щоб записувати потрібні значення
    double min_temp;
    double max_temp;

    //Ініціалізування масиву range_column для множини для запису розмахів вибірки кожного стовпця
    double range_column[cols];
    int counter3 = 0;
    //Знаходження розмаху вибірки кожного стовпця та запис цих значень у масив range_column
    for (int i = 0; i < cols; i++, counter3++) {
        min_temp = temp_matrix[0][i];
        max_temp = temp_matrix[0][i];
        for (int j = 0; j < rows; j++, counter3++) {
            if (min_temp > temp_matrix[j][i])
                min_temp = temp_matrix[j][i];
            if (max_temp < temp_matrix[j][i])
                max_temp = temp_matrix[j][i];
            counter3 += 2;
        }
        range_column[i] = max_temp - min_temp;
    }
    std::cout << "counter 3 for cols:" << counter3 << "\n";
    //Ініціалізування масиву range_rows для множини для запису розмахів вибірки кожного рядка
    double range_rows[rows];
    int counter2 = 0;
    //Знаходження розмаху вибірки кожного рядка та запис цих значень у масив range_rows
    for (int i = 0; i < rows; i++, counter2++) {
        min_temp = temp_matrix[i][0];
        max_temp = temp_matrix[i][0];
        for (int j = 0; j < cols; j++, counter2++) {
            if (min_temp > temp_matrix[i][j])
                min_temp = temp_matrix[i][j];
            if (max_temp < temp_matrix[i][j])
                max_temp = temp_matrix[i][j];
            counter2+=2;
        }
        
        range_rows[i] = max_temp - min_temp;
    }

    //Знаходження максимального та мінімального значення серед розмахів стовпців та запис у результуючий кортеж
    double max_range_column = range_column[0];
    double min_range_column = range_column[0];
    for (int i = 0; i < cols; i++, counter3++) {
        if (range_column[i] > max_range_column)
            max_range_column = range_column[i];
        if (range_column[i] < min_range_column)
            min_range_column = range_column[i];
        counter3 += 2;

    }
    std::cout << "counter 3 for cols:" << counter3 << "\n";

    result[1] = max_range_column;
    result[2] = min_range_column;

    //Знаходження максимального та мінімального значення серед розмахів рядків та запис у результуючий кортеж
    double max_range_rows = range_rows[0];
    double min_range_rows = range_rows[0];
    for (int i = 0; i < rows; i++, counter2++) {
        if (range_rows[i] > max_range_rows)
            max_range_rows = range_rows[i];
        if (range_rows[i] < min_range_rows)
            min_range_rows = range_rows[i];
        counter2 += 2;
    }
    std::cout << counter2 << std::endl;
    result[3] = max_range_rows;
    result[4] = min_range_rows;

    //Виведення пояснень елементів результуючого кортежу у консоль
    std::cout << "Результат представлений у виглядi:" << std::endl;
    std::cout << "Перше це розмах всiєї вибiрки, яка представлена матрицею" << std::endl;
    std::cout << "Друге це максимальний розмах стовпцiв, третє це мiнiмальний розмах стовпцiв " << std::endl;
    std::cout << "Четверте це максимальний розмах рядкiв, п'яте це мiнiмальний розмах рядкiв " << std::endl;
    std::cout << "Результат:" << std::endl;
    //Виведення результуючого кортежу у консоль
    for (int i = 0; i < 5; i++) {
        std::cout << result[i] << '\t';
    }
    std::cout << std::endl;
    std::cout << "Якщо бажаєте закiнчити, напишiть будь-що окрiм {1, 2, 3} :" << std::endl;
    std::cout << "Якщо хочете вивести розмахи кожного стовпця та закiнчити, напишiть 1 :" << std::endl;
    std::cout << "Якщо хочете вивести розмахи кожного рядка та закiнчити, напишiть 2 :" << std::endl;
    std::cout << "Якщо хочете вивести розмахи кожного стовпця та кожного рядка та закiнчити, напишiть 3 :" << std::endl;
    //Ініціалізування змінної check для вибору дій та введення check через консоль
    int check;
    std::cin >> check;
    //Виконання описаних дій вище в залежності від змінної check
    if (check == 0) {
        return 0;
    }
    //Виведення розмахів кожного стовпця, записаних у масив range_column
    else if (check == 1) {
        std::cout << "Розмахи кожного стовпця:" << '\n';
        for (int i = 0; i < cols; i++)
            std::cout << range_column[i] << '\t';
        std::cout << std::endl;
    }
    //Виведення розмахів кожного рядка, записаних у масив range_rows
    else if (check == 2) {
        std::cout << "Розмахи кожного рядка:" << '\n';
        for (int i = 0; i < rows; i++) {
            std::cout << range_rows[i] << '\t';
        }
        std::cout << std::endl;
    }
    //Виведення розмахів кожного стовпця та кожного рядка, записаних у масив range_column та range_rows відповідно
    else if (check == 3) {
        std::cout << "Розмахи кожного стовпця:" << '\n';
        for (int i = 0; i < cols; i++)
            std::cout << range_column[i] << '\t';
        std::cout << std::endl;
        std::cout << "Розмахи кожного рядка:" << '\n';
        for (int i = 0; i < rows; i++) {
            std::cout << range_rows[i] << '\t';
        }
        std::cout << std::endl;
    }
    //Завершення виконування програми
    return 0;
}
