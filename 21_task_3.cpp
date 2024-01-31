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

double getNumber(string text)
{
    string user_input;
    while (true)
    {
        user_input = getUserString(text);
        if (isNumeric(user_input))
            break;
        cout << "Это должно быть число!\n";
    }
    return stod(user_input);
}

struct MathVector {
private:  
    string name;
    vector<double> points;
public:
    MathVector()
    {
        name = "None";
        points.push_back(0);
        points.push_back(0);
    }
    MathVector(double x, double y, string nameVector)
    {
        name = nameVector;
        points.push_back(x);
        points.push_back(y);
    }
    void setVector(double x, double y, string nameVector)
    {
        points[0] = x;
        points[1] = y;
        name = nameVector;
    }
    double dataX() { return points[0]; }
    double dataY() { return points[1]; }
    string dataName() { return name; }
    void getVector()
    {
        cout << fixed << setprecision(2) << name << " = { " << points[0] << ", " << points[1] << " } ";
    }
    ~MathVector() { cout << endl << name << " is delete\n"; }
};

MathVector AddVectors(MathVector vectorA, MathVector vectorB)
{
    MathVector newVector;
    newVector.setVector(vectorA.dataX() + vectorB.dataX(), vectorA.dataY() + vectorB.dataY(), vectorA.dataName() + "+" + vectorB.dataName());
    newVector.getVector();
    return newVector;
}

MathVector SubtractVectors(MathVector vectorA, MathVector vectorB)
{
    MathVector newVector;
    newVector.setVector(vectorA.dataX() - vectorB.dataX(), vectorA.dataY() - vectorB.dataY(), vectorA.dataName() + "-" + vectorB.dataName());
    newVector.getVector();
    return newVector;
}

MathVector ScaleVectors(MathVector vector, double scale)
{
    MathVector newVector;
    newVector.setVector(scale * vector.dataX(), scale * vector.dataY() , to_string (scale) + "*" + vector.dataName());
    newVector.getVector();
    return newVector;
}

double lenVector(MathVector vector)
{
    return sqrt(pow(vector.dataX(), 2) + pow(vector.dataY(), 2));
}

MathVector NormalizeVector(MathVector vector)
{
    return ScaleVectors(vector, 1 / lenVector(vector));
}

int main()
{
	setlocale(LC_ALL, "Russian");
    MathVector v(10.6, 5.45,"gffghh");
    v.getVector();

}