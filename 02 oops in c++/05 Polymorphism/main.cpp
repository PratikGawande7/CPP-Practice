/*
    Complete C++ OOPs - Chapter 5
    Topic: Polymorphism
    Source: Love Babbar - Complete C++ OOPS in 1 Shot
    Timestamp: 01:52:00

    These are detailed learning notes. Polymorphism means "many forms": one
    interface or operation can behave differently in different situations.
*/

#include <iostream>
#include <string>

using namespace std;

// =============================================================================
// 1. What is polymorphism?
// =============================================================================

/*
    Poly means many and morph means forms.

    In C++, polymorphism is commonly divided into:

    1. Compile-time polymorphism (static / early binding)
       The compiler decides which function or operator is meant before the
       program runs.
       Examples: function overloading and operator overloading.

    2. Run-time polymorphism (dynamic / late binding)
       The program chooses an overridden virtual function while running.
       It uses inheritance and a base pointer or reference to a derived object.

    A real-world analogy is one person having different roles. The same person
    can act as a teacher in one context and a researcher in another. The
    applicable behaviour depends on the context.
*/

// =============================================================================
// 2. Compile-time polymorphism: function overloading
// =============================================================================

/*
    Function overloading means multiple functions in one scope have the same
    name but different parameter lists.

    A signature differs when the parameter count, types, or order differs:

        add(int, int)
        add(int, int, int)
        add(double, double)

    The return type alone is not enough:

        int    calculate(int); // illegal with
        double calculate(int); // same parameter list

    The compiler uses the arguments at the call site to select an overload.
    This is resolved at compile time.
*/

class Calculator {
public:
    int add(int first, int second) const {
        return first + second;
    }

    int add(int first, int second, int third) const {
        return first + second + third;
    }

    double add(double first, double second) const {
        return first + second;
    }

    /*
        These functions have the same name but different parameter types.
        const after the parameter list means they do not modify this object.
    */
    void print(const string& message) const {
        cout << "Message: " << message << endl;
    }

    void print(int value) const {
        cout << "Integer: " << value << endl;
    }
};

void functionOverloadingExample() {
    cout << "===== Function overloading =====" << endl;

    Calculator calculator;
    cout << "add(2, 3): " << calculator.add(2, 3) << endl;
    cout << "add(2, 3, 4): " << calculator.add(2, 3, 4) << endl;
    cout << "add(2.5, 3.5): " << calculator.add(2.5, 3.5) << endl;

    calculator.print("overload selected by string");
    calculator.print(42); // Overload selected by int.

    // calculator.add(1, 2.0); may be ambiguous in some overload sets because
    // more than one conversion could be considered. Good APIs avoid unclear
    // overloads and callers can use explicit casts when necessary.
}

// =============================================================================
// 3. Compile-time polymorphism: operator overloading
// =============================================================================

/*
    Built-in operators already know how to work with built-in types:

        2 + 3

    For a user-defined type, the programmer can define a meaningful operation.
    Then this:

        complexOne + complexTwo

    can add real parts and imaginary parts.

    Operator overloading:
    - Must involve at least one user-defined type.
    - Cannot change an operator's precedence, associativity, or number of
      operands.
    - Cannot invent a new operator.
    - Some operators cannot be overloaded, including . , :: , ?: and sizeof.
    - Keep overloaded operators intuitive; surprising meanings make code hard
      to understand.
*/

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double realPart = 0.0, double imaginaryPart = 0.0)
        : real(realPart), imaginary(imaginaryPart) {}

    void print(const string& label) const {
        cout << label << ": " << real;
        if (imaginary >= 0.0) {
            cout << " + " << imaginary << "i" << endl;
        } else {
            cout << " - " << -imaginary << "i" << endl;
        }
    }

    // Member operator function. left + right calls left.operator+(right).
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // The function-call operator lets a Complex object be called like a
    // function. Such an object is called a function object (functor).
    void operator()() const {
        print("[Functor call]");
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imaginary == other.imaginary;
    }
};

void operatorOverloadingExample() {
    cout << "\n===== Operator overloading =====" << endl;

    Complex first(3.0, 4.0);
    Complex second(5.0, 6.0);
    Complex sum = first + second;

    first.print("First");
    second.print("Second");
    sum.print("Sum (first + second)");
    sum(); // Calls overloaded operator().

    cout << "Is sum equal to first? "
         << (sum == first ? "yes" : "no") << endl;
}

// =============================================================================
// 4. Run-time polymorphism: overriding
// =============================================================================

/*
    Function overriding occurs when a derived class provides its own
    implementation of a base class member function with the same name and
    compatible signature.

    A base pointer or reference can refer to a derived object (upcasting):

        Animal* animal = new Dog;

    If speak() is not virtual, a call through Animal* is selected using the
    pointer's static type and Animal::speak() runs. This is early binding.

    If speak() is virtual, the object's runtime type is used and Dog::speak()
    runs. This is late binding.

    override is not required for dispatch, but it asks the compiler to verify
    that the derived function really overrides a virtual base function. It
    catches spelling and signature mistakes.
*/

class Animal {
public:
    virtual void speak() const {
        cout << "[Animal] Generic animal sound." << endl;
    }

    /*
        A virtual destructor is essential when a derived object may be deleted
        through an Animal pointer. It ensures both ~Dog() and ~Animal() run.
    */
    virtual ~Animal() {
        cout << "[Animal destructor]" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "[Dog] Woof woof! Barking..." << endl;
    }

    ~Dog() override {
        cout << "[Dog destructor]" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "[Cat] Meow meow!" << endl;
    }

    ~Cat() override {
        cout << "[Cat destructor]" << endl;
    }
};

void runtimePolymorphismExample() {
    cout << "\n===== Run-time polymorphism =====" << endl;

    Animal* dog = new Dog();
    Animal* cat = new Cat();

    // Dynamic dispatch chooses the implementation based on the actual object.
    dog->speak();
    cat->speak();

    delete dog; // Dog destructor, then Animal destructor.
    delete cat; // Cat destructor, then Animal destructor.
}

// A reference can provide dynamic dispatch without manual allocation.
void makeAnimalSpeak(const Animal& animal) {
    animal.speak();
}

void referencePolymorphismExample() {
    cout << "\n===== Runtime polymorphism through references =====" << endl;
    Dog dog;
    Cat cat;

    makeAnimalSpeak(dog);
    makeAnimalSpeak(cat);
}

// =============================================================================
// 5. vptr and vtable: implementation idea
// =============================================================================

/*
    A common implementation model for virtual dispatch is:

    - A class with virtual functions has a virtual table (vtable) containing
      addresses of the appropriate virtual functions.
    - Each polymorphic object commonly contains a hidden virtual pointer (vptr)
      referring to the table for its runtime type.
    - animal->speak() uses that runtime table to find Dog::speak() or Cat::speak().

    vptr and vtable are useful mental models, but their exact representation is
    not mandated by the C++ standard. Do not write portable code that depends
    on their size or layout.

    Dynamic dispatch has a small runtime cost and may affect object size. The
    clarity and substitutability it provides are usually more important than
    this small implementation detail.
*/

// =============================================================================
// 6. Common mistakes and comparison
// =============================================================================

/*
    Common mistakes:

    1. Changing only the return type and expecting overloading.
    2. Forgetting const in an override's signature.
    3. Omitting override and missing a typo or signature mismatch.
    4. Calling a non-virtual function through a base pointer and expecting
       runtime dispatch.
    5. Deleting a derived object through a base pointer without a virtual
       destructor.
    6. Using raw new/delete when an automatic object or smart pointer is better.

    Compile-time polymorphism:
    - Early/static binding.
    - Decided by the compiler.
    - Function/operator overloading.
    - Does not require inheritance.

    Run-time polymorphism:
    - Late/dynamic binding.
    - Decided while the program runs.
    - Overriding through virtual functions.
    - Requires a base/derived relationship and virtual dispatch.
*/

// =============================================================================
// 7. Practice questions
// =============================================================================

/*
    1. What do "poly" and "morph" mean?
    2. What is compile-time polymorphism?
    3. Why is return type alone insufficient for overloading?
    4. What is operator overloading?
    5. What is function overriding?
    6. What does virtual change in a base member function?
    7. What is upcasting?
    8. Why should a polymorphic base destructor be virtual?
    9. What does override help the compiler check?
    10. What are vptr and vtable?
    11. Why is a vtable description an implementation model rather than a
        direct language guarantee?
    12. How can runtime polymorphism work through a reference?

    Homework:
    - Add overloaded multiply() functions for int and double values.
    - Create a Vector2D class with overloaded +, -, ==, and << operators.
    - Create a Shape base class and Circle, Rectangle, and Triangle derived
      classes, each overriding area() and draw().
    - Test the difference between a virtual and non-virtual speak() function.
    - Remove Animal's virtual destructor and explain why deletion becomes unsafe
      when a derived class owns resources.
*/

int main() {
    functionOverloadingExample();
    operatorOverloadingExample();
    runtimePolymorphismExample();
    referencePolymorphismExample();

    return 0;
}
