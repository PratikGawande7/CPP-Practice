/*
    Complete C++ OOPs - Chapter 7
    Topic: Miscellaneous and Advanced OOP Concepts
    Source: Love Babbar - Complete C++ OOPS in 1 Shot
    Timestamp: 02:50:00

    This chapter collects frequently asked C++ mechanics:
    const correctness, mutable, static members, friends, deep copying,
    private constructors, singleton design, and virtual destructors.
*/

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// =============================================================================
// 1. const correctness and mutable
// =============================================================================

/*
    A const object cannot be modified after initialization.

    Three common pointer forms:

        const int* pointer;       // pointer to const int
        int* const pointer;       // const pointer to int
        const int* const pointer; // const pointer to const int

    1. Pointer to const:
           The pointed-to value cannot be changed through this pointer, but the
           pointer may point somewhere else.

    2. Const pointer:
           The pointer cannot point somewhere else, but the pointed-to int may
           be changed through the pointer.

    3. Const pointer to const:
           Neither the address nor the value may be changed through it.
*/

void constPointerExample() {
    cout << "===== const pointers =====" << endl;

    int first = 10;
    int second = 20;

    const int* pointerToConst = &first;
    // *pointerToConst = 11; // Error: value cannot be changed through pointer.
    pointerToConst = &second; // The pointer itself can be redirected.

    int* const constPointer = &first;
    *constPointer = 11; // The pointed-to value can be changed.
    // constPointer = &second; // Error: address cannot be redirected.

    const int* const fullyConstPointer = &second;
    // *fullyConstPointer = 21; // Error.
    // fullyConstPointer = &first; // Error.

    cout << "Pointer-to-const now points to: " << *pointerToConst << endl;
    cout << "Const pointer value: " << *constPointer << endl;
    cout << "Fully const pointer value: " << *fullyConstPointer << endl;
    cout << "first: " << first << ", second: " << second << endl;
}

class ReadingCounter {
private:
    string value;
    mutable int readCount;

public:
    explicit ReadingCounter(const string& initialValue)
        : value(initialValue), readCount(0) {}

    /*
        A const member function promises not to change the observable logical
        state of the object. It can be called on const and non-const objects.
        mutable allows bookkeeping such as a cache or access counter to change
        without breaking that promise.
    */
    const string& getValue() const {
        ++readCount;
        return value;
    }

    int getReadCount() const {
        return readCount;
    }
};

void constMemberExample() {
    cout << "\n===== const member functions and mutable =====" << endl;

    const ReadingCounter counter("OOP learning");
    cout << "Value: " << counter.getValue() << endl;
    cout << "Value: " << counter.getValue() << endl;
    cout << "Read count: " << counter.getReadCount() << endl;

    // counter.value = "changed"; // Error: const object and private state.
}

// =============================================================================
// 2. static data members and static member functions
// =============================================================================

/*
    A static data member belongs to the class, not to an individual object.
    There is one shared copy for the class.

    A static member function:
    - Can be called with ClassName::function().
    - Has no implicit this pointer.
    - Can directly access static members.
    - Cannot directly access non-static members because no particular object
      has been supplied.

    Before C++17, an out-of-class definition was required for a static data
    member. This example uses the traditional definition so the rule is clear.
*/

class Student {
private:
    int id;
    string name;
    float* gpa;

    static int totalStudentsCount;

public:
    Student(int studentId, const string& studentName, float gpaValue)
        : id(studentId),
          name(studentName),
          gpa(new float(gpaValue)) {
        ++totalStudentsCount;
    }

    Student(const Student& source)
        : id(source.id),
          name(source.name),
          gpa(new float(*source.gpa)) {
        ++totalStudentsCount;
        cout << "[Student deep copy constructor]" << endl;
    }

    Student& operator=(const Student& source) {
        if (this == &source) {
            return *this;
        }

        id = source.id;
        name = source.name;
        *gpa = *source.gpa;
        return *this;
    }

    static int getTotalStudents() {
        return totalStudentsCount;
    }

    float getGPA() const {
        return *gpa;
    }

    void setGPA(float newGPA) {
        if (newGPA >= 0.0f && newGPA <= 10.0f) {
            *gpa = newGPA;
        }
    }

    const float* getGPAMemoryAddress() const {
        return gpa;
    }

    ~Student() {
        delete gpa;
        --totalStudentsCount;
    }
};

int Student::totalStudentsCount = 0;

void staticMemberExample() {
    cout << "\n===== static members =====" << endl;
    cout << "Initial live students: " << Student::getTotalStudents() << endl;

    {
        Student first(101, "Love Babbar", 9.8f);
        Student second(102, "Aarav", 8.6f);
        cout << "Live students: " << Student::getTotalStudents() << endl;
        cout << "First GPA: " << first.getGPA() << endl;
        cout << "Second GPA: " << second.getGPA() << endl;
    }

    cout << "After scope: " << Student::getTotalStudents() << endl;
}

// =============================================================================
// 3. friend functions and friend classes
// =============================================================================

/*
    A friend is not a class member, but the class grants it access to private
    and protected members.

    friend access:
    - Is granted explicitly by the class.
    - Is not automatically mutual.
    - Is not automatically inherited.
    - Should be used narrowly because it increases coupling and bypasses the
      normal public interface.

    A friend function is useful for operations such as symmetric operators or
    tightly coupled formatting. A friend class gives every member of that other
    class access, so it should be used even more carefully.
*/

class Distance {
private:
    int metres;

public:
    explicit Distance(int initialMetres)
        : metres(initialMetres) {}

    friend void addFiveMetres(Distance& distance);
    friend class DistanceInspector;
};

void addFiveMetres(Distance& distance) {
    distance.metres += 5;
}

class DistanceInspector {
public:
    static int readMetres(const Distance& distance) {
        return distance.metres;
    }
};

void friendExample() {
    cout << "\n===== friend function and friend class =====" << endl;

    Distance distance(10);
    addFiveMetres(distance);
    cout << "After friend function: "
         << DistanceInspector::readMetres(distance) << " metres" << endl;
}

// =============================================================================
// 4. shallow copy versus deep copy
// =============================================================================

/*
    A shallow copy copies each member as-is. For a raw pointer, this copies the
    address, so two objects refer to the same heap allocation.

    If both objects own that allocation and both destructors call delete:
    - the first destructor frees the memory;
    - the second destructor attempts to free an already-freed address;
    - the result is undefined behavior, commonly called double free.

    A deep copy allocates independent storage and copies the pointed-to value.
    Each object then owns and destroys its own allocation.

    Student above follows the Rule of Three for its raw pointer:
    destructor, copy constructor, and copy-assignment operator.
    Modern C++ usually prefers a value member or smart pointer to avoid manual
    ownership. This example is intentionally explicit for learning.
*/

void deepCopyExample() {
    cout << "\n===== deep copy =====" << endl;

    Student first(201, "First", 9.5f);
    Student second = first; // Deep copy constructor.

    cout << "First GPA address:  " << first.getGPAMemoryAddress() << endl;
    cout << "Second GPA address: " << second.getGPAMemoryAddress() << endl;

    second.setGPA(7.0f);
    cout << "First GPA after changing second: " << first.getGPA() << endl;
    cout << "Second GPA: " << second.getGPA() << endl;

    /*
        The addresses differ, so changing second does not change first.
        A deliberately shallow-owning class is not included as runnable code
        because its destructor would invoke undefined behavior.
    */
}

// =============================================================================
// 5. Private constructors and singleton design
// =============================================================================

/*
    A private constructor prevents outside code from writing:

        Logger logger;
        new Logger;

    The class can still create an object from its own member function.

    Singleton intent: make one shared object available through a class-level
    access point. The function-local static below is initialized once, is
    destroyed automatically, and is thread-safe since C++11.

    This is safer than a raw static Logger* that requires manual delete and can
    leak. A singleton should still be used sparingly because global shared
    state makes testing and dependencies harder to manage.
*/

class Logger {
private:
    Logger() {
        cout << "[Logger initialized]" << endl;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const string& message) {
        cout << "[LOG] " << message << endl;
    }
};

void singletonExample() {
    cout << "\n===== private constructor and singleton =====" << endl;

    Logger& firstLogger = Logger::getInstance();
    Logger& secondLogger = Logger::getInstance();

    firstLogger.log("One shared logger instance.");
    cout << "Same address: " << (&firstLogger == &secondLogger ? "yes" : "no")
         << endl;

    // Logger logger; // Error: constructor is private.
    // Logger copy = firstLogger; // Error: copying is deleted.
}

// =============================================================================
// 6. Virtual destructors
// =============================================================================

/*
    If a base pointer points to a derived object:

        Base* pointer = new Derived;
        delete pointer;

    the base destructor must be virtual. Otherwise, deleting through Base* is
    undefined behavior and the derived cleanup may not run.

    With virtual ~Base():
        ~Derived() runs first, then ~Base().

    This matters when Derived owns heap resources, file handles, locks, or
    other resources. Prefer RAII and smart pointers, but make a polymorphic
    base destructor virtual whenever deletion through the base is possible.
*/

class BaseResource {
public:
    virtual ~BaseResource() {
        cout << "[BaseResource destructor]" << endl;
    }
};

class DerivedResource : public BaseResource {
private:
    unique_ptr<int[]> data;

public:
    DerivedResource()
        : data(make_unique<int[]>(100)) {
        cout << "[DerivedResource allocated 100 integers]" << endl;
    }

    ~DerivedResource() override {
        cout << "[DerivedResource destructor; array released automatically]"
             << endl;
    }
};

void virtualDestructorExample() {
    cout << "\n===== virtual destructor =====" << endl;

    BaseResource* resource = new DerivedResource();
    delete resource; // Derived destructor first, then base destructor.
}

// =============================================================================
// 7. Summary and practice
// =============================================================================

/*
    Interview summary:

    const member function:
        Promises not to modify ordinary object state and can be called on a
        const object.

    mutable:
        Allows a specific member, commonly a cache or counter, to change in a
        const member function.

    static data member:
        One class-level value shared by all objects.

    static member function:
        Has no this pointer and directly accesses static members only.

    friend:
        Explicitly grants selected non-members private/protected access.

    deep copy:
        Allocates independent heap storage for owned pointer data.

    private constructor:
        Prevents outside construction and can control object creation.

    virtual destructor:
        Enables correct derived cleanup through a base pointer.

    Practice questions:
    1. Explain the three const pointer forms.
    2. Why can a const member function modify a mutable counter?
    3. Why does a static member function have no this pointer?
    4. What access does friend provide and why should it be limited?
    5. What is the difference between copy construction and copy assignment?
    6. Why does shallow copying an owning raw pointer cause double free?
    7. What are the Rule of Three and Rule of Five?
    8. Why are smart pointers preferred for resource ownership?
    9. How does a private constructor support a singleton?
    10. Why must a polymorphic base destructor be virtual?

    Homework:
    - Replace Student's raw float pointer with unique_ptr<float> and implement
      an appropriate deep-copy constructor.
    - Create a static object counter for BankAccount.
    - Add a friend stream-insertion operator for a private data class.
    - Implement a polymorphic FileResource base and derived resources with
      virtual destructors.
*/

int main() {
    constPointerExample();
    constMemberExample();
    staticMemberExample();
    friendExample();
    deepCopyExample();
    singletonExample();
    virtualDestructorExample();

    return 0;
}
