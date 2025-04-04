#include <bitset>
#include <cmath>
#include <iostream>

bool is_power_of_2(int);
void test1();
void test2();
void test3();

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator){}

    std::string to_string() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    // operator overload
    bool operator==(Fraction &other) {
        return this->numerator == other.numerator &&
            this->denominator == other.denominator;
    }
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction reduce(Fraction input) {
    int divider = gcd(input.numerator, input.denominator);
    input.numerator /= divider;
    input.denominator /= divider;
    return input;
}

int main(){
    // Question one, using loops
    std::cout << "\nFirst question with loops: " << std::endl;
    for (int num = 0; num < 50; ++num) {
        bool result = is_power_of_2(num);
        if (result == true) {
            printf("%d is a power of 2\n", num);
        } else {
            printf("%d is not a power of by 2\n", num);
        }
    }

    // Question one, no loop
    std::cout << "\nChecking is a num is power of 2 using no loops: " << std::endl;
    test1();

    // Question two
    std::cout << "\nTesting the is_prime_num() method: " << std::endl;
    test2();

    // Question three
    std::cout << "\nTesting the reduce fraction method: " << std::endl;
    test3();
    return 0;
}

// loop method
bool is_power_of_2(int num) {
    // keep dividing num by 2 until either 1 or non-divisible
    if (num == 0) {
        return false;
    }
    while (num  != 1) {
        if (num % 2 == 0) { // dividible by 2
            num = num/2;
            continue;
        } else {
            return false;
        }
    }
    return true;
}

bool is_prime_num(int num) {
    if (num <= 1) {
        return false;
    }
    // Used Google to learn how to check if a num is a prime num
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

//binary numbers
//2 : 10
//4 : 100
//8 : 1000
//16 : 10000
// Function verifies if a num is a power of 2 by checking if it has only one '1' bit in binary form
// Used chatgpt to learn about __builtin_popcount()
bool is_power_of_2_binary(int num) {
    int ones_count = __builtin_popcount(num);
    if (ones_count == 1) {
        return true;
    }
    return false;
}

void test1() {
    int inputs[5] = {0, 2, 6, 8, 16};
    bool outputs[5] = {false, true, false, true, true};

    for (int i = 0; i < 5; i++) {
        int input = inputs[i];
        int expect = outputs[i];

        int actual = is_power_of_2_binary(input);
        if (expect == actual) {
            std::cout << "PASS!" <<std::endl;
        } else {
            std::cout << "FAIL! case is: " << input << std::endl;
        }
    }
}

void test2() {
    int inputs[10] = {0, 1, 2, 4, 5, 10, 13, 43, 71, 80};
    bool outputs[10] = {false, false, true, false, true, false, true, true, true, false};

    for (int i = 0; i < 10; i++) {
        int input = inputs[i];
        int expect = outputs[i];

        int actual = is_prime_num(input);
        if (expect == actual) {
            std::cout << "PASS!" <<std::endl;
        } else {
            std::cout << "FAIL! case is: " << input << std::endl;
        }
    }
}

void test3() {//reduce given fraction to minimum terms
    // given an input, the actual output should match the expected output
    Fraction inputs[4] = {Fraction{1,2},
                        Fraction{2,4},
                        Fraction{4,2},
                        Fraction{6,8}
    };

    Fraction outputs[4] = {Fraction{1,2},
                                   Fraction{1,2},
                                   Fraction{2,1},
                                   Fraction{3,4}
    };

    // call the function & compare expected vs actual
    for (int i = 0; i < 4; i++) {
        Fraction input = inputs[i];
        Fraction expect = outputs[i];

        Fraction actual = reduce(input);
        if (expect == actual) {
            std::cout << "PASS!" <<std::endl;
        } else {
            std::cout << "FAIL! case is: " << input.to_string() << std::endl;
        }
    }
}
