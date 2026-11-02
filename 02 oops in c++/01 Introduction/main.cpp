/*
    Complete C++ OOPs - Chapter 1
    Topic: Introduction to Object-Oriented Programming
    Source: Love Babbar - Complete C++ OOPS in 1 Shot
    Timestamp: 00:00:00 (Chapter 1)

    These are learning notes, not short revision notes. Read the explanations
    above each example and run the program to connect the ideas with output.
*/

#include <iostream>
#include <string>

using namespace std;

// =============================================================================
// 1. Why was Object-Oriented Programming needed?
// =============================================================================

/*
    In procedural programming, we usually keep data and functions separate:

        int id = 101;
        string name = "Aarav";

        void study() { ... }
        void sleep() { ... }

    This works for small programs. As a program grows, however:

    1. Related data is scattered across the program.
    2. A function may accidentally change data belonging to another entity.
    3. Variables and functions can become difficult to find and maintain.
    4. Global variables pollute the global scope and can have unintended effects.
    5. Real-world entities such as Student, Librarian, and Teacher are not
       represented as clearly defined units.

    OOP provides a way to group related data and the operations on that data.
    This grouping improves organization and is the foundation for data hiding,
    modularity, reuse, and easier maintenance. Access control is introduced by
    classes; it becomes especially useful with private members, which will be
    studied in encapsulation.
*/

// A loose procedural-style example (kept commented so it does not conflict
// with the OOP example below):
//
// int studentId = 101;
// string studentName = "Aarav";
//
// void study() {
//     cout << studentName << " is studying." << endl;
// }

// =============================================================================
// 2. What is Object-Oriented Programming?
// =============================================================================

/*
    OOP stands for Object-Oriented Programming.

    The central idea is:

        Data (attributes/state) + Functions (behaviour)
        = one meaningful unit called an object

    Attributes describe an entity:
        id, age, name, number of subjects

    Behaviours describe what the entity can do:
        study(), sleep(), bunk()

    A class is the definition or blueprint used to create objects. An object
    is an actual instance created from that class.

    The medical-capsule analogy:
    If the ingredients of a capsule are scattered separately, their combined
    identity is unclear. When they are bound inside one capsule, they form a
    meaningful unit. Similarly, OOP binds related state and behaviour together.
*/

class Student {
public:
    // -------------------------------------------------------------------------
    // Attributes / state / data members
    // -------------------------------------------------------------------------
    int id;
    int age;
    string name;
    int numSubjects;

    // -------------------------------------------------------------------------
    // Behaviours / methods / member functions
    // -------------------------------------------------------------------------
    void study() {
        cout << name << " is studying C++ OOPs." << endl;
    }

    void sleep() {
        cout << name << " is sleeping." << endl;
    }

    void bunk() {
        cout << name << " is bunking classes." << endl;
    }
};

void studentExample() {
    // Student is a user-defined data type; s1 is an object of that type.
    Student s1;

    // Assign concrete values to this particular object.
    s1.id = 101;
    s1.age = 20;
    s1.name = "Love Babbar";
    s1.numSubjects = 5;

    cout << "Student id: " << s1.id << endl;
    cout << "Student age: " << s1.age << endl;
    cout << "Student name: " << s1.name << endl;
    cout << "Number of subjects: " << s1.numSubjects << endl;

    // The dot operator calls a member function on an object.
    s1.study();
    s1.sleep();
    s1.bunk();
}

// =============================================================================
// 3. Class versus object
// =============================================================================

/*
    CLASS
    -----
    - A class is a blueprint, template, or design.
    - It describes which attributes and behaviours its objects will have.
    - It is a user-defined data type.
    - The class definition itself does not contain the individual values of
      every future object.

    OBJECT
    ------
    - An object is an instance of a class.
    - It has its own concrete values for the class's data members.
    - A non-static object occupies memory when it is created.
    - Multiple objects can be created from one class, and each has separate
      object data.

    Analogy:
    - House blueprint -> class
    - Actual houses built from that blueprint -> objects
    - Mouse design -> class
    - Physical mouse in your hand -> object
    - Car design -> class
    - A Fortuner or Wagon R built from a design -> object
    - Person definition -> class
    - A specific person -> object

    Important memory clarification:
    A class describes the layout and functions. The non-static data members are
    stored separately for each object. Member functions are generally shared as
    program code rather than copied into every object. An empty class still has
    a non-zero sizeof value in C++ so that distinct objects can have distinct
    addresses; this is an implementation detail, not a useful data field.
*/

class Car {
public:
    string model;
    int year;

    void display() {
        cout << year << " " << model << endl;
    }
};

void classAndObjectExample() {
    Car car1;
    car1.model = "Fortuner";
    car1.year = 2024;

    Car car2;
    car2.model = "Wagon R";
    car2.year = 2023;

    // car1 and car2 use the same class definition but hold different values.
    cout << "car1: ";
    car1.display();
    cout << "car2: ";
    car2.display();

    cout << "Address of car1: " << &car1 << endl;
    cout << "Address of car2: " << &car2 << endl;
    cout << "Size of one Car object: " << sizeof(Car) << " bytes" << endl;
}

// =============================================================================
// 4. A class is a custom user-defined data type
// =============================================================================

/*
    Built-in type:

        int a;

    Here, int is a type supplied by C++ and a is a variable of that type.

    User-defined type:

        Student s1;

    Here, Student is a type defined by us and s1 is a variable (object) of that
    type. Since Student contains both data and functions, it can model a
    meaningful entity more effectively than separate primitive variables.
*/

void userDefinedTypeExample() {
    Student s1;
    Student s2;

    s1.name = "Aarav";
    s2.name = "Diya";

    // Each object has independent data.
    s1.age = 19;
    s2.age = 21;

    cout << s1.name << " is " << s1.age << " years old." << endl;
    cout << s2.name << " is " << s2.age << " years old." << endl;
}

// =============================================================================
// 5. Procedural and object-oriented paradigms
// =============================================================================

/*
    A programming paradigm is a general style or approach to writing programs.

    Procedural / functional style:
    - Focuses mainly on functions and the sequence of operations.
    - Common examples include C, Pascal, and FORTRAN.
    - Data and operations may remain separate unless the programmer creates
      their own structure.

    Object-oriented style:
    - Focuses on entities and the responsibilities of those entities.
    - Uses classes and objects to model a problem.
    - C++, Java, Python, and JavaScript support object-oriented techniques.

    These categories are simplified. Modern languages can support more than
    one programming style, and C++ supports procedural, object-oriented, and
    generic programming.
*/

// =============================================================================
// 6. Important terminology
// =============================================================================

/*
    OOP vocabulary:

    - Class: blueprint and user-defined type.
    - Object: instance of a class.
    - Data member: variable declared inside a class.
    - Member function / method: function declared inside a class.
    - Attribute / state: a property or current data of an object.
    - Behaviour: an action provided by an object's member function.
    - Instantiation: creating an object from a class.
    - Dot operator (.): accesses a public member through an object.

    In later chapters, OOP will be developed further through encapsulation,
    inheritance, polymorphism, and abstraction.
*/

// =============================================================================
// 7. Chapter 1 practice questions
// =============================================================================

/*
    Try answering these before checking your understanding:

    1. What is the difference between a class and an object?
    2. Why is Student a data type and s1 an object?
    3. Which members of Student represent state?
    4. Which members of Student represent behaviour?
    5. Why can two objects of the same class store different values?
    6. What problem occurs when related variables and functions are scattered?
    7. What does the dot operator do in s1.study()?
    8. Does creating a class automatically create a Student object?
    9. What is the difference between a blueprint and the thing built from it?
    10. Why is grouping data and behaviour useful in a large program?

    Practice task:
    Create a Book class with title, author, and pageCount attributes and
    read(), bookmark(), and display() member functions. Create two Book
    objects with different values and call their functions.
*/

int main() {
    cout << "===== Student: data and behaviour in one object =====" << endl;
    studentExample();

    cout << "\n===== Class versus objects =====" << endl;
    classAndObjectExample();

    cout << "\n===== User-defined data type =====" << endl;
    userDefinedTypeExample();

    return 0;
}
