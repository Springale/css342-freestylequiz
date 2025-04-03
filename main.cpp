#include <bitset>
#include <iostream>

bool is_power_of_2(int);

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

Fraction reduce(Fraction input) {
    return {-1, -1}; // TODO: replace this with the real code
}

int main(){
    /*for (int num = 0; num < 50; ++num) {
        bool result = is_power_of_2(num);
        if (result == true) {
            printf("%d is a power of 2\n", num);
        } else {
            printf("%d is not a power of by 2\n", num);
        }
    }
    return 0;
    */

    test();
}


void test() {//reduce given fraction to minimum terms
    // given an input, the actual output should match the expected output
    Fraction inputs[4] = {Fraction{1,2},
                        Fraction{2,4},
                        Fraction{4,2},
                        Fraction{6,8}
    };

    Fraction outputs[4] = {Fraction{1,2},
                                   Fraction{1,2},
                                   Fraction{2,3},
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

// loop method
/*bool is_power_of_2(int num) {
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

//binary numbers
//2 : 10
//4 : n
//8 : 1000
//16 : 10000
bool is_power_of_2_binary(int num) {
    int binary_num = std::bitset<8>(num);
}*/