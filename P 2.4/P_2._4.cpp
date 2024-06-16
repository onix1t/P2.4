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
    
    return 0;
}
