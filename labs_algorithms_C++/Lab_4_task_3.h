#pragma once
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>


using namespace std;


// База депутатів
unordered_map<int, unordered_map<string, string>> deputies = {
    {1, {{"name", "Депутат 1"}, {"party", "Партія A"}, {"vote", "None"}}},
    {2, {{"name", "Депутат 2"}, {"party", "Партія B"}, {"vote", "None"}}},
    {3, {{"name", "Депутат 3"}, {"party", "Партія A"}, {"vote", "None"}}}
};

// Функція для проведення голосування
unordered_map<string, int> vote_on_issue(const string& issue, const unordered_map<int, string>& votes) {
    cout << "Голосування по питанню: " << issue << endl;

    // Оновлення голосів
    for (auto& deputy : deputies) {
        int dep_id = deputy.first;
        auto& dep_info = deputy.second;

        if (votes.find(dep_id) != votes.end()) {
            dep_info["vote"] = votes.at(dep_id);
        }
        else {
            dep_info["vote"] = "утримався";
        }
    }

    // Підрахунок голосів
    unordered_map<string, int> results = { {"за", 0}, {"проти", 0}, {"утримався", 0} };
    for (const auto& deputy : deputies) {
        const auto& dep_info = deputy.second;
        string vote = dep_info.at("vote");

        // Перевіряємо, чи є голос у результатах, щоб уникнути помилок
        if (results.find(vote) != results.end()) {
            results[vote]++;
        }
    }

    // Вивід результатів
    cout << "Результати голосування: ";
    for (const auto& result : results) {
        cout << result.first << ": " << result.second << " ";
    }
    cout << endl;

    return results;
}

// Головна функція
int main() {
    unordered_map<int, string> votes = { {1, "за"}, {3, "проти"}, {2, "проти"} };
    vote_on_issue("Питання про бюджет", votes);
    return 0;
}
