/*
    Complete C++ OOPs - Chapter 4
    Topic: Inheritance and Modes of Inheritance
    Source: Love Babbar - Complete C++ OOPS in 1 Shot
    Timestamp: 01:10:00

    These are detailed learning notes. Inheritance lets a derived class reuse
    and extend an existing base class while expressing an IS-A relationship.
*/

#include <iostream>
#include <string>

using namespace std;

// =============================================================================
// 1. What is inheritance?
// =============================================================================

/*
    Inheritance is the capability of a class to derive properties and
    behaviours from another class.

    Base class     = parent class / super class
    Derived class  = child class / sub class

    A Student IS-A Human, so Student can inherit common Human functionality
    instead of duplicating name, age, and eat().

    Benefits:
    - Code reuse: common code is written once.
    - Extensibility: a derived class adds its own data and behaviour.
    - Maintenance: changes to common behaviour can be made in one base class.
    - Clear modelling: the relationship between entities is explicit.

    Use inheritance for a genuine IS-A relationship. A "Car has an Engine" is
    a HAS-A relationship and is usually modelled with composition instead.
*/

class Human {
public:
    string name;
    int age;

protected:
    string nationalID;

private:
    string secretPassword;

public:
    Human()
        : name("Unknown"), age(0), nationalID("NID-0000"),
          secretPassword("hidden") {
        cout << "[Human default constructor]" << endl;
    }

    Human(const string& humanName, int humanAge, const string& id)
        : name(humanName), age(humanAge), nationalID(id),
          secretPassword("hidden") {
        cout << "[Human parameterized constructor]" << endl;
    }

    void eat() const {
        cout << name << " is eating food." << endl;
    }

    void showHumanData() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

protected:
    void useSecretInsideHuman() const {
        // A base class can access its own private members.
        cout << "Human's private password is used internally." << endl;
        (void)secretPassword;
    }

public:
    ~Human() {
        cout << "[Human destructor]" << endl;
    }
};

// Public inheritance models "Student IS-A Human".
class Student : public Human {
private:
    int rollNumber;
    string schoolName;

public:
    Student(const string& studentName, int studentAge, const string& id,
            int roll, const string& school)
        : Human(studentName, studentAge, id),
          rollNumber(roll),
          schoolName(school) {
        cout << "[Student constructor]" << endl;
    }

    void study() const {
        // Public base members are accessible in the derived class.
        cout << name << " (Roll: " << rollNumber << ") is studying at "
             << schoolName << "." << endl;

        // Protected base members are accessible in the derived class.
        cout << "National ID (protected base member): "
             << nationalID << endl;

        // secretPassword = "new"; // Error: private base member is inaccessible.
        useSecretInsideHuman();
    }

    ~Student() {
        cout << "[Student destructor]" << endl;
    }
};

void singleInheritanceExample() {
    cout << "===== Single inheritance =====" << endl;
    Student student("Love Babbar", 22, "NID-9999", 101,
                    "CodeHelp Academy");

    student.eat();   // Inherited public function.
    student.showHumanData(); // Inherited public function.
    student.study(); // Student's own function.

    // student.nationalID = "new"; // Error: protected outside the hierarchy.
    // student.secretPassword;     // Error: private and inaccessible.
}

// =============================================================================
// 2. Access specifiers and inheritance modes
// =============================================================================

/*
    Access inside the declaring class:

                         Same class   Derived class   Outside code
        public               yes           yes            yes
        protected            yes           yes            no
        private              yes           no             no

    Inheritance mode changes the access level of inherited public and protected
    members as seen through the derived class. It does not make base private
    members directly accessible.

    Base member       public inheritance   protected inheritance   private inheritance
    public            public               protected               private
    protected         protected             protected               private
    private           inaccessible         inaccessible             inaccessible

    Important distinction:
    A private base member still belongs to the base subobject inside a derived
    object, but derived code cannot name it directly. The base's own public or
    protected member functions may still operate on it.
*/

class AccessBase {
public:
    int publicValue;

protected:
    int protectedValue;

private:
    int privateValue;

public:
    AccessBase()
        : publicValue(1), protectedValue(2), privateValue(3) {}

    int getPrivateValue() const {
        return privateValue;
    }
};

class PublicDerived : public AccessBase {
public:
    void demonstrate() {
        publicValue = 10;    // Remains public in PublicDerived.
        protectedValue = 20; // Remains protected in PublicDerived.
        // privateValue = 30; // Never directly accessible.
    }
};

class ProtectedDerived : protected AccessBase {
public:
    void demonstrate() {
        publicValue = 100;    // Becomes protected in this derived class.
        protectedValue = 200; // Remains protected.
    }
};

class PrivateDerived : private AccessBase {
public:
    void demonstrate() {
        publicValue = 1000;    // Becomes private in this derived class.
        protectedValue = 2000; // Becomes private.
    }
};

void inheritanceModeExample() {
    cout << "\n===== Inheritance modes =====" << endl;

    PublicDerived publicObject;
    publicObject.publicValue = 11;
    publicObject.demonstrate();
    cout << "Public inheritance exposes publicValue: "
         << publicObject.publicValue << endl;

    ProtectedDerived protectedObject;
    protectedObject.demonstrate();
    // protectedObject.publicValue = 12; // Error: now protected.

    PrivateDerived privateObject;
    privateObject.demonstrate();
    // privateObject.publicValue = 13; // Error: now private.

    cout << "Base private value through base's public function: "
         << publicObject.getPrivateValue() << endl;
}

// =============================================================================
// 3. Five types of inheritance
// =============================================================================

/*
    1. Single:
           Base -> Derived

    2. Multilevel:
           Grandparent -> Parent -> Child

    3. Multiple:
           BaseA and BaseB -> One derived class

    4. Hierarchical:
                    Base
                   /    \
              Child1    Child2

    5. Hybrid:
       A combination of two or more inheritance forms. Hybrid designs can
       introduce the diamond problem, which is addressed with virtual base
       classes (shown below).
*/

// ----- Multilevel inheritance -------------------------------------------------

class LivingBeing {
public:
    void breathe() const {
        cout << "Living being breathes." << endl;
    }
};

class Animal : public LivingBeing {
public:
    void move() const {
        cout << "Animal moves." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() const {
        cout << "Dog barks." << endl;
    }
};

void multilevelInheritanceExample() {
    cout << "\n===== Multilevel inheritance =====" << endl;
    Dog dog;
    dog.breathe(); // LivingBeing -> Animal -> Dog
    dog.move();
    dog.bark();
}

// ----- Multiple inheritance and ambiguity ------------------------------------

class Teacher {
public:
    void displayRole() const {
        cout << "Role: teaching students." << endl;
    }
};

class Researcher {
public:
    void displayRole() const {
        cout << "Role: conducting research." << endl;
    }
};

class Professor : public Teacher, public Researcher {
public:
    explicit Professor(const string& professorDepartment)
        : department(professorDepartment) {}

    void displayDepartment() const {
        cout << "Department: " << department << endl;
    }

private:
    string department;
};

void multipleInheritanceExample() {
    cout << "\n===== Multiple inheritance =====" << endl;
    Professor professor("Computer Science");
    professor.displayDepartment();

    // professor.displayRole(); // Error: both bases provide displayRole().

    // Scope resolution selects the intended base-class implementation.
    professor.Teacher::displayRole();
    professor.Researcher::displayRole();
}

// ----- Hierarchical inheritance ----------------------------------------------

class Shape {
public:
    void describe() const {
        cout << "This is a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void drawCircle() const {
        cout << "Drawing a circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void drawRectangle() const {
        cout << "Drawing a rectangle." << endl;
    }
};

void hierarchicalInheritanceExample() {
    cout << "\n===== Hierarchical inheritance =====" << endl;
    Circle circle;
    Rectangle rectangle;

    circle.describe();
    circle.drawCircle();
    rectangle.describe();
    rectangle.drawRectangle();
}

// ----- Hybrid inheritance and the diamond problem ----------------------------

class HybridPerson {
public:
    void identify() const {
        cout << "One shared HybridPerson subobject." << endl;
    }
};

// virtual inheritance makes the common base shared in the final object.
class HybridStudent : virtual public HybridPerson {};
class HybridEmployee : virtual public HybridPerson {};

class TeachingAssistant : public HybridStudent, public HybridEmployee {
public:
    void demonstrate() const {
        // Without virtual inheritance, identify() would be ambiguous because
        // two separate HybridPerson subobjects would exist.
        identify();
    }
};

void hybridInheritanceExample() {
    cout << "\n===== Hybrid inheritance =====" << endl;
    TeachingAssistant assistant;
    assistant.demonstrate();
}

// =============================================================================
// 4. Constructor and destructor order
// =============================================================================

/*
    When a derived object is created:

    1. Virtual base classes, if any, are initialized.
    2. Direct base classes are initialized from left to right in the class
       declaration, regardless of the order written in the initializer list.
    3. Derived data members are initialized in declaration order.
    4. The derived constructor body runs.

    When the object is destroyed, the reverse occurs:

    1. Derived destructor body runs.
    2. Derived members are destroyed in reverse declaration order.
    3. Direct base destructors run in reverse base order.
    4. Virtual bases are destroyed last.

    For Student : public Human, Human is constructed before Student and Human
    is destroyed after Student.
*/

class OrderBase {
public:
    explicit OrderBase(const string& baseName) {
        cout << "Constructing base: " << baseName << endl;
    }

    ~OrderBase() {
        cout << "Destroying base." << endl;
    }
};

class OrderDerived : public OrderBase {
public:
    OrderDerived()
        : OrderBase("OrderBase") {
        cout << "Constructing derived." << endl;
    }

    ~OrderDerived() {
        cout << "Destroying derived." << endl;
    }
};

void constructorDestructorOrderExample() {
    cout << "\n===== Constructor and destructor order =====" << endl;
    {
        OrderDerived object;
        cout << "Object is alive." << endl;
    }
    cout << "Object scope ended." << endl;
}

// =============================================================================
// 5. Summary and practice
// =============================================================================

/*
    Practice questions:
    1. What is inheritance?
    2. What is the difference between IS-A and HAS-A?
    3. Why is protected useful in inheritance?
    4. Can a derived class directly access private base members?
    5. What happens to public members under private inheritance?
    6. Name and draw the five types of inheritance.
    7. Why does multiple inheritance cause ambiguity?
    8. How does :: resolve a member-name conflict?
    9. In what order are constructors called?
    10. In what order are destructors called?
    11. What is the diamond problem?
    12. How does virtual inheritance solve the diamond problem?

    Homework:
    - Create Vehicle -> Car as a single inheritance example.
    - Create Grandparent -> Parent -> Child as a multilevel example.
    - Create Printer and Scanner -> Machine as multiple inheritance.
    - Create Employee -> Manager and Employee -> Developer as hierarchical
      inheritance.
    - Create a hybrid diamond and compare it with and without virtual bases.
    - Use the access table to predict which members are accessible before
      compiling each example.
*/

int main() {
    singleInheritanceExample();
    inheritanceModeExample();
    multilevelInheritanceExample();
    multipleInheritanceExample();
    hierarchicalInheritanceExample();
    hybridInheritanceExample();
    constructorDestructorOrderExample();

    return 0;
}
