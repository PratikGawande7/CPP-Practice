/*
    Complete C++ OOPs - Chapter 6
    Topic: Abstraction, Abstract Classes, and Interfaces
    Source: Love Babbar - Complete C++ OOPS in 1 Shot
    Timestamp: 02:20:00

    These are detailed learning notes. Abstraction hides implementation
    complexity and exposes only the operations a user needs.
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// =============================================================================
// 1. What is abstraction?
// =============================================================================

/*
    Abstraction means hiding complex internal implementation details and
    showing only the essential features or interface.

    Real-world examples:

    - Car: the accelerator is an interface. The driver does not manage fuel
      injection, spark timing, piston movement, or torque transfer directly.
    - ATM: the user enters a card, PIN, and amount. Database queries, bank
      network routing, authentication, and cash-dispensing mechanisms remain
      hidden.

    In C++:
    - <algorithm>'s sort() gives a simple operation while hiding its sorting
      implementation.
    - An abstract class can define what derived classes must do without
      exposing how each derived class does it.

    Encapsulation and abstraction are related but different:

    Encapsulation:
        Bundles data and behaviour and controls access to state. It focuses on
        protecting data, often using private members and public methods.

    Abstraction:
        Hides implementation complexity and exposes an essential contract. It
        focuses on what an object can do rather than how it does it.
*/

// =============================================================================
// 2. Abstraction through a library interface
// =============================================================================

void standardLibraryAbstractionExample() {
    cout << "===== Abstraction through a library =====" << endl;

    vector<int> values{5, 1, 4, 2, 3};

    // We call sort without implementing or knowing its internal algorithm.
    sort(values.begin(), values.end());

    cout << "Sorted values: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << endl;

    /*
        The C++ standard specifies the behaviour of sort(), not one particular
        implementation strategy. A library implementation may use a hybrid
        algorithm such as Introsort. The caller depends on the public
        interface, not those hidden details.
    */
}

// =============================================================================
// 3. Pure virtual functions and abstract classes
// =============================================================================

/*
    A pure virtual function is declared with = 0:

        virtual void draw() = 0;

    It establishes a requirement for derived classes. A class with at least one
    pure virtual function is abstract.

    Rules:
    - An abstract class cannot be instantiated directly.
    - A derived class must override every inherited pure virtual function to
      become concrete and instantiable.
    - An abstract class can contain data members, constructors, implemented
      member functions, and non-pure virtual functions.
    - A pure virtual function can have a definition in some designs, but the
      derived class still needs to override it to become concrete.
    - A pointer or reference to an abstract base type is allowed. This is how
      common code can work with many concrete derived types.
    - An abstract base used polymorphically should have a virtual destructor.
*/

class Shape {
protected:
    string color;

public:
    explicit Shape(const string& shapeColor)
        : color(shapeColor) {}

    // Pure virtual functions define the required Shape contract.
    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;

    // A concrete function can be shared by all derived classes.
    void displayColor() const {
        cout << "Shape color: " << color << endl;
    }

    // Virtual cleanup makes deletion through Shape* safe.
    virtual ~Shape() {
        cout << "[Shape destructor]" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const string& circleColor, double circleRadius)
        : Shape(circleColor), radius(circleRadius) {}

    void draw() const override {
        cout << "[Drawing] " << color << " circle with radius "
             << radius << endl;
    }

    double calculateArea() const override {
        constexpr double pi = 3.14159265358979323846;
        return pi * radius * radius;
    }

    ~Circle() override {
        cout << "[Circle destructor]" << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(const string& rectangleColor, double rectangleLength,
              double rectangleWidth)
        : Shape(rectangleColor),
          length(rectangleLength),
          width(rectangleWidth) {}

    void draw() const override {
        cout << "[Drawing] " << color << " rectangle ("
             << length << " x " << width << ")" << endl;
    }

    double calculateArea() const override {
        return length * width;
    }

    ~Rectangle() override {
        cout << "[Rectangle destructor]" << endl;
    }
};

void abstractClassExample() {
    cout << "\n===== Abstract class =====" << endl;

    // Shape shape("Red"); // Error: Shape is abstract.

    /*
        unique_ptr owns each concrete object and deletes it automatically.
        Shape remains the common abstract interface, and virtual dispatch calls
        the correct draw() and calculateArea() implementation.
    */
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>("Red", 5.0));
    shapes.push_back(make_unique<Rectangle>("Blue", 4.0, 6.0));

    cout << fixed << setprecision(2);
    for (const unique_ptr<Shape>& shape : shapes) {
        shape->displayColor();
        shape->draw();
        cout << "Area: " << shape->calculateArea() << endl;
        cout << "---------------------------------------" << endl;
    }

    // unique_ptr cleanup invokes Circle/Rectangle destructors and Shape's
    // virtual destructor automatically when shapes leaves this function.
}

// =============================================================================
// 4. Interface in C++
// =============================================================================

/*
    C++ has no separate interface keyword like some languages. An interface is
    conventionally represented by a pure abstract class:

    - All relevant operations are pure virtual.
    - It usually contains no data members.
    - It has a virtual destructor.
    - It describes a contract, not one shared implementation.

    An interface can be implemented by unrelated classes. A class can inherit
    from more than one interface, which is one common use of multiple
    inheritance.
*/

class Printable {
public:
    virtual void print() const = 0;
    virtual void showPDF() const = 0;

    virtual ~Printable() = default;
};

class Report : public Printable {
private:
    string title;

public:
    explicit Report(const string& reportTitle)
        : title(reportTitle) {}

    void print() const override {
        cout << "Printing report: " << title << endl;
    }

    void showPDF() const override {
        cout << "Opening PDF view for: " << title << endl;
    }
};

class Invoice : public Printable {
private:
    int invoiceNumber;

public:
    explicit Invoice(int number)
        : invoiceNumber(number) {}

    void print() const override {
        cout << "Printing invoice #" << invoiceNumber << endl;
    }

    void showPDF() const override {
        cout << "Opening PDF view for invoice #" << invoiceNumber << endl;
    }
};

void interfaceExample() {
    cout << "\n===== Interface-style pure abstract class =====" << endl;

    // Printable printable; // Error: cannot instantiate an interface.

    vector<unique_ptr<Printable>> documents;
    documents.push_back(make_unique<Report>("Annual results"));
    documents.push_back(make_unique<Invoice>(1001));

    for (const unique_ptr<Printable>& document : documents) {
        document->print();
        document->showPDF();
    }
}

// =============================================================================
// 5. Abstraction versus encapsulation in one example
// =============================================================================

class CoffeeMachine {
private:
    int waterMillilitres;

    void heatWater() const {
        cout << "  [hidden] Heating water." << endl;
    }

    void pumpWater() const {
        cout << "  [hidden] Pumping water through coffee grounds." << endl;
    }

public:
    explicit CoffeeMachine(int initialWater)
        : waterMillilitres(initialWater) {}

    // Public abstraction: the user needs only this simple operation.
    bool makeCoffee() {
        constexpr int requiredWater = 200;
        if (waterMillilitres < requiredWater) {
            cout << "Not enough water." << endl;
            return false;
        }

        heatWater();
        pumpWater();
        waterMillilitres -= requiredWater;
        cout << "Coffee is ready." << endl;
        return true;
    }

    int getWaterLevel() const {
        return waterMillilitres;
    }
};

void abstractionAndEncapsulationExample() {
    cout << "\n===== Abstraction and encapsulation together =====" << endl;

    CoffeeMachine machine(400);
    machine.makeCoffee();
    cout << "Remaining water: " << machine.getWaterLevel() << " ml" << endl;

    // machine.waterMillilitres = -100; // Error: private state is protected.
    // machine.heatWater();              // Error: implementation is hidden.
}

// =============================================================================
// 6. Summary and practice
// =============================================================================

/*
    Comparison:

    Feature              Concrete class       Abstract class       Interface
    ---------------------------------------------------------------------------
    Pure virtual funcs   None required        At least one          All contract funcs
    Direct object        Allowed              Forbidden             Forbidden
    Data members         Allowed              Allowed               Usually none
    Main purpose         Complete object      Shared base contract  Strict contract

    Common mistakes:
    - Trying to instantiate an abstract class.
    - Forgetting to override one pure virtual function.
    - Omitting a virtual destructor from an abstract polymorphic base.
    - Confusing abstraction (hidden implementation) with encapsulation
      (controlled access to state).
    - Exposing internal containers or raw pointers instead of an interface.

    Practice questions:
    1. What is abstraction?
    2. What is the difference between abstraction and encapsulation?
    3. What is a pure virtual function?
    4. Why is Shape an abstract class?
    5. Can an abstract class have a constructor and data members?
    6. Can a pointer point to an abstract class?
    7. What must a derived class do to become concrete?
    8. Why should an abstract base destructor be virtual?
    9. What is an interface in C++?
    10. Why is sort() an example of abstraction?
    11. Why is unique_ptr useful in the Shape example?
    12. What happens if a derived class does not implement calculateArea()?

    Homework:
    - Create an abstract Payment class with pure virtual pay() and refund().
    - Implement CardPayment, UpiPayment, and CashPayment.
    - Create an abstract Notification interface with send().
    - Add EmailNotification and SMSNotification implementations.
    - Add validation and private state without exposing implementation details.
*/

int main() {
    standardLibraryAbstractionExample();
    abstractClassExample();
    interfaceExample();
    abstractionAndEncapsulationExample();

    return 0;
}
