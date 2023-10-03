// Task-4.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class Adress {

private:
    std::string city;
    std::string street;
    int house_num;
    int flat_num;

public:

    std::string get_output_address() {

        return city + ", " + street + ", " + std::to_string(house_num) + ", " + std::to_string(flat_num);
    }




    Adress(std::string city, std::string street, int house_num, int flat_num) {
        this->city = city;
        this->street = street;
        this->house_num = house_num;
        this->flat_num = flat_num;
    }

    Adress() {
        city = "Неизвестно";
        street = "Неизвестно";
        house_num = 0;
        flat_num = 0;
    }







};


int main() {

    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    std::ifstream read("in.txt");

    if (read.is_open()) {
        int size;
        read >> size;
        Adress* adress_arr = new Adress[size];


        std::string city;
        std::string street;
        int house_num;
        int flat_num;


        for (int i = 0; i < size; ++i) {

            read >> city;
            read >> street;
            read >> house_num;
            read >> flat_num;

            adress_arr[i] = { city, street, house_num, flat_num };

        }


        std::ofstream record("out.txt");

        if (record.is_open()) {

            record << size << "\n";


            for (int i = 1; i < size; ++i) {
                std::string adress_line_0 = adress_arr[i].get_output_address();
                std::string adress_line_1 = adress_arr[i - 1].get_output_address();

                char* str_0 = &adress_line_0[0];
                char* str_1 = &adress_line_1[0];

                if (strcmp(str_1, str_0) == 1) {
                    std::swap(adress_arr[i], adress_arr[i - 1]);
                }

            }

            for (int i = 0; i < size; ++i) {
                record << adress_arr[i].get_output_address() << '\n';
            }





        }
        else {
            std::cout << "The file is not opened for recording!";
        }
        record.close();



        delete[] adress_arr;



    }
    else {
        std::cout << "The file is not opened for reading!";
    }

    read.close();


















    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
