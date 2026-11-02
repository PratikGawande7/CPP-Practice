/*
    Complete C++ OOPs - Chapter 2
    Topic: Class Basics, Object Memory, and Object Lifecycle
    Source: Love Babbar - Complete C++ OOPS in 1 Shot
    Timestamp: 00:37:00

    These are detailed learning notes. Read the explanations and run the
    examples to observe construction, copying, destruction, and memory use.
*/

#include <iostream>
#include <string>

using namespace std;

// =============================================================================
// 1. Class syntax and access specifiers
// =============================================================================

/*
    General class syntax:

        class ClassName {
        public:
            // members accessible from outside

        private:
            // members accessible only through class member functions

        protected:
            // accessible in this class and derived classes
        };

    The semicolon after the closing brace is mandatory.

    A class's default access level is private. Therefore, members written
    before the first access-specifier cannot be accessed directly from main().
    A struct is similar, but its default access level is public.
*/

class PrivateByDefault {
    int value; // private because no access specifier appears before it

public:
    void setValue(int newValue) {
        value = newValue;
    }

    int getValue() const {
        return value;
    }
};

class AccessExample {
public:
    int publicValue;

private:
    int privateValue;

public:
    void setPrivateValue(int newValue) {
        privateValue = newValue;
    }

    int getPrivateValue() const {
        return privateValue;
    }
};

void accessSpecifierExample() {
    PrivateByDefault object;

    // object.value = 10; // Error: value is private.
    object.setValue(10);
    cout << "Private value through a public function: "
         << object.getValue() << endl;

    AccessExample accessObject;
    accessObject.publicValue = 20;
    accessObject.setPrivateValue(30);

    cout << "Public value: " << accessObject.publicValue << endl;
    cout << "Private value through getter: "
         << accessObject.getPrivateValue() << endl;
}

// =============================================================================
// 2. Empty classes and object size
// =============================================================================

class EmptyClass {
    // No non-static data members.
};

/*
    sizeof(EmptyClass) is normally 1 byte, not 0.

    An object must have a distinct address from another object of the same type.
    If an empty object had size zero, placing two objects next to each other
    would give them the same address. C++ therefore gives an empty class a
    non-zero size. The exact object layout is controlled by the implementation,
    but the language guarantees that distinct complete objects have distinct
    addresses.

    Member functions do not usually add one copy of their machine code to every
    object. Object size primarily reflects its non-static data members, padding,
    and alignment.
*/

void emptyClassExample() {
    EmptyClass first;
    EmptyClass second;

    cout << "Size of EmptyClass: " << sizeof(EmptyClass) << " byte(s)" << endl;
    cout << "Address of first empty object: " << &first << endl;
    cout << "Address of second empty object: " << &second << endl;
}

// =============================================================================
// 3. Static and dynamic object allocation
// =============================================================================

class BasicStudent {
public:
    int age;

    void printAge() const {
        cout << "Student age: " << age << endl;
    }
};

/*
    Static object creation:

        BasicStudent student;
        student.age = 20;
        student.printAge();

    The object has automatic storage duration when declared inside a function.
    It is commonly described as a stack object and is destroyed automatically
    when its scope ends.

    Dynamic object creation:

        BasicStudent* student = new BasicStudent();
        student->age = 21;
        student->printAge();
        delete student;

    new creates an object with dynamic storage duration and returns its address.
    The pointer itself is a local variable, but the object it points to is
    dynamically allocated. delete destroys that one object and releases its
    storage.

    The arrow operator p->member is shorthand for (*p).member.
*/

void allocationExample() {
    BasicStudent staticStudent;
    staticStudent.age = 20;
    staticStudent.printAge();

    BasicStudent* dynamicStudent = new BasicStudent();
    dynamicStudent->age = 21;
    dynamicStudent->printAge();
    cout << "Same access using (*pointer).member: ";
    cout << (*dynamicStudent).age << endl;

    delete dynamicStudent;
    dynamicStudent = nullptr; // Avoid keeping a dangling pointer.
}

/*
    Do not write:

        BasicStudent student();

    inside a block when you intend to create an object. This is parsed as a
    function declaration returning BasicStudent and taking no arguments. This
    is called the Most Vexing Parse. Use BasicStudent student{}; or
    BasicStudent student; instead.
*/

// =============================================================================
// 4. Constructors
// =============================================================================

/*
    A constructor is a special member function that runs when an object is
    initialized.

    Rules:
    - Its name exactly matches the class name.
    - It has no return type, not even void.
    - It initializes an object and can establish valid starting state.
    - It is called automatically during object creation.

    A constructor with no parameters is a default constructor. A constructor
    with parameters is a parameterized constructor. Constructors can be
    overloaded, so one class can provide several ways to initialize objects.
*/

class Student {
public:
    int id;
    int age;
    string name;
    float* gpa;

    // Default constructor.
    Student()
        : id(0), age(0), name("Dummy"), gpa(new float(0.0f)) {
        cout << "[Default constructor] object created at " << this << endl;
    }

    // Parameterized constructor. "this" points to the current object.
    Student(int id, int age, const string& name, float gpaValue)
        : id(id), age(age), name(name), gpa(new float(gpaValue)) {
        cout << "[Parameterized constructor] object created at "
             << this << endl;
    }

    /*
        Constructor initialization list:

            Student(...) : id(id), age(age), name(name) { ... }

        The left side of each pair is the data member. The right side is the
        parameter. Members are initialized before the constructor body runs.
        This is the proper way to initialize const members, reference members,
        and members without a default constructor. It also avoids constructing
        a member first and assigning to it later.

        The expression this->age means "the age member of the current object".
        The shorter initialization-list spelling above avoids a naming
        collision while still showing the same relationship.
    */

    void printDetails() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Age: " << age
             << " | GPA: " << *gpa << endl;
    }

    // Copy constructor: creates a new object from an existing Student.
    Student(const Student& source)
        : id(source.id),
          age(source.age),
          name(source.name),
          gpa(new float(*source.gpa)) {
        cout << "[Copy constructor] copying from " << &source
             << " into " << this << endl;
    }

    /*
        The parameter is a const reference:

            const Student& source

        Passing by reference avoids making another Student copy just to pass
        the argument. If it were passed by value, creating that parameter
        would itself need the copy constructor, which would need another copy
        forever and eventually cause stack overflow.

        const means the source object is not modified during copying.
    */

    // Destructor: releases the memory owned by this object.
    ~Student() {
        cout << "[Destructor] destroying object at " << this << endl;
        delete gpa;
        gpa = nullptr;
    }
};

void constructorAndCopyExample() {
    cout << "\n--- Constructors and copy constructor ---" << endl;

    Student defaultStudent;
    defaultStudent.printDetails();

    Student first(101, 20, "Love Babbar", 9.5f);
    first.printDetails();

    // Both forms create a new object using the copy constructor.
    Student second = first;
    Student third(first);
    second.printDetails();
    third.printDetails();

    /*
        Student's copy constructor performs a deep copy:
        first.gpa and second.gpa point to different float objects containing
        equal values. This means each Student can delete its own resource safely.
    */
    cout << "first.gpa address:  " << first.gpa << endl;
    cout << "second.gpa address: " << second.gpa << endl;
}

// =============================================================================
// 5. Destructors and memory leaks
// =============================================================================

/*
    A destructor:
    - Has the class name preceded by ~.
    - Has no return type and takes no parameters.
    - Runs when an object is destroyed.
    - Is called automatically for automatic objects at scope exit.
    - Runs for a dynamic object when delete is explicitly used.

    In this lesson Student owns a float allocated with new. Its destructor must
    call delete exactly once. If delete is omitted, the float leaks. If two
    objects point to the same float and both destructors delete it, the program
    has a double-delete error. Deep copying avoids that ownership collision.
*/

void destructorAndDynamicExample() {
    cout << "\n--- Automatic lifetime ---" << endl;
    {
        Student scopedStudent(102, 22, "Rahul", 8.8f);
        scopedStudent.printDetails();
    } // Destructor runs automatically here.

    cout << "\n--- Dynamic lifetime ---" << endl;
    Student* heapStudent = new Student(103, 23, "Diya", 9.1f);
    heapStudent->printDetails();

    delete heapStudent; // Calls destructor and releases the Student object.
    heapStudent = nullptr;
}

// =============================================================================
// 6. Shallow copy warning and structure padding
// =============================================================================

/*
    A default copy constructor copies each member as-is. For a raw pointer,
    that means it copies the address, not the pointed-to value. This is called
    a shallow copy. If the pointer represents owned memory, multiple objects
    can then try to delete the same address.

    Student avoids that problem by allocating a separate float in its custom
    copy constructor. That is a deep copy.

    Do not run a broken shallow-copy example as part of this program; it can
    cause undefined behavior. It is enough to reason about:

        this->gpa = source.gpa;       // shallow: same address
        this->gpa = new float(*source.gpa); // deep: separate address

    Structure padding:
    Compilers may insert unused padding bytes between members so objects meet
    alignment requirements. Therefore sizeof(structure) is not always the sum
    of member sizes. For example, a char followed by an int may occupy 8 bytes
    instead of 5 on a common implementation. Exact results are implementation-
    dependent.
*/

class PaddingExample {
public:
    char letter;
    int number;
};

void paddingExample() {
    cout << "\nSize of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of PaddingExample: " << sizeof(PaddingExample)
         << " bytes (implementation-dependent)" << endl;
}

// =============================================================================
// 7. Summary and practice
// =============================================================================

/*
    Quick comparison:

    Feature              Automatic object         Dynamic object
    ---------------------------------------------------------------------------
    Example              Student s;               Student* s = new Student;
    Access               s.member                s->member
    Storage duration     Scope-based              Until delete
    Destruction          Automatic                delete is required
    Main risk             Scope too short          Memory leak if not deleted

    Practice questions:
    1. Why is a class's default access private?
    2. Why does an empty class have a non-zero size?
    3. What is the difference between . and ->?
    4. What does new return?
    5. Why must every owned new have a matching delete?
    6. What is the Most Vexing Parse?
    7. Why does a constructor have no return type?
    8. What does this represent?
    9. Why is const Student& used in a copy constructor?
    10. What is the difference between shallow and deep copy?
    11. When does a stack object's destructor run?
    12. What happens if delete is never called for a heap object?

    Homework:
    - Add a Book class with default and parameterized constructors.
    - Add a copy constructor and observe the addresses of its string/pointer
      members.
    - Compare sizeof classes with different member ordering.
*/

int main() {
    cout << "===== Access specifiers =====" << endl;
    accessSpecifierExample();

    cout << "\n===== Empty class =====" << endl;
    emptyClassExample();

    cout << "\n===== Static and dynamic allocation =====" << endl;
    allocationExample();

    constructorAndCopyExample();
    destructorAndDynamicExample();
    paddingExample();

    return 0;
}
