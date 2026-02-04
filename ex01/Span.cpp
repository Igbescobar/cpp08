/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:59:25 by igngonza          #+#    #+#             */
/*   Updated: 2026/02/04 18:48:44 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : maxSize(N) {
}

Span::Span(const Span &other) : maxSize(other.maxSize), numbers(other.numbers) {
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize)
        throw std::runtime_error("Span capacity exceeded");
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> copy(numbers);
    std::sort(copy.begin(), copy.end());

    unsigned int minSpan = copy[1] - copy[0];
    for (std::vector<int>::iterator it = copy.begin(); it != copy.end() - 1;
         ++it) {
        unsigned int span = *(it + 1) - *it;
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    int minVal = *std::min_element(numbers.begin(), numbers.end());
    int maxVal = *std::max_element(numbers.begin(), numbers.end());

    return static_cast<unsigned int>(maxVal) -
           static_cast<unsigned int>(minVal);
}

std::vector<int> Span::getNumber() const {
    return this->numbers;
}
