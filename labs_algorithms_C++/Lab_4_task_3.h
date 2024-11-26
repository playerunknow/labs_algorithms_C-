#pragma once
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>


using namespace std;


// База Deputyів
unordered_map<int, unordered_map<string, string>> deputies = 
{
    {1, {{"name", "Deputy 1"}, {"party", "Партія A"}, {"vote", "None"}}},
    {2, {{"name", "Deputy 2"}, {"party", "Партія B"}, {"vote", "None"}}},
    {3, {{"name", "Deputy 3"}, {"party", "Партія A"}, {"vote", "None"}}}
};

// Функція для проведення голосування
unordered_map<string, int> vote_on_issue(const string& issue, const unordered_map<int, string>& votes) {
    cout << "Voting on a question: " << issue << endl;

    // Оновлення голосів
    for (auto& deputy : deputies) 
    {
        int dep_id = deputy.first;
        auto& dep_info = deputy.second;

        if (votes.find(dep_id) != votes.end()) 
        {
            dep_info["vote"] = votes.at(dep_id);
        }
        else 
        {
            dep_info["vote"] = "abstained";
        }
    }

    // Підрахунок голосів
    unordered_map<string, int> results = { {"for", 0}, {"against", 0}, {"abstained", 0} };
    for (const auto& deputy : deputies) 
    {
        const auto& dep_info = deputy.second;
        string vote = dep_info.at("vote");

        // Перевіряємо, чи є голос у результатах, щоб уникнути помилок
        if (results.find(vote) != results.end()) 
        {
            results[vote]++;
        }
    }

    // Вивід результатів
    cout << "Results: ";
    for (const auto& result : results) 
    {
        cout << result.first << ": " << result.second << " ";
    }
    cout << endl;

    return results;
}

// Головна функція
void lab_4_task_3()
{
    unordered_map<int, string> votes = { {1, "for"}, {3, "against"}, {2, "abstained"} };
    vote_on_issue("Budget questions", votes);
}
