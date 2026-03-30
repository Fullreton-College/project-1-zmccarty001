#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string cleanWord(string word) {
    string cleaned = "";
    for (char c : word) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

void getwords(vector<string> &words, ifstream &file) {
    string word;

    while (file >> word) {
        word = cleanWord(word);
        if (!word.empty()) {
            words.push_back(word);
        }
    }
}

vector<pair<string, int>> getWordCounts(vector<string> &words) {
    vector<pair<string, int>> counts;

    if (words.empty()) return counts;

    string current = words[0];
    int count = 1;

    for (int i = 1; i<words.size(); i++) {
        if (words[i] == current) {
            count++;
        } 
        else {
            counts.push_back(make_pair(current, count));
            current = words[i];
            count = 1;
        }
    }
    counts.push_back(make_pair(current, count));

    return counts;
}
void sortWords(vector<string> &words) {
    sort(words.begin(), words.end());
}
int main() {
    ifstream file("homes.txt");
    vector<string> words;

    getwords(words, file);
    sortWords(words);
    vector<pair<string, int>> wordCounts = getWordCounts(words);

    for (int i = 0; i < wordCounts.size(); i++) {
        cout << wordCounts[i].first << ": "
        << wordCounts[i].second << endl;
    }
    file.close();
    return 0;
}