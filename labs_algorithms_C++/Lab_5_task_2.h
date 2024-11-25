#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class EncodingTable {
private:
    map<char, string> encoding;
    map<string, char> decoding;

public:
    void add_encoding(char ch, const string& code) {
        // Додає кодування символу
        encoding[ch] = code;
        decoding[code] = ch;
    }

    string encode(const string& text) {
        // Кодує текст, перетворюючи кожен символ у відповідний код
        string encoded_text;
        for (char ch : text) {
            if (encoding.count(ch)) {
                encoded_text += encoding[ch];
            }
            else {
                encoded_text += ch; // Залишає символ без змін, якщо кодування не знайдено
            }
        }
        return encoded_text;
    }

    string decode(const string& encoded_text) {
        // Декодує закодований текст, перетворюючи коди назад у символи
        string decoded_text;
        string code;
        for (char ch : encoded_text) {
            code += ch;
            if (decoding.count(code)) {
                decoded_text += decoding[code];
                code.clear(); // Скидаємо код, коли він успішно декодований
            }
        }
        return decoded_text;
    }
};

void lab_5_task_2() 
{
    EncodingTable table;

    // Додаємо кодування
    table.add_encoding('A', "01");
    table.add_encoding('B', "10");
    table.add_encoding('C', "11");

    // Кодуємо текст
    string text = "ABCA";
    string encoded_text = table.encode(text);
    cout << "Кодований текст: " << encoded_text << endl;

    // Декодуємо текст
    string decoded_text = table.decode(encoded_text);
    cout << "Декодований текст: " << decoded_text << endl;

}
