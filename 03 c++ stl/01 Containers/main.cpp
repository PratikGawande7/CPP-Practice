/*
    C++ STL - Chapter 1
    Topic: Introduction to STL and Containers
    Source: Love Babbar - C++ STL in 1 Video

    These are learning notes. This master file demonstrates the main container
    families, their interfaces, typical complexity, and important edge cases.
*/

#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// =============================================================================
// 1. What is the C++ Standard Template Library?
// =============================================================================

/*
    STL stands for Standard Template Library. It is a collection of generic
    components supplied by the C++ standard library.

    The main STL building blocks are:

    1. Containers:
       Store and organize collections of objects.

    2. Iterators:
       Generalized pointers used to traverse container elements.

    3. Algorithms:
       Reusable operations such as sort, find, reverse, and binary_search.

    4. Function objects (functors):
       Objects that behave like functions and can customize algorithms.

    Templates make these components work with many data types. For example,
    vector<int> and vector<string> use the same vector template with different
    element types.

    A container is not automatically the best choice for every problem. Select
    one according to access needs, ordering, uniqueness, insertion pattern, and
    ownership/lifetime requirements.
*/

// =============================================================================
// 2. Sequence containers
// =============================================================================

/*
    Sequence containers store elements in a linear sequence.

    vector:
    - Contiguous dynamic array.
    - Fast random access with [] or at().
    - push_back is amortized O(1); reallocation can make one insertion O(N).
    - Inserting/removing in the middle is O(N).
    - reserve() can reduce reallocations when a size estimate is known.

    list:
    - Doubly linked list.
    - No [] or random access.
    - Insertion/removal at a position is O(1) after an iterator to that
      position has been obtained.
    - Finding a position is O(N).
    - Each node has pointer overhead and elements are not contiguous.

    deque:
    - Double-ended sequence with segmented storage.
    - Fast insertion/removal at both front and back.
    - Supports random access, although it is not necessarily contiguous.
    - Insertion in the middle is linear.
*/

void vectorExample() {
    cout << "===== vector: dynamic contiguous array =====" << endl;

    vector<int> numbers;
    numbers.reserve(5); // Optional: reserve storage before inserting.
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.emplace_back(30); // Constructs an element at the end.

    cout << "Elements: ";
    for (int number : numbers) {
        cout << number << ' ';
    }
    cout << "\nSize: " << numbers.size()
         << "\nCapacity: " << numbers.capacity() << endl;

    // [] is fast but performs no bounds check.
    cout << "numbers[1]: " << numbers[1] << endl;

    // at() checks bounds and throws out_of_range for an invalid index.
    cout << "numbers.at(0): " << numbers.at(0) << endl;

    cout << "Front: " << numbers.front()
         << " | Back: " << numbers.back() << endl;

    numbers.pop_back();
    numbers.insert(numbers.begin() + 1, 15);
    cout << "After pop_back and insert: ";
    for (int number : numbers) {
        cout << number << ' ';
    }
    cout << endl;

    numbers.erase(numbers.begin() + 1);
    cout << "After erase: ";
    for (int number : numbers) {
        cout << number << ' ';
    }
    cout << endl;

    numbers.clear();
    cout << "Empty after clear(): " << (numbers.empty() ? "yes" : "no")
         << endl;

    /*
        Important vector facts:
        - size() is the number of actual elements.
        - capacity() is allocated element storage available before another
          reallocation is needed.
        - clear() removes elements but is not required to reduce capacity.
        - push_back/emplace_back can invalidate pointers, references, and
          iterators if reallocation occurs.
    */
}

void listExample() {
    cout << "\n===== list: doubly linked list =====" << endl;

    list<int> values;
    values.push_back(20);
    values.push_front(10);
    values.push_back(30);

    cout << "Elements: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << endl;

    values.push_front(5);
    values.pop_back();

    // Find an iterator before inserting at that position.
    list<int>::iterator position = values.begin();
    ++position;
    values.insert(position, 15);

    cout << "After front/back operations and insert: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << endl;

    /*
        list does not support values[2]. To reach an index, advance an
        iterator, which takes linear time. list is useful when stable iterators
        and frequent local insertions/erasures matter more than cache-friendly
        traversal and random access.
    */
}

void dequeExample() {
    cout << "\n===== deque: double-ended queue =====" << endl;

    deque<int> values;
    values.push_back(20);
    values.push_front(10);
    values.emplace_back(30);
    values.emplace_front(5);

    cout << "Elements: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << "\nvalues[2]: " << values[2] << endl;

    values.pop_front();
    values.pop_back();
    cout << "After removing both ends: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << endl;
}

// =============================================================================
// 3. Container adapters
// =============================================================================

/*
    Container adapters provide a restricted interface over an underlying
    container. They do not expose every operation of that underlying container.

    stack:
    - LIFO: last in, first out.
    - top(), push(), emplace(), pop(), empty(), size().
    - pop() removes but does not return the element. Read top() first.

    queue:
    - FIFO: first in, first out.
    - front(), back(), push(), emplace(), pop(), empty(), size().
    - pop() also returns void.

    priority_queue:
    - The highest-priority element is at top().
    - Default priority_queue<int> is a max-heap.
    - priority_queue<int, vector<int>, greater<int>> is a min-heap.
    - push/pop are O(log N); top is O(1).
*/

void stackExample() {
    cout << "\n===== stack: LIFO =====" << endl;

    stack<int> values;
    values.push(100);
    values.push(200);
    values.emplace(300);

    while (!values.empty()) {
        cout << "Top: " << values.top() << endl;
        values.pop();
    }
}

void queueExample() {
    cout << "\n===== queue: FIFO =====" << endl;

    queue<int> values;
    values.push(1);
    values.push(2);
    values.emplace(3);

    while (!values.empty()) {
        cout << "Front: " << values.front()
             << " | Back: " << values.back() << endl;
        values.pop();
    }
}

void priorityQueueExample() {
    cout << "\n===== priority_queue: heap adapter =====" << endl;

    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(30);
    cout << "Max-heap top: " << maxHeap.top() << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(30);
    cout << "Min-heap top: " << minHeap.top() << endl;

    cout << "Max-heap removal order: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << ' ';
        maxHeap.pop();
    }
    cout << "\nMin-heap removal order: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << ' ';
        minHeap.pop();
    }
    cout << endl;
}

// =============================================================================
// 4. Associative containers
// =============================================================================

/*
    Associative containers organize values by keys.

    map:
    - Stores unique key-value pairs.
    - Keys are ordered by default.
    - Usually implemented as a balanced search tree.
    - find, insert, and erase by key are O(log N).
    - Access with map[key] inserts a default value when the key is absent.
      Use at(key) when missing keys should throw instead of being inserted.

    unordered_map:
    - Stores unique key-value pairs in hash buckets.
    - No sorted iteration order.
    - Average find/insert/erase is O(1), worst case O(N).
    - Hashing and equality must be available for the key type.

    set:
    - Stores unique values in sorted order.
    - Usually a balanced search tree.
    - Search/insert/erase are O(log N).

    unordered_set:
    - Stores unique values using hashing.
    - No sorted iteration order.
    - Average search/insert/erase is O(1), worst case O(N).

    In all these containers, duplicate insertion does not create another copy
    of a key/value. For map and set, ordering is a deliberate feature; for
    unordered containers, never rely on printed iteration order.
*/

void mapExample() {
    cout << "\n===== map: ordered key-value pairs =====" << endl;

    map<string, int> marks;
    marks["Love"] = 100;
    marks["Babbar"] = 99;
    marks.insert({"Aarav", 95});

    cout << "marks[Love]: " << marks.at("Love") << endl;

    // find() avoids accidentally inserting a missing key.
    if (marks.find("Missing") == marks.end()) {
        cout << "Missing key was not found." << endl;
    }

    cout << "Ordered entries: ";
    for (const pair<const string, int>& entry : marks) {
        cout << '(' << entry.first << ", " << entry.second << ") ";
    }
    cout << endl;

    // operator[] inserts "New" with value 0 before assigning 88.
    marks["New"] = 88;
    marks.erase("Babbar");
}

void unorderedMapExample() {
    cout << "\n===== unordered_map: hash key-value pairs =====" << endl;

    unordered_map<string, int> frequencies;
    frequencies["apple"]++;
    frequencies["apple"]++;
    frequencies["banana"]++;

    cout << "apple frequency: " << frequencies.at("apple") << endl;
    cout << "Entries (order is unspecified): ";
    for (const auto& entry : frequencies) {
        cout << '(' << entry.first << ", " << entry.second << ") ";
    }
    cout << endl;
}

void setExample() {
    cout << "\n===== set: ordered unique values =====" << endl;

    set<int> values;
    values.insert(20);
    values.insert(10);
    values.insert(20); // Duplicate is ignored.
    values.insert(30);

    cout << "Sorted unique values: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << endl;

    if (values.count(20) == 1) {
        cout << "20 exists in the set." << endl;
    }

    values.erase(10);
}

void unorderedSetExample() {
    cout << "\n===== unordered_set: hash unique values =====" << endl;

    unordered_set<string> languages;
    languages.insert("C++");
    languages.insert("Python");
    languages.insert("C++"); // Duplicate is ignored.

    cout << "Unique values (order is unspecified): ";
    for (const string& language : languages) {
        cout << language << ' ';
    }
    cout << endl;
}

// =============================================================================
// 5. Choosing a container and complexity summary
// =============================================================================

/*
    Choose:
    - vector when you need a general-purpose dynamic array or random access.
    - list when local insertion/erasure with an iterator and stable nodes are
      more important than random access and cache locality.
    - deque when you need efficient operations at both ends plus indexing.
    - stack for LIFO access.
    - queue for FIFO access.
    - priority_queue when repeatedly retrieving the highest/lowest priority.
    - map/set when sorted keys or values are required.
    - unordered_map/unordered_set for average constant-time lookup and no
      ordering requirement.

    Typical complexities:

    Container       Access/search       Insert/erase             Special
    vector          random access O(1)  end amortized O(1)       contiguous
                    middle O(N)         middle O(N)
    list            traversal O(N)     position O(1)*           no random access
    deque           random access O(1)  ends O(1)                segmented storage
    stack           top O(1)           top O(1)                  LIFO
    queue           ends O(1)          ends O(1)                 FIFO
    priority_queue  top O(1)           push/pop O(log N)         heap
    map             key O(log N)       O(log N)                 sorted keys
    set             key O(log N)       O(log N)                 sorted unique values
    unordered_map   average O(1)       average O(1)              hash table
    unordered_set   average O(1)       average O(1)              hash table

    * For list, O(1) insertion/erasure assumes an iterator already points to
      the target position. Finding that iterator may take O(N).
*/

void emptyContainerSafetyExample() {
    cout << "\n===== safe access checks =====" << endl;

    vector<int> values;
    if (values.empty()) {
        cout << "Cannot call front(), back(), or pop_back() on an empty vector."
             << endl;
    }

    stack<int> valuesStack;
    if (valuesStack.empty()) {
        cout << "Cannot call top() or pop() on an empty stack." << endl;
    }

    queue<int> valuesQueue;
    if (valuesQueue.empty()) {
        cout << "Cannot call front(), back(), or pop() on an empty queue."
             << endl;
    }
}

// =============================================================================
// 6. Practice questions and homework
// =============================================================================

/*
    Practice questions:
    1. What does STL stand for?
    2. What are the four main STL component categories?
    3. What is the difference between size() and capacity() in vector?
    4. Why is vector[] different from vector::at()?
    5. Why does list not support random access?
    6. What do LIFO and FIFO mean?
    7. Why does priority_queue<int> behave as a max-heap?
    8. What happens when map[key] is used for a missing key?
    9. Why does a set ignore duplicates?
    10. What is the average and worst-case complexity of unordered_map lookup?
    11. When should you prefer map over unordered_map?
    12. Why must empty containers be checked before front(), top(), or back()?

    Homework:
    - Implement a word-frequency counter using unordered_map<string, int>.
    - Store student marks in map<string, int> and print them in sorted key order.
    - Use a priority_queue to print the three largest values.
    - Remove duplicates from a vector using set, then compare the ordering with
      unordered_set.
    - Compare vector and list for insertion at the beginning, and explain why
      their theoretical complexities differ.
    - Create a small menu program using stack for undo operations and queue for
      customer service requests.
*/

int main() {
    cout << "=================== C++ STL CHAPTER 1: CONTAINERS ==================="
         << endl;

    vectorExample();
    listExample();
    dequeExample();
    stackExample();
    queueExample();
    priorityQueueExample();
    mapExample();
    unorderedMapExample();
    setExample();
    unorderedSetExample();
    emptyContainerSafetyExample();

    return 0;
}
