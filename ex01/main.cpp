/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:59:12 by igngonza          #+#    #+#             */
/*   Updated: 2026/02/03 12:10:51 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    try {
        std::cout << "Small Span" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        try {
            sp.addNumber(42);
        } catch (std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "\nTesting large Span with 10000 numbers" << std::endl;
        const unsigned int SIZE = 10000;
        Span largeSpan(SIZE);

        for (unsigned int i = 0; i < SIZE; ++i) {
            largeSpan.addNumber(rand() % 100000000000);
        }

        std::cout << "Shortest span in largeSpan: " << largeSpan.shortestSpan()
                  << std::endl;
        std::cout << "Longest span in largeSpan: " << largeSpan.longestSpan()
                  << std::endl;

        std::cout << "\nTesting addNumbers() with range" << std::endl;
        std::vector<int> numbers;
        for (int i = 0; i < 5000; ++i) {
            numbers.push_back(i * 2);
        }

        Span spRange(5000);
        spRange.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Shortest span in spRange: " << spRange.shortestSpan()
                  << std::endl;
        std::cout << "Longest span in spRange: " << spRange.longestSpan()
                  << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
