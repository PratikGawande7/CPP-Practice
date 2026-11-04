
// ==================== NUMBER SYSTEMS ====================
// A number system is a way of representing numbers using a set of symbols
// and a base.
//
// The base tells us how many different digits are available in that system.
//
// Decimal number system:
// - Base 10
// - Uses the digits 0 to 9
// - This is the number system people normally use.
// Example: 538
//
// Binary number system:
// - Base 2
// - Uses only the digits 0 and 1
// - Computers use binary to represent and process data.
// Example: 1011 (binary)
//
// Octal number system:
// - Base 8
// - Uses the digits 0 to 7
// Example: 27 (octal)
//
// Hexadecimal number system:
// - Base 16
// - Uses 0 to 9 and A to F
// - A means 10, B means 11, C means 12, D means 13,
//   E means 14, and F means 15.
// Example: 2F (hexadecimal)

// PLACE VALUE IN A NUMBER SYSTEM
// In every number system, the value of a digit depends on its position.
// The positions start from the right side with power 0.
//
// Decimal example:
// 538 = (5 * 10^2) + (3 * 10^1) + (8 * 10^0)
//     = 500 + 30 + 8
//     = 538
//
// Binary example:
// 1011 = (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (1 * 2^0)
//      = 8 + 0 + 2 + 1
//      = 11 in decimal

// CONVERTING DECIMAL TO BINARY
// To convert a decimal number to binary:
// 1. Divide the number by 2.
// 2. Write down the remainder, which is always 0 or 1.
// 3. Divide the quotient by 2 again.
// 4. Continue until the quotient becomes 0.
// 5. Read the remainders from bottom to top.
//
// Example: convert decimal 13 to binary
// 13 / 2 = 6 remainder 1
//  6 / 2 = 3 remainder 0
//  3 / 2 = 1 remainder 1
//  1 / 2 = 0 remainder 1
//
// Reading the remainders from bottom to top:
// 13 in decimal = 1101 in binary

// CONVERTING BINARY TO DECIMAL
// Multiply each binary digit by its power of 2 and add the results.
//
// Example:
// 1101 = (1 * 2^3) + (1 * 2^2) + (0 * 2^1) + (1 * 2^0)
//      = 8 + 4 + 0 + 1
//      = 13 in decimal

// In C++, an integer literal can be written in different number systems:
// int decimalNumber = 13;      // decimal
// int binaryNumber = 0b1101;   // binary
// int octalNumber = 015;       // octal
// int hexadecimalNumber = 0xD; // hexadecimal
//
// The prefix tells C++ which number system is being used:
// 0b or 0B = binary
// 0        = octal
// 0x or 0X = hexadecimal