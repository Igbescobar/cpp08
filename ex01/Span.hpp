/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:59:21 by igngonza          #+#    #+#             */
/*   Updated: 2026/02/03 11:59:22 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN__HPP
#define SPAN__HPP

#include <stdexcept>
#include <vector>
class Span {
  public:
    Span(unsigned int);
    Span(const Span &);
    Span &operator=(const Span &);
    ~Span();

    void addNumber(const int);
    template <typename InputIt>
    void addNumbers(InputIt begin, InputIt end);

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

  private:
    unsigned int maxSize;
    std::vector<int> numbers;

    Span();
};

template <typename InputIt>
void Span::addNumbers(InputIt begin, InputIt end) {
    if (this->maxSize < (std::distance(begin, end) + this->numbers.size()))
        throw std::runtime_error("Span's capacity exceeded");

    this->numbers.insert(numbers.end(), begin, end);
}
#endif
