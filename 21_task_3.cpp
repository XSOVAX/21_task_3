#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> splitString(string const& str, char const& separator)
{
    vector<string> words;
    string word;
    stringstream ss(str);
    while (getline(ss, word, separator))
    {
        if (word.length() != 0)
        {
            words.push_back(word);
        }
    }
    return words;
}

string getUserString(const string& text)
{
    printf("%s", text.c_str());
    string user_input;
    getline(cin, user_input);
    return splitString(user_input, ' ')[0];
}

bool isNumeric(string& number)
{
    if (number.begin() == number.end())
        return false;
    auto it = find_if(number.begin(), number.end(), [](char const& c)
        { return !isdigit(c); });
    return it == number.end();
}

int getNumber(string text)
{
    string user_input;
    while (true)
    {
        user_input = getUserString(text);
        if (isNumeric(user_input))
            break;
        cout << "Это должно быть число!\n";
    }
    return stoi(user_input);
}



int main()
{
	setlocale(LC_ALL, "Russian");


}