// fileLab.8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//
//
//Написать программу, которая считывает текст из файла и выводит на экран только
//предложения, содержащие введенное с клавиатуры слово.


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string keyword, line, sentence;
    string filename = "myFile2.txt";

    string fileContent = "C++ is a leading programming language used in game development, virtual reality, real-time simulation and high-frequency trading, where efficiency and speed matter. I love programming";

    ofstream outfile(filename);
    outfile << fileContent;
    outfile.close();

    cout << "Enter a keyword: ";
    cin >> keyword;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    while (getline(file, line)) {
        stringstream ss(line);

        while (getline(ss, sentence, '.')) {
            stringstream sentenceStream(sentence);
            bool found = false;

            string word;
            while (sentenceStream >> word) {
                if (word == keyword) {
                    found = true;
                    break;
                }
            }

            if (found) {
                cout << sentence << "." << endl;  
            }
        }
    }

    file.close();

    cout << "End of program." << endl;

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
