#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

vector<tuple<int, int, char>> lz77_compress(const string& data) {
    vector<tuple<int, int, char>> compressed;
    int i = 0;
    int n = data.size();

    while (i < n) {
        string match = "";
        int match_position = 0;

        // Вікно для пошуку
        int search_start = max(0, i - 255);
        int search_end = i;

        // Пошук найкращого збігу
        for (int j = search_start; j < search_end; j++) {
            int k = 0;

            // Поки символи збігаються
            while ((i + k < n) && (data[j + k] == data[i + k])) {
                k++;
                if ((j + k) >= i) { // щоб уникнути посилання на себе
                    break;
                }
            }

            // Якщо знайдено кращий збіг
            if (k > static_cast<int>(match.size())) {
                match = data.substr(j, k);
                match_position = j;
            }
        }

        // Додати до стисненого результату
        if (!match.empty()) {
            char next_char = (i + match.size() < n) ? data[i + match.size()] : '\0';
            compressed.emplace_back(match_position, match.size(), next_char);
            i += match.size() + 1; // переходимо до наступного символу
        }
        else {
            compressed.emplace_back(0, 0, data[i]); // не знайдено збігу
            i++;
        }
    }

    return compressed;
}

void lab_5_task_3() 
{
    string data = "ABABABABA";
    auto compressed_data = lz77_compress(data);

    cout << "Дані до стиснення: " << data << endl;
    cout << "Стиснені дані: ";
    for (const auto& item : compressed_data) {
        int position = get<0>(item);
        int length = get<1>(item);
        char next_char = get<2>(item);

        cout << "(" << position << ", " << length << ", " << (next_char ? next_char : ' ') << ") ";
    }
    cout << endl;

}
