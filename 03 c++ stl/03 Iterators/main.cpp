/*
    C++ STL - Chapter 3
    Topic: Iterators and Traversal Mechanics
    Source: Love Babbar - C++ STL in 1 Video

    An iterator is a pointer-like object that provides a common way to
    navigate through different container types.
*/

#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// =============================================================================
// 1. What is an iterator?
// =============================================================================

/*
    Containers store elements in different ways:

    - vector and deque support random access.
    - list stores linked nodes.
    - set and map store tree nodes.
    - forward_list stores a singly linked chain.

    An index loop such as values[i] works only with containers that provide
    indexing. Iterators provide a standard interface:

        auto it = container.begin();
        while (it != container.end()) {
            use(*it);
            ++it;
        }

    A range [first, last) includes first and excludes last. end() is a
    past-the-end sentinel; it does not point to the last element and must never
    be dereferenced.

    Dereferencing:
        *it        accesses the current element.
        it->member accesses a member through an iterator to an object.

    const_iterator allows reading but prevents modifying the element through
    that iterator. cbegin() and cend() explicitly produce const iterators.
*/

void forwardAndReverseTraversalExample() {
    cout << "===== Forward and reverse traversal =====" << endl;

    vector<int> values{10, 20, 30, 40, 50};

    cout << "Forward with explicit iterator: ";
    vector<int>::iterator iterator = values.begin();
    for (; iterator != values.end(); ++iterator) {
        cout << *iterator << ' ';
    }
    cout << endl;

    cout << "Reverse with reverse_iterator: ";
    for (vector<int>::reverse_iterator reverseIterator =
             values.rbegin();
         reverseIterator != values.rend();
         ++reverseIterator) {
        cout << *reverseIterator << ' ';
    }
    cout << endl;

    cout << "Read-only traversal with cbegin/cend: ";
    for (vector<int>::const_iterator readOnly = values.cbegin();
         readOnly != values.cend();
         ++readOnly) {
        cout << *readOnly << ' ';
    }
    cout << endl;

    // *values.end() is invalid and must not be used.
}

void listAndMapTraversalExample() {
    cout << "\n===== Iterators on non-contiguous containers =====" << endl;

    list<int> linkedValues{10, 20, 30};
    cout << "list: ";
    for (list<int>::iterator iterator = linkedValues.begin();
         iterator != linkedValues.end();
         ++iterator) {
        cout << *iterator << ' ';
    }
    cout << endl;

    map<string, int> marks{{"Aarav", 95}, {"Diya", 98}};
    cout << "map: ";
    for (map<string, int>::const_iterator iterator = marks.cbegin();
         iterator != marks.cend();
         ++iterator) {
        // A map iterator points to a pair<const Key, Value>.
        cout << iterator->first << '=' << iterator->second << ' ';
    }
    cout << endl;

    set<int> orderedValues{30, 10, 20};
    cout << "set: ";
    for (set<int>::const_iterator iterator = orderedValues.cbegin();
         iterator != orderedValues.cend();
         ++iterator) {
        cout << *iterator << ' ';
    }
    cout << endl;
}

// =============================================================================
// 2. Iterator categories
// =============================================================================

/*
    Iterator categories describe the operations an iterator supports:

    1. Input iterator:
       Read values and move forward. A single-pass input iterator is suitable
       for reading a stream, such as istream_iterator.

    2. Output iterator:
       Write values and move forward. ostream_iterator is a common example.

    3. Forward iterator:
       Read/write values and move forward repeatedly. forward_list iterators
       are forward iterators.

    4. Bidirectional iterator:
       Supports forward and backward movement. list, set, and map iterators
       belong here.

    5. Random-access iterator:
       Supports bidirectional movement, it + n, it - n, it[n], and constant-
       time distance for random-access containers. vector and deque iterators
       belong here.

    Each category provides at least the capabilities of the category before it.
    Algorithms choose the weakest category they need so they can work with as
    many containers as possible.
*/

void iteratorCategoryExample() {
    cout << "\n===== Random access versus bidirectional =====" << endl;

    vector<int> vectorValues{100, 200, 300, 400, 500};
    vector<int>::iterator vectorIterator = vectorValues.begin();
    vectorIterator = vectorIterator + 3; // O(1) jump.
    cout << "vector begin + 3: " << *vectorIterator << endl;
    cout << "vector[2] through iterator: " << vectorIterator[-1] << endl;

    deque<int> dequeValues{100, 200, 300, 400, 500};
    deque<int>::iterator dequeIterator = dequeValues.begin() + 4;
    cout << "deque begin + 4: " << *dequeIterator << endl;

    list<int> listValues{100, 200, 300, 400, 500};
    list<int>::iterator listIterator = listValues.begin();
    // listIterator = listIterator + 3; // Error: list is not random access.
    advance(listIterator, 3); // O(3) for list.
    cout << "list after advance by 3: " << *listIterator << endl;

    forward_list<int> forwardValues{100, 200, 300, 400, 500};
    forward_list<int>::iterator forwardIterator = forwardValues.begin();
    advance(forwardIterator, 3);
    cout << "forward_list after advance by 3: "
         << *forwardIterator << endl;
}

// =============================================================================
// 3. Iterator utility functions
// =============================================================================

/*
    advance(iterator, n):
    - Moves the supplied iterator by n positions.
    - Modifies the iterator itself.
    - For random-access iterators, a jump is O(1).
    - For list/set/map/forward_list, it walks nodes and is O(n).
    - Do not advance beyond the valid range.

    next(iterator, n):
    - Returns an iterator n positions after the supplied iterator.
    - Does not modify the original iterator.

    prev(iterator, n):
    - Returns an iterator n positions before the supplied iterator.
    - Requires a bidirectional or random-access iterator.
    - The starting iterator must be far enough from begin.

    distance(first, last):
    - Returns the number of increments needed to reach last.
    - O(1) for random-access iterators.
    - O(N) for linked/tree iterators.
    - The order must be a valid traversal from first to last.
*/

void iteratorUtilitiesExample() {
    cout << "\n===== advance, next, prev, and distance =====" << endl;

    set<int> values{5, 10, 15, 20, 25};
    set<int>::const_iterator start = values.cbegin();
    set<int>::const_iterator third = next(start, 2);
    set<int>::const_iterator previous = prev(third);

    cout << "start: " << *start
         << " | next(start, 2): " << *third
         << " | prev(third): " << *previous << endl;

    auto numberOfElements = distance(values.cbegin(), values.cend());
    cout << "Distance from begin to end: " << numberOfElements << endl;

    vector<int> vectorValues{1, 2, 3, 4, 5};
    vector<int>::iterator moved = vectorValues.begin();
    advance(moved, 2);
    cout << "After advance by 2: " << *moved << endl;
}

// =============================================================================
// 4. Iterator invalidation and safe modification
// =============================================================================

/*
    An iterator is valid only while the container guarantees that it still
    refers to an element.

    Common invalidation rules:

    - vector insertion can invalidate all iterators if reallocation occurs.
      Erasing invalidates the erased iterator and often iterators after it.
    - deque insertion/erasure has more complicated invalidation rules.
    - list insertion does not invalidate existing iterators. Erasing invalidates
      only iterators to erased elements.
    - set/map insertion does not invalidate existing iterators. Erasing
      invalidates only the erased iterator.

    The erase(iterator) overload returns the next valid iterator. This is the
    safe pattern for removing while traversing:

        for (auto it = values.begin(); it != values.end();) {
            if (condition(*it)) {
                it = values.erase(it);
            } else {
                ++it;
            }
        }
*/

void eraseWhileTraversingExample() {
    cout << "\n===== Safe erase while traversing =====" << endl;

    list<int> values{1, 2, 3, 4, 5, 6};
    for (list<int>::iterator iterator = values.begin();
         iterator != values.end();) {
        if (*iterator % 2 == 0) {
            iterator = values.erase(iterator);
        } else {
            ++iterator;
        }
    }

    cout << "Odd values after erasing evens: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << endl;
}

// =============================================================================
// 5. Output iterators and generic traversal
// =============================================================================

void outputIteratorExample() {
    cout << "\n===== Output iterator =====" << endl;

    vector<int> values{10, 20, 30};
    cout << "Values through ostream_iterator: ";
    copy(values.cbegin(), values.cend(),
         ostream_iterator<int>(cout, " "));
    cout << endl;
}

template <typename Container>
void printGenericContainer(const Container& container,
                           const string& label) {
    cout << label;
    for (typename Container::const_iterator iterator = container.cbegin();
         iterator != container.cend();
         ++iterator) {
        cout << *iterator << ' ';
    }
    cout << endl;
}

void genericTraversalExample() {
    cout << "\n===== Generic iterator-based traversal =====" << endl;

    vector<int> vectorValues{1, 2, 3};
    list<int> listValues{4, 5, 6};
    printGenericContainer(vectorValues, "vector: ");
    printGenericContainer(listValues, "list: ");
}

// =============================================================================
// 6. Summary and practice
// =============================================================================

/*
    Container capability summary:

    Container       Category             it + k       it--       Typical use
    vector          random access       yes O(1)      yes        dynamic array
    deque           random access       yes O(1)      yes        double-ended data
    list            bidirectional       no            yes        linked nodes
    set/map         bidirectional       no            yes        ordered trees
    forward_list    forward             no            no         singly linked data

    Practice questions:
    1. Why are iterators needed when vectors support indexes?
    2. What does begin() return?
    3. Why must end() not be dereferenced?
    4. What is reverse_iterator and what do rbegin/rend mean?
    5. What is the difference between iterator and const_iterator?
    6. Which iterator category does vector use?
    7. Why is listIterator + 3 invalid?
    8. What is the difference between advance and next?
    9. When is distance O(1), and when is it O(N)?
    10. Which iterator does erase return?
    11. Why can vector insertion invalidate iterators?
    12. Why can list insertion preserve existing iterators?

    Homework:
    - Traverse a map in forward and reverse order.
    - Use next() to access the fourth element of a list.
    - Use prev() to traverse a set backwards from end().
    - Remove all values greater than 50 using the safe erase pattern.
    - Write one template function that prints vector, list, deque, and set.
    - Use ostream_iterator to copy a vector into cout and an output file.
*/

int main() {
    cout << "=================== C++ STL CHAPTER 3: ITERATORS ==================="
         << endl;

    forwardAndReverseTraversalExample();
    listAndMapTraversalExample();
    iteratorCategoryExample();
    iteratorUtilitiesExample();
    eraseWhileTraversingExample();
    outputIteratorExample();
    genericTraversalExample();

    return 0;
}
