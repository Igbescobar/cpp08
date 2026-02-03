/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:14:10 by igngonza          #+#    #+#             */
/*   Updated: 2026/02/03 11:14:11 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>
template <typename T>
typename T::iterator easyfind(T &vec, int i) {
    typename T::iterator it = std::find(vec.begin(), vec.end(), i);
    if (it == vec.end())
        throw std::runtime_error("Value not found");
    return it;
}
