/*
    C++ STL - Chapter 2
    Topic: Algorithms
    Source: Love Babbar - C++ STL in 1 Video

    STL algorithms are generic functions that operate on ranges. A range is
    commonly represented by two iterators: [first, last), where first is
    included and last is one-past-the-end and is excluded.
*/

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

void printVector(const vector<int>& values, const string& label) {
    cout << label;
    for (int value : values) {
        cout << value << ' ';
    }
    cout << endl;
}

// =============================================================================
// 1. What are STL algorithms?
// =============================================================================

/*
    The Standard Template Library provides pre-written, generic algorithms so
    common operations do not need to be implemented from scratch.

    Include:
        <algorithm> for sorting, searching, comparison, and rearrangement.
        <numeric>  for accumulate and other numeric operations.

    Most algorithms do not know which container they operate on. They only
    require iterators with the capabilities they need. For example, sort()
    requires random-access iterators, while find() can work with an input range.

    The usual range convention is [begin, end):
        begin points to the first element.
        end points just after the last element.

    Passing end as the second iterator prevents the algorithm from reading
    beyond the range and makes empty ranges representable.
*/

// =============================================================================
// 2. Sorting and reversing
// =============================================================================

/*
    sort(first, last):
    - Sorts in ascending order with the default comparator.
    - Accepts a comparator for another ordering.
    - Requires random-access iterators, so it works with vector and deque but
      not directly with list. list has its own member sort().
    - Typical complexity is O(N log N).
    - sort is not stable: equivalent elements do not have to retain their
      original order. Use stable_sort when that ordering matters.

    reverse(first, last):
    - Reverses the elements in the range.
    - Linear time and constant auxiliary space for ordinary containers.
*/

void sortingAndReversingExample() {
    cout << "===== Sorting and reversing =====" << endl;

    vector<int> values{40, 10, 50, 20, 30};

    sort(values.begin(), values.end());
    printVector(values, "Ascending:  ");

    sort(values.begin(), values.end(), greater<int>());
    printVector(values, "Descending: ");

    reverse(values.begin(), values.end());
    printVector(values, "Reversed:   ");
}

// =============================================================================
// 3. Searching algorithms
// =============================================================================

/*
    find(first, last, value):
    - Linear search.
    - Does not require sorted data.
    - Returns an iterator to the first matching element, or last if absent.
    - O(N).

    binary_search(first, last, value):
    - Returns true/false.
    - Requires the range to be sorted according to the same ordering.
    - O(log N) with random-access iterators.

    lower_bound(first, last, value):
    - Returns the first position whose value is not less than value:
          first element >= value

    upper_bound(first, last, value):
    - Returns the first position whose value is greater than value:
          first element > value

    lower_bound and upper_bound return last if no matching position exists.
    Always compare the returned iterator with end before dereferencing it.
    For a vector, iterator subtraction gives the index. For a list, use
    distance(), which takes linear time.
*/

void searchingExample() {
    cout << "\n===== Searching and bounds =====" << endl;

    vector<int> values{10, 20, 30, 30, 30, 40, 50};

    bool containsThirty = binary_search(values.begin(), values.end(), 30);
    cout << "Is 30 present? " << (containsThirty ? "Yes" : "No") << endl;

    vector<int>::const_iterator found = find(values.begin(), values.end(), 40);
    if (found != values.end()) {
        cout << "find() located 40 at index " << (found - values.begin())
             << endl;
    }

    vector<int>::const_iterator lower =
        lower_bound(values.begin(), values.end(), 30);
    vector<int>::const_iterator upper =
        upper_bound(values.begin(), values.end(), 30);

    if (lower != values.end()) {
        cout << "lower_bound(30) index: " << (lower - values.begin())
             << " and value: " << *lower << endl;
    }

    if (upper != values.end()) {
        cout << "upper_bound(30) index: " << (upper - values.begin())
             << " and value: " << *upper << endl;
    } else {
        cout << "upper_bound(30) points to end." << endl;
    }

    cout << "Frequency of 30: " << (upper - lower) << endl;

    vector<int>::const_iterator missing =
        lower_bound(values.begin(), values.end(), 35);
    if (missing != values.end()) {
        cout << "First value not less than 35: " << *missing << endl;
    } else {
        cout << "No value is at least 35." << endl;
    }
}

// =============================================================================
// 4. Numeric algorithms
// =============================================================================

/*
    accumulate(first, last, initial):
    - Combines all values into one result.
    - O(N).
    - The type of initial controls the accumulator type. Use 0LL when a long
      long result is needed; using int 0 can overflow before assignment.

    count(first, last, value):
    - Counts equal values in O(N).

    count_if(first, last, predicate):
    - Counts values satisfying a condition.

    inner_product and partial_sum are additional useful numeric algorithms,
    although this chapter focuses on the common sum/count operations.
*/

void numericExample() {
    cout << "\n===== Numeric algorithms =====" << endl;

    vector<int> values{5, 2, 9, 1, 7, 9};

    int sum = accumulate(values.begin(), values.end(), 0);
    long long safeSum =
        accumulate(values.begin(), values.end(), 0LL);
    int nines = count(values.begin(), values.end(), 9);
    int valuesAtLeastFive = count_if(
        values.begin(), values.end(),
        [](int value) { return value >= 5; });

    cout << "Sum: " << sum << endl;
    cout << "Long long sum: " << safeSum << endl;
    cout << "Count of 9: " << nines << endl;
    cout << "Count of values >= 5: " << valuesAtLeastFive << endl;
}

// =============================================================================
// 5. Min/max and range manipulation
// =============================================================================

/*
    min_element and max_element:
    - Return iterators, not values.
    - Dereference only when the range is non-empty.
    - O(N).

    minmax_element returns both iterators in one pass.

    rotate(first, middle, last):
    - Moves the element at middle to first and shifts the preceding elements.
    - Example [1 2 3 4 5], rotate(begin, begin + 2, end)
      becomes [3 4 5 1 2].
    - Linear time.

    unique(first, last):
    - Removes consecutive duplicates logically by moving unique values to the
      front and returns a new logical end.
    - It does not resize the container.
    - Erase the returned suffix for a vector:
          values.erase(newEnd, values.end());
    - To remove all duplicate values, sort first unless the data is already
      grouped by value. unique only compares adjacent elements.
*/

void minMaxAndManipulationExample() {
    cout << "\n===== Min/max and range manipulation =====" << endl;

    vector<int> values{5, 2, 9, 1, 7, 9};

    if (!values.empty()) {
        vector<int>::const_iterator minimum =
            min_element(values.begin(), values.end());
        vector<int>::const_iterator maximum =
            max_element(values.begin(), values.end());

        cout << "Minimum: " << *minimum
             << " at index " << (minimum - values.begin()) << endl;
        cout << "Maximum: " << *maximum
             << " at index " << (maximum - values.begin()) << endl;
    }

    vector<int> rotated{1, 2, 3, 4, 5};
    rotate(rotated.begin(), rotated.begin() + 2, rotated.end());
    printVector(rotated, "Rotated left by 2: ");

    vector<int> duplicates{10, 10, 20, 20, 20, 30, 10};
    sort(duplicates.begin(), duplicates.end());
    vector<int>::iterator newEnd =
        unique(duplicates.begin(), duplicates.end());
    duplicates.erase(newEnd, duplicates.end());
    printVector(duplicates, "Sorted unique values: ");
}

// =============================================================================
// 6. Custom comparators and predicates
// =============================================================================

/*
    Many algorithms accept a callable:
    - greater<int>() sorts descending.
    - A lambda can express a custom condition.
    - A comparator should provide a consistent strict ordering when used by
      sorting algorithms. For two equal items, it should return false in both
      directions.
*/

void customComparatorExample() {
    cout << "\n===== Custom comparator =====" << endl;

    vector<int> values{1, 2, 3, 4, 5, 6};
    sort(values.begin(), values.end(),
         [](int left, int right) {
             // Even values first; values with the same parity ascend.
             if ((left % 2) != (right % 2)) {
                 return left % 2 == 0;
             }
             return left < right;
         });

    printVector(values, "Even first: ");
}

// =============================================================================
// 7. Preconditions, complexity, and practice
// =============================================================================

/*
    Important preconditions:
    - binary_search/lower_bound/upper_bound require a sorted range.
    - sort requires random-access iterators.
    - min_element/max_element return end for an empty range.
    - unique only removes adjacent duplicates and does not resize.
    - Dereferencing end or an iterator from an empty range is invalid.

    Complexity summary:

    Algorithm       Typical time       Extra space    Important condition
    sort            O(N log N)         implementation  random-access range
    reverse         O(N)               O(1)            -
    find            O(N)               O(1)            -
    binary_search   O(log N)           O(1)            sorted random-access range
    lower_bound     O(log N)           O(1)            sorted range
    upper_bound     O(log N)           O(1)            sorted range
    accumulate      O(N)               O(1)            -
    count           O(N)               O(1)            -
    min_element     O(N)               O(1)            non-empty before dereference
    rotate          O(N)               O(1)            -
    unique          O(N)               O(1)            adjacent duplicates

    Practice questions:
    1. What is the [first, last) range convention?
    2. Why must a range be sorted before binary_search?
    3. What is the difference between lower_bound and upper_bound?
    4. Why should lower_bound's result be checked before dereferencing?
    5. Why does initial 0LL matter in accumulate?
    6. Does unique resize a vector?
    7. Why is sort not directly available for list?
    8. What is the difference between find and binary_search?
    9. What does rotate do to a range?
    10. What makes a comparator suitable for sort?

    Homework:
    - Find the first and last occurrence of a value using lower_bound and
      upper_bound.
    - Count even and odd values using count_if.
    - Rotate a vector right by k positions.
    - Sort a vector of pairs by second value, then by first value.
    - Remove duplicates from an unsorted vector and preserve sorted output.
    - Use minmax_element to find both extremes in one algorithm call.
*/

int main() {
    cout << "=================== C++ STL CHAPTER 2: ALGORITHMS ==================="
         << endl;

    sortingAndReversingExample();
    searchingExample();
    numericExample();
    minMaxAndManipulationExample();
    customComparatorExample();

    return 0;
}
