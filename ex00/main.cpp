/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:14:05 by igngonza          #+#    #+#             */
/*   Updated: 2026/02/03 11:15:45 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    try {
        std::list<int>::iterator it = easyfind(lst, 4);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    return 0;
}
