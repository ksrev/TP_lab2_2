#include "helper.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

bool isSplitterSuggestion(const char& ch) {
	return ch == '.' || ch == '?' || ch == '!' || ch == '\n' || ch == '\0';
}

string task(const string& s) {
	string questians, exclamation;
	bool isWord = false, isSuggestion = false;
	int startSuggestoin = 0;
	int number = 1;
	for (int i = 0; i < s.size(); i++)
		if (isSplitterSuggestion(s[i])) {
			if (s[i] == '?')
				questians.append(s.substr(startSuggestoin, i + 1 - startSuggestoin));
			else if (s[i] == '!')
				exclamation.append(s.substr(startSuggestoin, i + 1 - startSuggestoin));
			startSuggestoin = i + 1;
		}
	string ans = questians + exclamation;
	return !ans.empty() ? ans : "В файле нет восклицательных и вопросительных предложений\n";
}

string readFile(ifstream& input) {
	string s = "";
	string tmpS;
	while (getline(input, tmpS))
		s.append(tmpS).append("\n");
	return s;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename;
	processInputNameOfInputFile(filename);
	ifstream input(filename);
	cout << "Результат работы:\n" << task(readFile(input));
	input.close();
}