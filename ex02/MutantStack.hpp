/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:58:50 by igngonza          #+#    #+#             */
/*   Updated: 2026/02/03 13:04:56 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK__HPP
#define MUTANT_STACK__HPP

#include <stack>
template <typename T>
class MutantStack : public std::stack<T> {
  public:
    MutantStack() : std::stack<T>() {
    }
    MutantStack(const MutantStack &other) : std::stack<T>(other) {
    }
    MutantStack &operator=(const MutantStack &other) {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }
};
#endif
