#include "ladder.h"
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void error(string word1, string word2, string msg) {
    cout << msg << word1 << word2;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int str1_len = length(str1);
    int str2_len = length(str2);

    if (str1_len - str2_len > d || str2_len - str1_len > d)
        return false;
    
    int str1_index = 0;
    int str2_index = 0;
    int difference = 0;

    for (; str1_index < str1_len && str2_index < str2_len; ++str1_index, ++str2_index) {
        if (str1[str1_index] != str2[str2_index]) {
            if (str1_index == str2_index)
                str1_len > str2_index ? ++str1_index, --str2_index : ++str2_index, --str1_index;
            else {
                return false;
            }
        }
    }
    return true;
}

bool is_adjacent(const string& word1, const string& word2) {
    if (length(word1) != length(word2))
        return false;

    int length = length(word1);
    int difference = 0;
    for (int i = 0; i < length; ++i) {
        if (word1[i] != word2[i])
            ++difference;
    }

    return difference <= 1;
}

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
            if (is_adjacent(last_word, *word_list_it) || edit_distance_within(last_word, *word_list_it, 1)) {
                if (!visited.find(*word_list_it)) {
                    visited.insert(*word_list_it);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(*word_list_it);
                    if (*word_list_it == end_word)
                        return new_ladder;
                    ladder_queue.push_back(new_ladder);
                }
            }
        }
    }
    return [];
}


void load_words(set<string> & word_list, const string& file_name) {
    fstream read_file;
    read_file.open(file_name);
    string word;
    while (read_file >> word)
        word_list.push_back(word);
    read_file.close();
}


void print_word_ladder(const vector<string>& ladder) {
    for (auto word : ladder)
        cout << word << " ";
}


void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}

