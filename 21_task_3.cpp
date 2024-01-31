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

int getNumberRange(string text, int from, int to)
{
    int number;
    do
    {
        cout << "Введите число в диапозоне от " << from << " до " << to << endl;
        number = getNumber(text);
    } while (number < from or number > to);
    return number;
}

double getDouble(const char* msg)
{
    string str_number;
    cout << msg;
    cin >> str_number;
    double number;
    try { number = stod(str_number);}
    catch (const out_of_range& e) { getDouble(msg); }
    return number;
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

MathVector createMathVector()
{
    string name = getUserString("Введите номер операции : ");
    double x = getDouble("Введите значение X координаты ветора : ");
    double y = getDouble("Введите значение X координаты ветора : ");
    MathVector vector(x, y, name);
    return vector;
}

void performOperations()
{
    cout << "Введите номер операции над векторами\n";
    vector<string>actions = {"add", "subtract", "scale", "length", "normalize", "exit"};
    for (int i = 0; i < actions.size(); ++i)
    {
        cout << actions[i] << endl;
    }
    string operation;
    do {
        operation = getUserString("Введите номер операции : ");
        if (operation == "add")
        {
            cout << "Операция сложение векторов\n";
            MathVector vectorA = createMathVector();
            MathVector vectorB = createMathVector();
            MathVector vectorC = AddVectors(vectorA, vectorB);
        }
        if (operation == "substract")
        {
            cout << "Операция вычетание векторов\n";
            MathVector vectorA = createMathVector();
            MathVector vectorB = createMathVector();
            MathVector vectorC = SubtractVectors(vectorA, vectorB);
        }
        if (operation == "substract")
        {
            cout << "Операция скалярное произведение\n";
            MathVector vector = createMathVector();
            double scale = getDouble("Введите скалярное значение : ");
            MathVector vectorC = ScaleVectors(vector, scale);
        }
        if (operation == "length")
        {
            cout << "Операция длина ветора\n";
            MathVector vector = createMathVector();
            cout << "Длина данного вектора = " << lenVector(vector);
        }
        if (operation == "normalize")
        {
            cout << "Операция нормализация ветора\n";
            MathVector vector = createMathVector();
            MathVector normal_vector = NormalizeVector(vector);
        }
    } while (operation != "exit");
}

int main()
{
	setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC, "eng");
    
    performOperations();
}