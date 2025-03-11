#include "ladder.h"


void error(string word1, string word2, string msg) {
    cout << msg << word1 << word2;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d);
bool is_adjacent(const string& word1, const string& word2);

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    vector<vector<string>> ladder_queue;
    ladder_queue.push([begin_word]);
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop_front();
        string last_word = ladder.back();
        for (iterator word_list_it = word_list.begin(); word_list_it != word_list.end(); ++word_list_it) {
            if (is_adjacent(last_word, *word_list_it)) {
                if (!visited.find(*word_list_it)) {
                    visited.insert(*word_list_it);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(*word_list_it);
                    if (*word_list_it == end_word)
                        return new_ladder;

                }
            }
        }

    }

}


void load_words(set<string> & word_list, const string& file_name);


void print_word_ladder(const vector<string>& ladder);


void verify_word_ladder();
