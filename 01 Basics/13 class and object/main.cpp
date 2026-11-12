/*
CLASSES AND OBJECTS

HOW TO READ THIS FILE:
This first part is a set of notes written inside a C++ comment. The
indented code examples in the notes show the syntax for the idea being
explained; they are small examples, not a second program to copy and run.
Some examples are complete statements, such as `Student s;`. Others are
parts of a class, such as a constructor, and belong inside the class braces.

The runnable C++ program starts after the closing comment marker below.
It contains a complete Student class and a main() function that uses it.
You can read the notes first, then compare their short examples with the
matching parts of that runnable program.

1. A class defines a user-defined data type

You already know built-in data types:
  int    stores an integer, such as 20
  float  and double store numbers with a fractional part
  char   stores a character, such as 'A'
  bool   stores true or false

Each built-in type describes one kind of value. But a real thing, such as a
student, usually needs several pieces of information at once: a name, age,
weight, and height. We want to keep those related pieces together instead
of treating them as unrelated values.

A class lets us define our own type (a user-defined data type). It can
bundle related information and actions into one definition. The variables
inside it are called data members; the functions inside it are called
member functions.

Here is the basic shape of a class. The names inside the braces are examples
of information and actions the class can define:

    class Student {
    public:
        int age;                 // data member: information each object has
        void studying() { }      // member function: action an object can do
    };                           // semicolon ends the class definition

This is the class definition (the plan). To create a particular Student
object from it, write `Student s;` somewhere in a function.

For example, if we wanted one custom type to bundle an integer, a character,
and a true/false value, we could define a class with an int, char, and bool
data member. A Student type can similarly bundle several integers and a
string. The class definition describes what every Student object can store
and do.

2. Class vs. object: the plan vs. the actual thing

HOUSE BLUEPRINT:
An architect draws where the rooms, washroom, hall, and other spaces belong.
You cannot live in the drawing. It is a plan, not a house.

The class is like that blueprint: it describes what a house should be like.
The house actually built from the plan is like an object.

COMPUTER MOUSE:
The design showing a mouse's shape and buttons is like the class. Each
physical mouse made from that design is a separate object.

The important difference is:
  class  = the description/type (the plan)
  object = one actual thing made using that description

In C++ terms, an object is an instance of a class. The class defines the
user-defined data type; each object is one instance of that type and has
its own data. For example, two Student objects can both have age and name,
but one can store Asha and 20 while the other stores Kunal and 21. Just
writing a class defines the type; it does not by itself create an object.

3. What goes inside a class?

  Data members   = what an object HAS (its properties or state).
  Member functions = what an object DOES (its behavior or actions).

For Student, age and name are data members. running() and studying() are
member functions. In everyday language: age/name describe the student;
running/studying are actions that student can do.

ACCESS:
Members in a class are private by default. "Private" means code outside the
class cannot directly use those members. Write public: to make the members
after it accessible to outside code, such as main(). In the runnable
Student class after these notes, public: lets main() read and change a
Student's data and call its functions. A struct works similarly, but its
members are public by default.

4. Writing a class

Use the class keyword, then the type's name and a body between braces.
Class names are commonly written in CamelCase, such as Student (each word
starts with a capital letter). Members go inside the braces. Do not miss
the semicolon after the closing brace:

    class Student {
        // members go here
    }; // required semicolon

This defines what a Student object will contain; it does not yet create a
particular student. An object is created separately, for example with
Student s;.

5. How much memory does an object use?

The class is the description/type; an object is an actual instance that
takes storage for its data. Even an empty class has a nonzero size
(commonly 1 byte). This allows distinct empty objects to have distinct
addresses. The exact size is implementation-dependent, meaning it can vary
with the compiler and system.

Do not just add up member sizes and assume that is always the class size.
The compiler may add padding bytes (unused gaps) so members are suitably
aligned in memory and can be accessed properly. Three ints commonly take
12 bytes, but check with sizeof on your own compiler.

Adding string does not mean Student must be exactly 40 bytes. The size of
string and the padding vary by implementation. Also, a string's characters
may be stored elsewhere, so sizeof(Student) does not include the full text
of every name. sizeof reports the size of the object itself, not necessarily
all memory that the object may use elsewhere.

6. Making objects: local and dynamic

LOCAL OBJECT:
    Student s1;

This creates one Student object named s1. This is often called stack
allocation in beginner lessons. More precisely, s1 has automatic storage
duration: C++ automatically destroys it when the scope containing it ends.
A scope is the region between a matching pair of braces. Use the dot
operator to access a member through the object itself:
    s1.age
    s1.studying()

DYNAMIC OBJECT:
    Student* s = new Student;

Read this in pieces:
  Student* s  declares s as a pointer that can hold the address of a Student.
  new Student creates a Student object with dynamic storage duration.
  The new expression gives back that object's address, which is stored in s.

Because s is a pointer (it holds an address), use -> to access the object's
members: s->age. This is shorthand for (*s).age: first follow the pointer
to the object, then use the dot operator. `new Student()` is another way
to write the no-argument construction.

A raw new object is not cleaned up just because the pointer goes out of
scope. Call delete s exactly once when done; that destroys the object and
releases its memory. Forgetting this can cause a memory leak (memory that
the program no longer uses but has not released). Modern C++ usually
prefers a smart pointer such as unique_ptr, which cleans up automatically.
The runnable example after these notes demonstrates raw new/delete and
smart-pointer cleanup.

7. Constructors: setting an object up

When an object is created, we often want its data to start with useful
values. A constructor is a special member function that runs automatically
when an object is created and initializes that object. Think of it as the
setup instructions that run for each new object.

Constructor rules:
  - It has the same name as the class.
  - It has no return type (not even void).

DEFAULT CONSTRUCTOR:
A constructor that can be called without passing arguments (extra values
between the parentheses). Example:

    Student s;

This creates s and calls the no-argument constructor. In the lecture's
example, this constructor sets age to 0, weight to 3, height to 45, and
name to "dummy". These are just chosen starting values; the constructor
can initialize members with other suitable values.

PARAMETERIZED CONSTRUCTOR:
A constructor that receives values (parameters), so each object can start
with the details we provide. Example:

    Student s(20, 70, 175, "Kunal");

Here the example constructor receives age 20, weight 70, height 175, and
name "Kunal", in that order. The values supplied when calling it are called
arguments; the named inputs in the constructor definition are parameters.

THE this POINTER:
If a parameter and a data member are both named age, `age = age;` does not
express the intended assignment: both names refer to the parameter, so it
would assign the parameter to itself. `this` points to the current object
(the particular object whose constructor or member function is running).
Therefore:

    this->age = age;

means "put the parameter age into this object's age member." The left side
uses this-> to name the member of the current object; the right side is the
parameter value.

INITIALIZATION LIST:
A constructor can initialize its members before its body starts by writing
a colon after its parameter list:

    Student(int myAge) : age(myAge) { }

Here age(myAge) initializes the object's age member using the parameter
myAge. This is another clear way to initialize members and is generally
preferred to assigning to them inside the constructor body.

8. Destructors: when an object is finished

A destructor is a special member function named ~ClassName (for example,
~Student). It has no parameters or return type, and it cannot be
overloaded. It runs when an object's lifetime ends, often to release
resources used by that object.

A local object is destroyed automatically when its scope ends. A dynamic
object made with raw new is destroyed when delete is called. C++ does not
automatically clean up a raw new object if you forget delete. A smart
pointer can manage that cleanup for you.

9. Homework question: Student s; or Student s();?

`Student s;` creates an object named s and calls its default constructor.
Surprisingly, `Student s();` declares a function named s that takes no
arguments and returns Student; it does not create an object. This confusing
case is called the "most vexing parse." Use `Student s;` or `Student s{};`
to make an object.

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

// PART B: Complete, runnable C++ example.
// The notes above explain the ideas; this program demonstrates them.
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
    Student() : age(0), height(45), weight(3), name("dummy") {
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
