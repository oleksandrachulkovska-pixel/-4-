#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <clocale>

using namespace std;

class Angle
{
private:
    int degrees;
    int minutes;

    int totalMinutes() const
    {
        return degrees * 60 + minutes;
    }

    void normalize()
    {
        int total = totalMinutes();
        const int fullCircle = 360 * 60;

        total %= fullCircle;

        if (total < 0)
            total += fullCircle;

        degrees = total / 60;
        minutes = total % 60;
    }

public:
    // Конструктор за замовчуванням
    Angle()
    {
        degrees = 0;
        minutes = 0;
        cout << "Викликано конструктор за замовчуванням." << endl;
    }

    // Конструктор з параметрами
    Angle(int d, int m)
    {
        degrees = d;
        minutes = m;
        normalize();
        cout << "Викликано конструктор з параметрами." << endl;
    }

    // Конструктор копіювання
    Angle(const Angle& other)
    {
        degrees = other.degrees;
        minutes = other.minutes;
        cout << "Викликано конструктор копіювання." << endl;
    }

    // Деструктор
    ~Angle()
    {
        cout << "Викликано деструктор Angle." << endl;
    }

    // Ініціалізація об'єкта
    void Init(int d = 0, int m = 0)
    {
        degrees = d;
        minutes = m;
        normalize();
    }

    // Введення даних
    void Read()
    {
        cout << "Введіть градуси: ";
        cin >> degrees;

        cout << "Введіть хвилини: ";
        cin >> minutes;

        normalize();
    }

    // Виведення даних
    void Display() const
    {
        cout << degrees << "° " << minutes << "'" << endl;
    }

    // Перетворення в рядок
    string toString() const
    {
        ostringstream out;
        out << degrees << "° " << minutes << "'";
        return out.str();
    }

    // Переведення у радіани
    double toRadians() const
    {
        const double PI = 3.14159265358979323846;
        double angleInDegrees = degrees + minutes / 60.0;

        return angleInDegrees * PI / 180.0;
    }

    // Нормалізація кута
    void normalizeAngle()
    {
        normalize();
    }

    // Збільшення кута
    void increase(int d, int m)
    {
        int total = totalMinutes() + d * 60 + m;

        degrees = total / 60;
        minutes = total % 60;

        normalize();
    }

    // Зменшення кута
    void decrease(int d, int m)
    {
        int total = totalMinutes() - d * 60 - m;

        degrees = total / 60;
        minutes = total % 60;

        normalize();
    }

    // Обчислення синуса
    double sine() const
    {
        return sin(toRadians());
    }

    // Порівняння двох кутів
    int compare(const Angle& other) const
    {
        int thisAngle = totalMinutes();
        int otherAngle = other.totalMinutes();

        if (thisAngle < otherAngle)
            return -1;

        if (thisAngle > otherAngle)
            return 1;

        return 0;
    }

    // Перевантаження оператора +
    Angle operator+(const Angle& other) const
    {
        return Angle(0, totalMinutes() + other.totalMinutes());
    }

    // Перевантаження оператора -
    Angle operator-(const Angle& other) const
    {
        return Angle(0, totalMinutes() - other.totalMinutes());
    }

    // Перевантаження оператора ==
    bool operator==(const Angle& other) const
    {
        return compare(other) == 0;
    }

    // Перевантаження оператора <
    bool operator<(const Angle& other) const
    {
        return compare(other) < 0;
    }

    // Перевантаження оператора >
    bool operator>(const Angle& other) const
    {
        return compare(other) > 0;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    cout << "Створення об'єктів" << endl;

    Angle angle1(30, 20);
    Angle angle2(45, 40);

    cout << "angle1 = ";
    angle1.Display();

    cout << "angle2 = ";
    angle2.Display();

    cout << endl;

    cout << "Перевірка оператора +" << endl;

    Angle sum = angle1 + angle2;

    cout << "angle1 + angle2 = ";
    sum.Display();

    cout << endl;

    cout << "Перевірка оператора -" << endl;

    Angle difference = angle2 - angle1;

    cout << "angle2 - angle1 = ";
    difference.Display();

    cout << endl;

    cout << "Перевірка оператора ==" << endl;

    if (angle1 == angle2)
        cout << "Кути рівні." << endl;
    else
        cout << "Кути не рівні." << endl;

    cout << endl;

    cout << "Перевірка оператора <" << endl;

    if (angle1 < angle2)
        cout << "angle1 менший за angle2." << endl;
    else
        cout << "angle1 не менший за angle2." << endl;

    cout << endl;

    cout << "Перевірка нормалізації" << endl;

    Angle angle3(350, 30);
    Angle angle4(20, 45);

    cout << "angle3 = ";
    angle3.Display();

    cout << "angle4 = ";
    angle4.Display();

    Angle normalizedSum = angle3 + angle4;

    cout << "angle3 + angle4 = ";
    normalizedSum.Display();

    cout << endl;

    cout << "Перевірка інших методів класу" << endl;

    cout << "Кут angle1: ";
    angle1.Display();

    cout << fixed << setprecision(6);

    cout << "angle1 у радіанах: "
        << angle1.toRadians() << endl;

    cout << "sin(angle1): "
        << angle1.sine() << endl;

    angle1.increase(10, 30);

    cout << "Після збільшення на 10° 30': ";
    angle1.Display();

    angle1.decrease(5, 15);

    cout << "Після зменшення на 5° 15': ";
    angle1.Display();

    cout << endl;

    cout << "Результат toString(): "
        << angle1.toString() << endl;

    cout << endl;

    return 0;
}