/*
CLASSES AND OBJECTS
Read each topic in this order: the everyday idea, then the C++ meaning.

1. A class defines a user-defined data type

You already know built-in data types such as int, float, double, char, and
bool. Each describes a kind of value. But a student is more than one value:
a student can have a name, age, weight, and height.

A class lets us define our own data type and group related information and
actions. More precisely, C++ calls this a user-defined class type. Its
variables are called data members, and its functions are called member
functions.

2. Class vs. object: blueprint vs. real thing

HOUSE BLUEPRINT:
An architect draws where the rooms, washroom, hall, and other spaces belong.
You cannot live in the drawing. It is a plan, not a house.

The class is like that blueprint. The house actually built from the plan is
like an object.

COMPUTER MOUSE:
The design showing the mouse's shape and buttons is like the class. Each
physical mouse made from that design is an object.

Technical meaning: an object is an instance of a class. The class defines
the user-defined data type; each object is one instance of that data type,
with its own data. Just writing a class does not create an object.

3. What goes inside a class?

  Data members = what an object HAS (its properties/state).
  Member functions = what an object DOES (its behavior/actions).

For Student, age and name are data members. running() and studying() are
member functions.

ACCESS:
Members in a class are private by default. That means code outside the class
cannot directly use them. Write public: to allow outside code, such as
main(), to access the members below it. A struct works similarly, but its
members are public by default.

4. Writing a class

Use the class keyword, then a name and a body. Do not miss the semicolon
after the closing brace:

    class Student {
        // members go here
    }; // required semicolon

5. How much memory does an object use?

The class is the description; an object is the actual instance that takes
storage. Even an empty class has a nonzero size (commonly 1 byte). This
allows distinct empty objects to have distinct addresses. The exact size
is implementation-dependent.

Do not just add up member sizes and assume that is always the class size.
The compiler may add padding bytes so members are suitably aligned in
memory. Three ints commonly take 12 bytes, but check with sizeof.

Adding string does not mean Student must be exactly 40 bytes. The size of
string and the padding vary by implementation. Also, string's characters
may be stored elsewhere, so sizeof(Student) does not include the full text
of every name.

6. Making objects: local and dynamic

LOCAL OBJECT:
    Student s1;

This is often called stack allocation in beginner lessons. More precisely,
s1 has automatic storage duration: it is destroyed when its scope ends.
Use the dot operator to access its members: s1.age, s1.studying().

DYNAMIC OBJECT:
    Student* s = new Student;

new creates the object with dynamic storage duration and gives back its
address. The pointer s stores that address. Access members with ->:
s->age. This is shorthand for (*s).age.

A raw new object is not cleaned up just because the pointer goes out of
scope. Call delete s exactly once when done; that destroys the object and
releases its memory. Forgetting this can cause a memory leak. Modern C++
usually prefers a smart pointer such as unique_ptr, which cleans up
automatically. The program below shows both ideas.

7. Constructors: setting an object up

When an object is created, we often want its data to start with useful
values. A constructor is a special member function that runs automatically
at object creation and initializes the object.

Constructor rules:
  - It has the same name as the class.
  - It has no return type (not even void).

DEFAULT CONSTRUCTOR:
A constructor that can be called without passing arguments. Example:
Student s;

PARAMETERIZED CONSTRUCTOR:
A constructor that receives values. Example:
Student s(20, 70, 175, "Kunal");

THE this POINTER:
If a parameter and a data member are both named age, `age = age;` does not
express the intended assignment: it refers to the parameter on both sides.
`this` points to the current object. Therefore:

    this->age = age;

means "put the parameter age into this object's age member." The left side
uses this-> to name the member; the right side is the parameter.

INITIALIZATION LIST:
A constructor can initialize its members before its body starts by writing
a colon after its parameter list:

    Student(int myAge) : age(myAge) { }

This is another clear way to initialize members and is generally preferred
to assigning to them inside the constructor body.

8. Destructors: when an object is finished

A destructor is a special member function named ~ClassName. It has no
parameters or return type, and it cannot be overloaded. It runs when an
object's lifetime ends, often to release resources.

A local object is destroyed automatically when its scope ends. A dynamic
object made with raw new is destroyed when delete is called. C++ does not
automatically clean up a raw new object if you forget delete. A smart
pointer can manage that cleanup for you.

9. Homework question: Student s; or Student s();?

`Student s;` creates an object and calls its default constructor.
Surprisingly, `Student s();` declares a function named s that takes no
arguments and returns Student; it does not create an object. This is called
the "most vexing parse." Use `Student s;` or `Student s{};` to make an object.

10. Check these sizes on your own compiler

Compare sizeof(ThreeInts), sizeof(string), and sizeof(Student). Three ints
commonly take 12 bytes. A 64-bit implementation might report 40 bytes for a
Student with string, but that is not guaranteed: compiler layout, padding,
and string implementation can change the result. That variation is the
memory-alignment / structure-padding question from the lesson.

QUICK RECAP
Class = user-defined data type / plan.
Object = instance / actual thing with its own data.
Data members = properties. Member functions = behavior.
Use . with an object, -> with a pointer.
Constructor sets up an object. Destructor runs when its lifetime ends.
*/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Empty {
    // No data members or member functions.
}; // The semicolon after the class definition is required.

class ThreeInts {
public:
    int age;
    int weight;
    int height;
};

class Student {
public:
    // Data members: each Student object stores its own values.
    int age;
    int height;
    int weight;
    string name;

    // Default constructor: used when no starting details are supplied.
    Student() : age(0), height(0), weight(0), name("Unknown") {
        cout << "Default constructor: setting up a Student\n";
    }

    // Parameterized constructor using this to distinguish members from
    // same-named parameters.
    Student(int age, int weight, int height, string name) {
        this->age = age;
        this->weight = weight;
        this->height = height;
        this->name = name;
        cout << "Parameterized constructor using this: setting up "
             << this->name << '\n';
    }

    // A second parameterized constructor shows the initialization-list style.
    Student(string name, int age, int weight, int height)
        : age(age), height(height), weight(weight), name(name) {
        cout << "Initialized with a member initialization list: "
             << this->name << '\n';
    }

    // Member function: behavior belonging to Student.
    void running() const {
        cout << name << " is running\n";
    }

    void studying() const {
        cout << name << " is studying. Age: " << age << '\n';
    }

    // Same-named parameters and data members: this-> selects the current
    // object's member; the right-hand names refer to the parameters.
    void setDetails(int age, string name) {
        this->age = age;
        this->name = name;
    }

    // Destructor: runs when this object's lifetime ends.
    ~Student() {
        cout << "Destructor: " << name << " object is being destroyed\n";
    }
};

int main() {
    cout << "Size of an empty class object: " << sizeof(Empty)
         << " byte(s) (commonly 1)\n\n";
    cout << "Size of ThreeInts: " << sizeof(ThreeInts)
         << " bytes (commonly 12)\n";
    cout << "Size of string object: " << sizeof(string)
         << " bytes on this implementation\n";

    Empty empty1;
    Empty empty2;
    cout << "Two empty objects have distinct addresses: "
         << boolalpha << (&empty1 != &empty2) << "\n\n";

    // Most vexing parse: this would declare a function named mistaken with no
    // parameters that returns Student; it would not create a Student object.
    // Student mistaken();
    // Use braces (or Student mistaken;) to create the object instead.
    Student correctlyCreated{};
    cout << '\n';

    cout << "--- Default constructor and local object ---\n";
    {
        // A local object is destroyed automatically when this scope ends.
        Student student1;
        student1.setDetails(20, "Asha");
        student1.height = 165;
        student1.weight = 55;

        // Use . to access members through an object.
        student1.studying();
        student1.running();
    } // student1 leaves scope here, so its destructor runs automatically.

    cout << "\n--- Default constructor with a dynamic object ---\n";
    Student* defaultDynamic = new Student;
    defaultDynamic->studying();
    delete defaultDynamic; // Dynamic objects need cleanup when using raw new.

    cout << "\n--- Parameterized constructor using this ---\n";
    Student studentWithThis(20, 70, 175, "Kunal");
    studentWithThis.studying();

    cout << "\n--- Parameterized constructor using an initialization list ---\n";
    Student studentWithInitList("Ravi", 22, 65, 180);
    studentWithInitList.studying();

    cout << "\n--- Dynamic object and pointer member access ---\n";
    Student* student3 = new Student(19, 58, 170, "Maya");

    // Use -> to access members through a pointer.
    student3->studying();
    cout << "The same member using (*pointer).member: "
         << (*student3).age << '\n';

    delete student3; // Calls the destructor and releases the dynamic object.
    student3 = nullptr;

    cout << "\n--- Smart pointer cleanup ---\n";
    unique_ptr<Student> managedStudent =
        make_unique<Student>("Noah", 21, 68, 172);
    managedStudent->studying();
    // managedStudent is cleaned up automatically when it leaves main().

    cout << "\nSize of a Student object: " << sizeof(Student)
         << " byte(s); the exact value depends on the implementation.\n";
    return 0;
}
