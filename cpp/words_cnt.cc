#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

struct Word_info {
    string word;
    int count;
};

void track_word(vector<Word_info> *stat, string *word) {
    bool found = false;
    auto iter = stat->begin();
    while (!found && iter != stat->end()) {
        if (iter->word == *word) {
            ++(iter->count);
            found = true;
        }
        ++iter;
    }

    if (!found) {
        Word_info info;
        info.word = *word;
        info.count = 1;
        stat->push_back(info);
    }
}

Word_info max(vector<Word_info> *stat) {
    auto iter = stat->begin();
    auto res = iter;
    while (iter != stat->end()) {
        if (iter->count > res->count) {
            res = iter;
        }
        ++iter;
    }

    return *res;
}

int main() {
    vector<Word_info> stat; 
    string input;

    getline(std::cin, input);

    auto iter = input.begin();
    auto start = iter;
    while (iter != input.end()) {
        ++iter;
        if (*iter == ' ' || iter == input.end()) {
            string word(start, iter);
            if (iter != input.end()) {
                start = iter + 1;
            }

            track_word(&stat, &word);
        }
    }

    auto res = max(&stat);

    std::cout << res.word << ':' << res.count << std::endl;
    return 0;
}