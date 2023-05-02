/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
     Fraction a(1, 2), b(3, 4);
    ostringstream os;

    // Test operator<<
    os << a; // Not thrwoing error
    std::cout << os.str(); // Prints well

    istringstream is("5 6"); // Could also be "5,6" for ex

    // Test operator>>
    is >> b;
    std::cout << b;
   
}
