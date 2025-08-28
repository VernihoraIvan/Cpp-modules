/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:35:00 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/08/28 14:47:26 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void testCase(const std::string &input)
{
    std::cout << "=== Testing: \"" << input << "\" ===" << std::endl;
    ScalarConverter::convert(input);
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "Running comprehensive ScalarConverter test suite...\n" << std::endl;
    
    // CHAR TESTS
    std::cout << "========== CHAR TESTS ==========" << std::endl;
    testCase("a");
    testCase("U");
    testCase("0");
    testCase("!");
    
    // INT TESTS  
    std::cout << "========== INT TESTS ==========" << std::endl;
    testCase("42");
    testCase("-42");
    testCase("0");
    testCase("2147483647");   // INT_MAX
    testCase("-2147483648");  // INT_MIN
    
    // FLOAT TESTS
    std::cout << "========== FLOAT TESTS ==========" << std::endl;
    testCase("42.0f");
    testCase("-42.5f");
    testCase("0.0f");
    testCase("3.14159f");
    
    // DOUBLE TESTS
    std::cout << "========== DOUBLE TESTS ==========" << std::endl;
    testCase("42.0");
    testCase("-42.5");
    testCase("0.0");
    testCase("3.1411");
    
    // PSEUDO-LITERAL TESTS
    std::cout << "========== PSEUDO-LITERAL TESTS ==========" << std::endl;
    testCase("nan");
    testCase("nanf");
    testCase("+inf");
    testCase("-inf");
    testCase("+inff");
    testCase("-inff");
    
    // OVERFLOW TESTS
    std::cout << "========== OVERFLOW TESTS ==========" << std::endl;
    testCase("3000000000");        // > INT_MAX
    testCase("-3000000000");       // < INT_MIN
    testCase("3000000000.0f");     // Float > INT_MAX
    testCase("3000000000.0");      // Double > INT_MAX
    testCase("-2147483649.0f");    // Float < INT_MIN
    
    // EDGE CASES
    std::cout << "========== EDGE CASES ==========" << std::endl;
    testCase("123abc");       // Invalid
    testCase("");             // Empty
    testCase("42.5.6");       // Multiple dots
    testCase("++42");         // Double sign
    testCase("42ff");         // Double f
    
    std::cout << "Test suite completed!" << std::endl;
    return 0;
}
