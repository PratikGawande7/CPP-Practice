/*
    C++ STL - Chapter 4
    Topic: Functors, Custom Comparators, and Lambdas
    Source: Love Babbar - C++ STL in 1 Video

    These are learning notes. A functor is an object that can be called like a
    function because its class overloads operator().
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// =============================================================================
// 1. What is a functor?
// =============================================================================

/*
    A functor (function object) is an object with operator() overloaded.

        Functor object;
        object(argument);

    looks like a function call, but the object may store state in data members.

    Why functors are useful in STL:
    - They can carry configuration, such as a multiplication factor.
    - They can be used as sorting and ordering policies.
    - They work naturally as template arguments for set, map, and
      priority_queue.
    - They can be reused instead of repeating comparator logic.
*/

class MultiplierFunctor {
private:
    int factor;

public:
    explicit MultiplierFunctor(int multiplier)
        : factor(multiplier) {}

    int operator()(int number) const {
        return number * factor;
    }
};

void basicFunctorExample() {
    cout << "===== Basic functor =====" << endl;

    MultiplierFunctor multiplyByFive(5);
    cout << "multiplyByFive(10): " << multiplyByFive(10) << endl;
    cout << "multiplyByFive(7): " << multiplyByFive(7) << endl;
}

// =============================================================================
// 2. Comparator ordering contract
// =============================================================================

/*
    A comparator receives two values a and b and returns true when a should
    appear before b according to the requested ordering.

        return a.marks < b.marks;

    means lower marks come first when used by sort.

    A comparator should provide a strict weak ordering:
    - irreflexive: compare(a, a) is false;
    - consistent for equivalent elements;
    - transitive ordering for non-equivalent elements.

    Do not write a comparator using <=. For equal values, both compare(a, b)
    and compare(b, a) should be false.

    const references avoid copying elements, and const operator() allows the
    comparator to be used where the STL stores or invokes it as a const object.
*/

struct Student {
    int rollNumber;
    int marks;
    string name;
};

void printStudent(const Student& student) {
    cout << "Roll: " << student.rollNumber
         << " | Name: " << student.name
         << " | Marks: " << student.marks << endl;
}

struct StudentMarksAscending {
    bool operator()(const Student& first, const Student& second) const {
        if (first.marks != second.marks) {
            return first.marks < second.marks;
        }
        return first.rollNumber < second.rollNumber;
    }
};

void customSortFunctorExample() {
    cout << "\n===== Custom sort comparator functor =====" << endl;

    vector<Student> students{
        {101, 85, "Love"},
        {102, 95, "Babbar"},
        {103, 72, "Rahul"},
        {104, 91, "Kunal"},
        {105, 85, "Diya"}
    };

    sort(students.begin(), students.end(), StudentMarksAscending());

    cout << "Students by marks ascending (roll breaks ties):" << endl;
    for (const Student& student : students) {
        printStudent(student);
    }
}

// =============================================================================
// 3. Comparator behavior in sort and priority_queue
// =============================================================================

/*
    std::sort:
        comparator(a, b) == true means a is placed before b.

        a.marks < b.marks -> smallest marks first.
        a.marks > b.marks -> largest marks first.

    std::priority_queue:
        top() is the element considered highest priority by the heap policy.
        The comparator's meaning can feel reversed compared with sort.

        a.marks > b.marks -> smallest marks at top (min-heap).
        a.marks < b.marks -> largest marks at top (max-heap).

    A good way to remember a priority_queue comparator:
    it describes which element has lower priority than another. The element
    that is not considered lower priority rises to top.
*/

struct StudentMinHeapComparator {
    bool operator()(const Student& first, const Student& second) const {
        if (first.marks != second.marks) {
            return first.marks > second.marks;
        }
        return first.rollNumber > second.rollNumber;
    }
};

struct StudentMaxHeapComparator {
    bool operator()(const Student& first, const Student& second) const {
        if (first.marks != second.marks) {
            return first.marks < second.marks;
        }
        return first.rollNumber < second.rollNumber;
    }
};

void priorityQueueFunctorExample() {
    cout << "\n===== Functors with priority_queue =====" << endl;

    vector<Student> students{
        {101, 85, "Love"},
        {102, 95, "Babbar"},
        {103, 72, "Rahul"},
        {104, 91, "Kunal"}
    };

    priority_queue<Student, vector<Student>, StudentMinHeapComparator> minHeap;
    priority_queue<Student, vector<Student>, StudentMaxHeapComparator> maxHeap;

    for (const Student& student : students) {
        minHeap.push(student);
        maxHeap.push(student);
    }

    cout << "Min-heap order (lowest marks first):" << endl;
    while (!minHeap.empty()) {
        printStudent(minHeap.top());
        minHeap.pop();
    }

    cout << "Max-heap order (highest marks first):" << endl;
    while (!maxHeap.empty()) {
        printStudent(maxHeap.top());
        maxHeap.pop();
    }
}

// =============================================================================
// 4. Functors with ordered containers
// =============================================================================

/*
    A comparator can be part of a container's type:

        set<int, greater<int>>

    The comparator defines the ordering used by the tree. It is not merely a
    one-time sort operation. The container uses it for insertion, lookup, and
    maintaining its invariants.

    The comparator must remain logically consistent while the container is
    alive. Changing the comparison rule in a way that contradicts existing
    elements breaks ordered-container behavior.
*/

struct StudentNameDescending {
    bool operator()(const Student& first, const Student& second) const {
        if (first.name != second.name) {
            return first.name > second.name;
        }
        return first.rollNumber < second.rollNumber;
    }
};

void orderedContainerFunctorExample() {
    cout << "\n===== Functor with set =====" << endl;

    set<Student, StudentNameDescending> students{
        {101, 85, "Love"},
        {102, 95, "Babbar"},
        {103, 72, "Rahul"}
    };

    cout << "Students by name descending:" << endl;
    for (const Student& student : students) {
        printStudent(student);
    }
}

// =============================================================================
// 5. Lambdas: inline anonymous function objects
// =============================================================================

/*
    A lambda is an anonymous callable object introduced in C++11.

        [capture](parameters) -> return_type {
            body
        }

    The return type is usually inferred and can be omitted.

    Capture forms:
    - []       captures nothing.
    - [value]  captures value by copy.
    - [&value] captures value by reference.
    - [=]      captures used outer variables by copy.
    - [&]      captures used outer variables by reference.

    Capturing by reference allows modification of the original variable only
    when the lambda is not const-by-default or the capture is explicitly
    mutable where appropriate. Avoid capturing references that outlive the
    referenced object.
*/

void lambdaExample() {
    cout << "\n===== Lambda comparators and callable state =====" << endl;

    vector<Student> students{
        {101, 85, "Love"},
        {102, 95, "Babbar"},
        {103, 72, "Rahul"}
    };

    sort(students.begin(), students.end(),
         [](const Student& first, const Student& second) {
             return first.marks > second.marks;
         });

    cout << "Descending marks with a lambda:" << endl;
    for (const Student& student : students) {
        printStudent(student);
    }

    int threshold = 80;
    int countAtLeastThreshold = count_if(
        students.begin(), students.end(),
        [threshold](const Student& student) {
            return student.marks >= threshold;
        });
    cout << "Students with marks >= " << threshold << ": "
         << countAtLeastThreshold << endl;

    int calls = 0;
    for_each(students.begin(), students.end(),
             [&calls](const Student&) {
                 ++calls;
             });
    cout << "Lambda calls counted by reference: " << calls << endl;
}

// =============================================================================
// 6. Standard function objects
// =============================================================================

/*
    The standard library provides common function objects in <functional>:

        less<T>()       a < b
        greater<T>()    a > b
        equal_to<T>()   a == b
        plus<T>()       a + b

    They are useful when no custom state or special logic is needed.
*/

void standardFunctorExample() {
    cout << "\n===== Standard function objects =====" << endl;

    vector<int> values{4, 1, 5, 2, 3};
    sort(values.begin(), values.end(), greater<int>());

    cout << "Descending with greater<int>: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << endl;

    cout << "less<int>(2, 5): " << (less<int>()(2, 5) ? "true" : "false")
         << endl;
    cout << "greater<int>(5, 2): "
         << (greater<int>()(5, 2) ? "true" : "false") << endl;
}

// =============================================================================
// 7. Summary, mistakes, and practice
// =============================================================================

/*
    Functor versus function versus lambda:

    Plain function:
        Simple reusable callable, but state must be supplied separately.

    Functor:
        Class/struct object with operator(); can store state and has a named,
        reusable type.

    Lambda:
        Concise anonymous callable; can capture local state and is ideal for
        one-off algorithm customization.

    Common mistakes:
    - Returning <= from a sorting comparator.
    - Forgetting that priority_queue comparator behavior differs from visual
      sort order.
    - Writing a comparator that gives contradictory results for equal values.
    - Capturing a local variable by reference after its lifetime ends.
    - Changing an ordered container's comparison assumptions.
    - Copying large objects in a comparator instead of using const references.

    Practice questions:
    1. What is a functor?
    2. How does operator() make an object callable?
    3. Why can a functor maintain state?
    4. What does comparator true mean for sort?
    5. Why does a priority_queue min-heap comparator look reversed?
    6. What is strict weak ordering?
    7. Why should comparator parameters usually be const references?
    8. What is a lambda capture list?
    9. What is the difference between [=] and [&]?
    10. When should you choose a named functor over a lambda?
    11. How is a comparator used by set beyond initial ordering?
    12. What are less and greater?

    Homework:
    - Sort a vector of pairs by second value descending and first value
      ascending when tied.
    - Create a functor that multiplies every value by a configurable factor and
      use it with transform().
    - Create a priority_queue of tasks ordered by priority, then by task ID.
    - Use a lambda to sort strings by length, then alphabetically.
    - Create a set with a case-insensitive comparator and document the
      equivalence behavior.
*/

int main() {
    cout << "=================== C++ STL CHAPTER 4: FUNCTORS ==================="
         << endl;

    basicFunctorExample();
    customSortFunctorExample();
    priorityQueueFunctorExample();
    orderedContainerFunctorExample();
    lambdaExample();
    standardFunctorExample();

    return 0;
}
