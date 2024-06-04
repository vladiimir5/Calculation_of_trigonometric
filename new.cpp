#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath> // Для pow и M_PI
#include <math.h>
#include <vector>

using namespace std;

//структура считываемых данных
struct TrigonometricData 
{
    std::string name_of_trigonometric_operation;
    double trigonometric_operation_argument;
    int accuracy_of_calculation_trigonometric_operation;
};


//Чтение данных с определенной структурой из файла
vector <TrigonometricData> read_trigonometric_data(const string& filename)
{
    vector <TrigonometricData> data_list;

    std::ifstream infile(filename);

    if (!infile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return data_list;
    }

    TrigonometricData data;

    while (infile >> data.function_name >> data.argument >> data.precision) {
        data_list.push_back(data);
    }

    infile.close();

    return data_list;
}


// Функция для вычисления факториала числа для прямых тригонометрических функций(синус, косинус, тангенс, котангенс)
unsigned long long calculating_factorial_of_number_for_direct_trigonometric_functions(unsigned int n)
{
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) 
    {
        result *= i;
    }
    return result;
}


// Функция для вычисления факториала числа для обратных тригонометрических функций(арксинус, арккосинус, арктангенс, арккотангенс)
int calculating_factorial_of_number_for_inverse_trigonometric_functions(int n) 
{
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * calculating_factorial_of_number_for_inverse_trigonometric_functions(n - 1);
    }
}


// Функция для вычисления синуса по формуле ряда Тейлора
double sine(double trigonometric_operation_argument)
{
    double sum = 0.0;
    for (unsigned int i = 0; i <= 16; ++i) {
        if ((i % 2) == 0) { // Для четных степеней знак "+" перед членом
            sum += pow(-1, i) * (pow(trigonometric_operation_argument, 2 * i + 1)) / calculating_factorial_of_number_for_direct_trigonometric_functions(2 * i + 1);
        }
        else { // Для нечетных степеней знак "-" перед членом
            sum -= pow(-1, i) * (pow(trigonometric_operation_argument, 2 * i + 1)) / calculating_factorial_of_number_for_direct_trigonometric_functions(2 * i + 1);
        }
    }
    return sum;
}


// Функция для вычисления косинуса по формуле ряда Тейлора
double cosine(double trigonometric_operation_argument)
{
    double sum = 1.0; // Начинаем с 1, так как первый член ряда равен 1
    for (unsigned int i = 1; i <= 16; ++i) {
        if ((i % 2) != 0) { // Для нечетных степеней знак "-" перед членом
            sum -= pow(-1, i) * (pow(trigonometric_operation_argument, 2 * i) / calculating_factorial_of_number_for_direct_trigonometric_functions(2 * i));
        }
        else { // Для четных степеней знак "+" перед членом
            sum += pow(-1, i) * (pow(trigonometric_operation_argument, 2 * i) / calculating_factorial_of_number_for_direct_trigonometric_functions(2 * i));
        }
    }
    return sum;
}


// Функция для вычисления тангенса
double tggg(double trigonometric_operation_argument)
{
    return sine(trigonometric_operation_argument) / cosine(trigonometric_operation_argument);
}


// Функция для вычисления котангенса
double ctggg(double trigonometric_operation_argument)
{
    return cosine(trigonometric_operation_argument) / sine(trigonometric_operation_argument);
}


// Функция для вычисления арксинуса по формуле Маклорена
double arcsine(double trigonometric_operation_argument)
{
    double sum = 0.0;
    for (unsigned int i = 0; i <= 16; ++i) 
    {
        if ((i % 2) == 0) { // Для четных степеней знак "+" перед членом
            sum += pow(-1, i) * (pow(trigonometric_operation_argument, 2 * i + 1) / calculating_factorial_of_number_for_inverse_trigonometric_functions(2 * i + 1));
        }
        else { // Для нечетных степеней знак "-" перед членом
            sum -= pow(-1, i) * (pow(trigonometric_operation_argument, 2 * i + 1) / calculating_factorial_of_number_for_inverse_trigonometric_functions(2 * i + 1));
        }
    }
    return sum;
}


// Функция для вычисления арккосинуса по формуле Маклорена
double arccosine(double trigonometric_operation_argument) 
{
    double sum = 0.0;
    for (unsigned int i = 0; i <= 16; ++i) 
    {
        if ((i % 2) == 0) { // Для четных степеней знак "+" перед членом
            sum += pow(-1, i) * (pow(trigonometric_operation_argument, 2 * i + 1) / calculating_factorial_of_number_for_inverse_trigonometric_functions(2 * i + 1));
        }
        else { // Для нечетных степеней знак "-" перед членом
            sum -= pow(-1, i) * (pow(trigonometric_operation_argument, 2 * i + 1) / calculating_factorial_of_number_for_inverse_trigonometric_functions(2 * i + 1));
        }
    }
    return sum;
}


// Функция для вычисления арктангенса
double arctggg(double trigonometric_operation_argument)
{
    return arcsine(trigonometric_operation_argument) / arccosine(trigonometric_operation_argument);
}


// Функция для вычисления арккотангенса
double arcсtggg(double trigonometric_operation_argument)
{
    return arccosine(trigonometric_operation_argument) / arcsine(trigonometric_operation_argument);
}


// Функция для вычисления секанса
double secans(double trigonometric_operation_argument)
{
    return 1 / cosine(trigonometric_operation_argument);
}


// Функция для вычисления кoсеканса
double cosecans(double trigonometric_operation_argument)
{
    return 1 / arcsine(trigonometric_operation_argument);
}


/* Функция для определения какая тригонометрическая операция будет вычисляться
int determining_which_trigonometric_operation_calculated(string name_of_trigonometric_operation)
{
    int trigonometric_operation_code = 0;
    if ((name_of_trigonometric_operation.compare("sin")) == 0)
    {
        trigonometric_operation_code = 111;
        return sine();
    }
    if ((name_of_trigonometric_operation.compare("cos")) == 0)
    {
        trigonometric_operation_code = 222;
        return trigonometric_operation_code;
    }
    if ((name_of_trigonometric_operation.compare("tg")) == 0)
    {
        trigonometric_operation_code = 333;
        return trigonometric_operation_code;
    }
    if ((name_of_trigonometric_operation.compare("ctg")) == 0)
    {
        trigonometric_operation_code = 111;
        return trigonometric_operation_code;
    }
    if ((name_of_trigonometric_operation.compare("arcsin")) == 0)
    {
        return trigonometric_operation_code;
    }
    if ((name_of_trigonometric_operation.compare("arccos")) == 0)
    {
        return trigonometric_operation_code;
    }
    if ((name_of_trigonometric_operation.compare("arctg")) == 0)
    {
        return trigonometric_operation_code;
    }
    if ((name_of_trigonometric_operation.compare("arcctg")) == 0)
    {
        return trigonometric_operation_code;
    }
    if ((name_of_trigonometric_operation.compare("sec")) == 0)
    {
        return trigonometric_operation_code;
    }
    if ((name_of_trigonometric_operation.compare("cosec")) == 0)
    {
        return trigonometric_operation_code;
    }
}*/


//Функция для вычисления тригонометрической операции
double calculating_trigonometric_operation(string name_of_trigonometric_operation, double trigonometric_operation_argument)
{
    if ((name_of_trigonometric_operation.compare("sin")) == 0)
    {
        return sine(trigonometric_operation_argument);
    }
    else if ((name_of_trigonometric_operation.compare("cos")) == 0)
    {
        return cosine(trigonometric_operation_argument);
    }
    else if ((name_of_trigonometric_operation.compare("tg")) == 0)
    {
        return tggg(trigonometric_operation_argument);
    }
    else if ((name_of_trigonometric_operation.compare("ctg")) == 0)
    {
        return ctggg(trigonometric_operation_argument);
    }
    else if ((name_of_trigonometric_operation.compare("arcsin")) == 0)
    {
        return arcsine(trigonometric_operation_argument);
    }
    else if ((name_of_trigonometric_operation.compare("arccos")) == 0)
    {
        return arccosine(trigonometric_operation_argument);
    }
    else if ((name_of_trigonometric_operation.compare("arctg")) == 0)
    {
        return arctggg(trigonometric_operation_argument);
    }
    else if ((name_of_trigonometric_operation.compare("arcctg")) == 0)
    {
        return arcсtggg(trigonometric_operation_argument);
    }
    else if ((name_of_trigonometric_operation.compare("sec")) == 0)
    {
        return secans(trigonometric_operation_argument);
    }
    else if ((name_of_trigonometric_operation.compare("cosec")) == 0)
    {
        return cosecans(trigonometric_operation_argument);
    }
}

int main()
{
    //Сделать ввод данных с файла, если ошибка в чем-нибудь, то выводить ошибку в консоль, если все правильно, записывать в файл
    //Сделать тут проверку данных с файла
    TrigonometricData data;
    data = read_trigonometric_data("dataset.txt");

    /*string name_of_trigonometric_operation = "sin";
    double trigonometric_operation_argument = 30;
    int accuracy_of_calculation_trigonometric_operation = 5;*/

    double result_of_calculating_trigonometric_operation = calculating_trigonometric_operation(data.name_of_trigonometric_operation, data.trigonometric_operation_argument);

    string filename = "rounded_number.txt";
    ofstream outfile(filename);
    outfile << std::fixed << std::setprecision(data.accuracy_of_calculation_trigonometric_operation) << std::setfill('0') << result_of_calculating_trigonometric_operation;
    outfile.close();
}