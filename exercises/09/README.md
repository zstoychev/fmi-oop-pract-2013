# Упражнение 9 — виртуални функции и подтипов полиморфизъм

Нека имаме абстрактен клас `UnaryFunction`, представящ функция на един аргумент, който има следните чисто виртуални методи:

* `value(double x)` — връща стойността на функцията в точка x;
* `derivative()` — връща производната на функцията като динамично-заделен обект;
* `clone()` — създава динамично-заделено копие на функцията.

Дефиницията на класа е следната:

    class UnaryFunction {
    public:
      virtual ~UnaryFunction() {}
      virtual double value(double x) const = 0;
      virtual UnaryFunction* derivative() const = 0;
      virtual UnaryFunction* clone() const = 0;
    };

Разделете се на двойки по двама. Нека единият от вас реализира следните наследници на `UnaryFunction`:

* клас `Polynomial` представящ алгебричен полином. Нека да се създава по подадени коефициенти и степен на полинома.
* клас `Superposition` представящ суперпозиция на две функции на един аргумент.

Другият да реализира:

* клас `TrigonometricFunction`, представящ тригонометричните функции `sin(x)` и `cos(x)` със знак (положителен или отрицателен);
* клас `LinearCombination`, представящ линейна комбинация на две функции на един аргумент;
* клас `Product`, представящ произведение на две функции на един аргумент.

Нека функциите, които комбинират други функции, при конструирането си да правят копие на тези функции, използвайки метода `clone`. Грижете се внимателно за динамично-заделената памет. За самото реализиране на `clone` използвайте копиращия конструктор на класа.

След като сте готови:

* комбинирайте така написаните класове при единия от двамата и ги тествайте;
* допълнително — добавете метод `std::string toString(std::string variable = "x")` и реализирайте оператор `<<` за `UnaryFunction`, който извежда нейната низова репрезентация в поток.
