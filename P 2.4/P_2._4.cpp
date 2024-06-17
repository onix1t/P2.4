#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

// Функция для проверки, является ли символ буквой
bool isLetter(char c) {
    return isalpha(static_cast<unsigned char>(c));
}

// Функция для разделения строки на слова
vector<string> splitIntoWords(const string& str) {
    vector<string> words;
    string word;
    for (char c : str) {
        if (isLetter(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Практика 4 | Вариант 22\r\n";
    cout << "\r\nЗадание 1\r\n";
    
    const string filename = "input1.txt"; // Имя файла с заданными словами
    int n;
    
    // Запрос длины слов
    cout << "Введите длину слов (n): ";
    cin >> n;
    
    // Открытие файла
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл." << endl;
        return 1;
    }
    
    vector<string> words;
    string line;
    
    // Чтение файла построчно
    while (getline(file, line)) {
        vector<string> lineWords = splitIntoWords(line);
        for (const string& word : lineWords) {
            if (word.length() == n) {
                words.push_back(word);
            }
        }
    }
    
    file.close();
    
    // Сортировка слов в алфавитном порядке
    sort(words.begin(), words.end());
    
    // Вывод слов
    cout << "Слова длиной " << n << " в алфавитном порядке:" << endl;
    for (const string& word : words) {
        cout << word << endl;
    }

    cout << "\r\nЗадание 2\r\n";
    
    const string inputFilename = "input2.txt";  // Имя входного файла
    const string outputFilename = "output2.txt"; // Имя выходного файла

    // Открытие входного файла
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть входной файл." << endl;
        return 1;
    }

    vector<int> numbers;
    int number;

    // Чтение чисел из входного файла
    while (inputFile >> number) {
        numbers.push_back(number);
    }
    inputFile.close();

    // Открытие выходного файла
    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Не удалось открыть выходной файл." << endl;
        return 1;
    }

    // Запись квадратов чисел в выходной файл
    for (int num : numbers) {
        outputFile << num * num << " ";
    }
    outputFile.close();

    cout << "Квадраты чисел записаны в выходной файл." << endl;
    cout << "\r\nОчистить выходной файл? (Y/N)\r\n";
    char clearCom;
    cin >> clearCom;
    if (clearCom == 'Y' || clearCom == 'y')
    {
        ofstream outputFile(outputFilename, ios::trunc);
        cout << "Выходной файл очищен";
    }

    return 0;
}
