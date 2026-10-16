/*
CLASS AND OBJECT - LEARN THE IDEA, THEN THE C++ DETAILS

1. What is a class?

Think about a student. We might want to keep that student's name, age,
height, and weight together. A class lets us define a new type that groups
related information and the actions that work with it.

Technical definition:
A class is a user-defined type. Its data members describe the information
stored in an object, and its member functions describe operations the object
can perform.

For example, int stores one integer and char stores one character. Our own
Student type can group a string, integers, and functions into one useful
concept.

2. Class vs. object: blueprint and real thing

A class is like an architect's blueprint for a house. It describes what a
house should have, but the drawing itself is not a house that you can live in.
The built house is like an object: a real instance made according to the plan.

The same idea works for a computer mouse. The design describing its buttons
and behavior is the class; each actual mouse made from that design is an
object.

Technically, the class declares a type. An object (also called an instance)
is a particular value of that type. Each Student object has its own name and
age. A class definition by itself does not create a Student object.

3. Data members, member functions, and public

In the Student class below:
  - age, height, weight, and name are data members (properties/state).
  - running() and studying() are member functions (behavior/operations).
  - public: means code outside the class, such as main(), can access these
    members. Access control is explained further in object-oriented
    programming.

4. The semicolon after a class

A class definition ends with }; . The semicolon is required.

5. How much memory does a class/object use?

Defining a class describes a type; creating an object reserves storage for
that particular object. An empty class still has nonzero size in C++ (it is
commonly 1 byte), so separate empty objects can have distinct addresses.
The exact size is implementation-dependent.

An object's size can include its data members and padding bytes inserted for
alignment. Do not assume the size by simply adding the sizes of the members.
For example, std::string may manage its character data separately, so
sizeof(Student) does not include all characters in the student's name.

6. Creating objects and accessing members

Student student1; creates a local object. Beginner explanations often call
this "static" or "stack" allocation; more precisely, this local variable has
automatic storage duration and is destroyed when its scope ends.

Student* student2 = new Student; creates an object with dynamic storage
duration and gives us a pointer to it. Use -> to access members through a
pointer; (*student2).age is the equivalent longer form. With a raw pointer,
remember to call delete exactly once when finished, or the object and its
resources will not be released.

Modern C++ usually prefers a smart pointer such as unique_ptr, which releases
the object automatically. The raw new/delete example in main() is included
because it makes the pointer and cleanup mechanics visible.

7. Constructors: setting up a new object

A constructor is a special member function that runs automatically when an
object is created. It has the class's name and no return type.

The no-argument constructor is often called the default constructor. The
constructor with parameters is a parameterized constructor.

An initialization list, written after the constructor's colon, initializes
members as the object is being constructed. It is generally preferred over
assigning to those members inside the constructor body.

In Student(int age, string name), the parameter names match the member names.
this points to the current object, so this->age means "the age member of this
object"; the age on the right is the function parameter. The initialization
list also makes this distinction: age(age) initializes the member age from
the parameter age.

8. Destructors: cleanup when an object is done

A destructor is a special member function named ~ClassName. It runs when an
object's lifetime ends. Local objects are destroyed automatically when they
leave scope. For an object created with raw new, calling delete ends its
lifetime and invokes its destructor.

C++ does not automatically delete raw dynamically allocated objects if you
forget delete. Smart pointers and other resource-managing types help avoid
such leaks.
*/

#include <iostream>
#include <string>
using namespace std;

class Empty {
    // No data members or member functions.
}; // The semicolon after the class definition is required.

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

    // Parameterized constructor: start with the supplied values.
    // The initialization list initializes members before the constructor body.
    Student(int age, string name) : age(age), height(0), weight(0), name(name) {
        cout << "Parameterized constructor: setting up " << this->name << '\n';
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

    cout << "--- Local object ---\n";
    {
        // student1 is an object (instance) of the Student class.
        Student student1;
        student1.setDetails(20, "Asha");
        student1.height = 165;
        student1.weight = 55;

        // Use . to access members through an object.
        student1.studying();
        student1.running();
    } // student1 leaves scope here, so its destructor runs automatically.

    cout << "\n--- Parameterized constructor ---\n";
    Student student2(22, "Ravi");
    student2.studying();

    cout << "\n--- Dynamic object with a raw pointer ---\n";
    Student* student3 = new Student(19, "Maya");

    // Use -> to access members through a pointer.
    student3->studying();
    cout << "The same member using (*pointer).member: "
         << (*student3).age << '\n';

    delete student3; // Calls the destructor and releases the dynamic object.
    student3 = nullptr;

    cout << "\nSize of a Student object: " << sizeof(Student)
         << " byte(s); the exact value depends on the implementation.\n";
    return 0;
}
