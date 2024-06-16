#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

// ������� ��� ��������, �������� �� ������ ������
bool isLetter(char c) {
    return isalpha(static_cast<unsigned char>(c));
}

// ������� ��� ���������� ������ �� �����
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
    const string filename = "input1.txt"; // ��� ����� � ��������� �������
    int n;
    
    // ������ ����� ����
    cout << "������� ����� ���� (n): ";
    cin >> n;
    
    // �������� �����
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "�� ������� ������� ����." << endl;
        return 1;
    }
    
    vector<string> words;
    string line;
    
    // ������ ����� ���������
    while (getline(file, line)) {
        vector<string> lineWords = splitIntoWords(line);
        for (const string& word : lineWords) {
            if (word.length() == n) {
                words.push_back(word);
            }
        }
    }
    
    file.close();
    
    // ���������� ���� � ���������� �������
    sort(words.begin(), words.end());
    
    // ����� ����
    cout << "����� ������ " << n << " � ���������� �������:" << endl;
    for (const string& word : words) {
        cout << word << endl;
    }
    
    return 0;
}
