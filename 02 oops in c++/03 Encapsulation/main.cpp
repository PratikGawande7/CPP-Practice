/*
    Complete C++ OOPs - Chapter 3
    Topic: Encapsulation and Data Hiding
    Source: Love Babbar - Complete C++ OOPS in 1 Shot
    Timestamp: 01:05:00

    These are detailed learning notes. Encapsulation is about keeping an
    object's state controlled by the class that owns it.
*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// =============================================================================
// 1. What is encapsulation?
// =============================================================================

/*
    Encapsulation means wrapping data members and the member functions that
    operate on them into one unit: a class.

    A useful analogy is a medical capsule. The ingredients are enclosed inside
    one meaningful container. In a class, related state and behaviour are
    enclosed in one meaningful object.

    Encapsulation has two related ideas:

    1. Bundling:
       Data and the functions related to that data live in one class.

    2. Controlled access / data hiding:
       Internal state is kept private, and public member functions decide how
       outside code can read or change it.

    Encapsulation is not achieved merely by writing a class. A class with
    public data members bundles data and functions, but does not hide the data.
    Private data plus a controlled public interface provides stronger
    encapsulation.
*/

// =============================================================================
// 2. Perfectly (fully) encapsulated class
// =============================================================================

/*
    A class is commonly called perfectly or fully encapsulated when all of its
    data members are private. External code cannot use:

        student.age = -25;

    Instead, it must use the public interface. The class can validate input and
    preserve its own invariants.

    Getter: a public function that reads and returns private state.
    Setter: a public function that validates and updates private state.

    A getter or setter is not automatically required for every private member.
    The interface should expose only the operations the design actually needs.
*/

class Student {
private:
    int age;
    float gpa;
    string name;
    string idProofNumber;

public:
    Student(int initialAge, float initialGpa, const string& initialName,
            const string& initialIdProof)
        : age(0),
          gpa(0.0f),
          name(initialName),
          idProofNumber(initialIdProof) {
        // Reuse the same validation rules during construction.
        setAge(initialAge);
        setGPA(initialGpa);
    }

    // -------------------------------------------------------------------------
    // Getters: read access
    // -------------------------------------------------------------------------

    int getAge() const {
        return age;
    }

    float getGPA() const {
        return gpa;
    }

    const string& getName() const {
        return name;
    }

    /*
        The raw ID proof is never returned. This getter exposes only a masked
        representation. It also handles short or empty input safely.
    */
    string getMaskedIDProof() const {
        if (idProofNumber.empty()) {
            return "CONFIDENTIAL: unavailable";
        }

        const size_t visibleDigits = idProofNumber.size() < 4
            ? idProofNumber.size()
            : 4;
        const size_t hiddenDigits = idProofNumber.size() - visibleDigits;

        return "CONFIDENTIAL: " + string(hiddenDigits, '*')
            + idProofNumber.substr(hiddenDigits);
    }

    // -------------------------------------------------------------------------
    // Setters: validated write access
    // -------------------------------------------------------------------------

    bool setAge(int newAge) {
        if (newAge <= 0 || newAge >= 120) {
            cout << "[Error] Invalid age (" << newAge
                 << "). Age must be greater than 0 and less than 120."
                 << endl;
            return false;
        }

        age = newAge;
        cout << "[Success] Age updated to: " << age << endl;
        return true;
    }

    bool setGPA(float newGPA) {
        if (newGPA < 0.0f || newGPA > 10.0f) {
            cout << "[Error] Invalid GPA (" << newGPA
                 << "). GPA must be between 0.0 and 10.0." << endl;
            return false;
        }

        gpa = newGPA;
        cout << "[Success] GPA updated to: " << gpa << endl;
        return true;
    }

    /*
        There is intentionally no setter for idProofNumber. This gives callers
        read-only access to the masked value while preventing arbitrary changes.
    */
};

void studentEncapsulationExample() {
    cout << "===== Perfect encapsulation =====" << endl;

    Student student(20, 8.5f, "Love Babbar", "AADHAAR1234");

    cout << "\nName: " << student.getName() << endl;
    cout << "Age: " << student.getAge() << endl;
    cout << "GPA: " << student.getGPA() << endl;
    cout << "ID proof: " << student.getMaskedIDProof() << endl;

    cout << "\n--- Setter validation ---" << endl;
    student.setAge(-25); // Rejected; the previous age remains unchanged.
    student.setAge(21);  // Accepted.
    student.setGPA(15.0f); // Rejected.
    student.setGPA(9.0f);  // Accepted.

    // student.age = 30; // Compiler error: age is private.
    // student.idProofNumber = "new"; // Compiler error: also private.
}

// =============================================================================
// 3. Read-only and write-only interfaces
// =============================================================================

/*
    Access can be controlled member by member:

    Read-only:
        Provide a getter but no setter. The caller can observe a value but
        cannot modify it through the public interface.

    Write-only:
        Provide a setter but no getter. The caller can submit a value, but
        cannot read the stored value. A password or PIN often follows this
        pattern, although a verification function is usually more useful than
        exposing the secret.

    A class can also provide both, neither, or specialized operations instead
    of conventional getters and setters.
*/

class WriteOnlyPIN {
private:
    string pin;

public:
    explicit WriteOnlyPIN(const string& initialPin) : pin(initialPin) {}

    bool setPIN(const string& newPin) {
        if (newPin.size() != 4) {
            cout << "[Error] PIN must contain exactly four characters." << endl;
            return false;
        }

        pin = newPin;
        cout << "[Success] PIN updated." << endl;
        return true;
    }

    bool verifyPIN(const string& attemptedPin) const {
        return pin == attemptedPin;
    }

    // There is no getPIN(). The secret is not readable through the interface.
};

void accessDirectionExample() {
    cout << "\n===== Read-only and write-only access =====" << endl;

    WriteOnlyPIN pin("1234");
    cout << "Initial PIN verification: "
         << (pin.verifyPIN("1234") ? "successful" : "failed") << endl;
    pin.setPIN("12"); // Rejected.
    pin.setPIN("5678"); // Accepted.
    cout << "Updated PIN verification: "
         << (pin.verifyPIN("5678") ? "successful" : "failed") << endl;
}

// =============================================================================
// 4. BankAccount practice assignment
// =============================================================================

/*
    This example applies encapsulation to a practical class:

    - account number and balance are private.
    - account number has a getter but no public setter.
    - balance can change only through deposit() and withdraw().
    - PIN changes require the old PIN.
    - invalid amounts and withdrawals are rejected.

    Money is kept as double here to match the lecture exercise. Real financial
    software commonly uses integer smallest units (such as paise/cents) or a
    decimal type to avoid floating-point rounding issues.
*/

class BankAccount {
private:
    string accountNumber;
    double balance;
    string pin;

public:
    BankAccount(const string& initialAccountNumber,
                const string& initialPin,
                double initialBalance = 0.0)
        : accountNumber(initialAccountNumber),
          balance(0.0),
          pin(initialPin) {
        if (initialBalance < 0.0) {
            cout << "[Error] Initial balance cannot be negative. "
                    "Starting with zero."
                 << endl;
        } else {
            balance = initialBalance;
        }
    }

    const string& getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    bool deposit(double amount) {
        if (amount <= 0.0) {
            cout << "[Error] Deposit amount must be positive." << endl;
            return false;
        }

        balance += amount;
        cout << "[Success] Deposited $" << fixed << setprecision(2)
             << amount << ". New balance: $" << balance << endl;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0.0) {
            cout << "[Error] Withdrawal amount must be positive." << endl;
            return false;
        }

        if (amount > balance) {
            cout << "[Error] Insufficient balance." << endl;
            return false;
        }

        balance -= amount;
        cout << "[Success] Withdrew $" << fixed << setprecision(2)
             << amount << ". New balance: $" << balance << endl;
        return true;
    }

    bool changePIN(const string& oldPIN, const string& newPIN) {
        if (oldPIN != pin) {
            cout << "[Error] Old PIN is incorrect." << endl;
            return false;
        }

        if (newPIN.size() != 4) {
            cout << "[Error] New PIN must contain exactly four characters."
                 << endl;
            return false;
        }

        pin = newPIN;
        cout << "[Success] PIN changed." << endl;
        return true;
    }

    bool verifyPIN(const string& attemptedPIN) const {
        return pin == attemptedPIN;
    }
};

void bankAccountExample() {
    cout << "\n===== BankAccount encapsulation =====" << endl;

    BankAccount account("AC-101", "1234", 500.0);
    cout << "Account number: " << account.getAccountNumber() << endl;
    cout << "Starting balance: $" << fixed << setprecision(2)
         << account.getBalance() << endl;

    account.deposit(250.0);
    account.withdraw(100.0);
    account.withdraw(1000.0); // Rejected.
    account.deposit(-10.0);   // Rejected.

    account.changePIN("0000", "5678"); // Rejected.
    account.changePIN("1234", "5678"); // Accepted.
    cout << "New PIN verification: "
         << (account.verifyPIN("5678") ? "successful" : "failed") << endl;

    // account.balance = -100000.0; // Compiler error: balance is private.
    // account.pin = "0000";        // Compiler error: pin is private.
}

// =============================================================================
// 5. Encapsulation summary and practice questions
// =============================================================================

/*
    Without encapsulation:
    - State is exposed.
    - Any caller can assign invalid values.
    - Validation rules are scattered or missing.
    - The class cannot protect its invariants.

    With encapsulation:
    - Data members are hidden behind private access.
    - Public methods form a controlled interface.
    - Setters or domain operations validate input.
    - The implementation can change without changing callers.
    - Read-only or write-only access can be designed intentionally.

    Practice questions:
    1. What does encapsulation mean?
    2. What is a fully encapsulated class?
    3. Why is private data safer than public data?
    4. What is the purpose of a getter?
    5. Why should a setter validate input?
    6. How do you make a value read-only through a class interface?
    7. Why is a PIN usually not returned by a getter?
    8. Why should balance change through deposit() and withdraw()?
    9. Which BankAccount members should not have public setters?
    10. What is the difference between bundling and data hiding?

    Homework:
    - Add a transaction history to BankAccount without exposing the internal
      container directly.
    - Add a maximum withdrawal limit and validate it in withdraw().
    - Create a Temperature class that accepts Celsius only in a valid range
      and provides a read-only Fahrenheit conversion.
*/

int main() {
    studentEncapsulationExample();
    accessDirectionExample();
    bankAccountExample();

    return 0;
}
