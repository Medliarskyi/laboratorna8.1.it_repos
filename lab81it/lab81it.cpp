#include <iostream>
#include <cstring>

using namespace std;

// Функція для перевірки наявності всіх букв "while"
bool containsAllLetters(const char* str, const char* letters) {
    while (*letters) {
        if (!strchr(str, *letters)) {
            return false; // Якщо не знайдено букву, повертаємо false
        }
        letters++;
    }
    return true; // Якщо всі букви знайдені
}

// Функція для заміни "while" на ""
void replaceWhileWithStars(char* str) {
    const char* target = "while";
    size_t targetLength = strlen(target);
    char* position = strstr(str, target); // Знайти "while" у рядку

    while (position != nullptr) {
        // Заміна "while" на ""
        position[0] = '*';
        position[1] = '*';

        // Переміщення решти рядка
        strcpy_s(&position[2], strlen(position + targetLength) + 1, position + targetLength);

        // Знову шукаємо "while" у оновленому рядку
        position = strstr(position + 2, target);
    }
}

int main() {
    const char* letters = "while";
    char input[256];

    cout << "Enter a string: ";
    cin.getline(input, 256);

    if (containsAllLetters(input, letters)) {
        cout << "The string contains all letters from 'while'." << endl;
    }
    else {
        cout << "The string does not contain all letters from 'while'." << endl;
    }

    replaceWhileWithStars(input);
    cout << "Modified string: " << input << endl;

    return 0;
}