/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:24:46 by kali              #+#    #+#             */
/*   Updated: 2024/06/12 15:31:36 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque> 
# include <list> 


template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        MutantStack();
        MutantStack(MutantStack const &Org);
        MutantStack& operator=(MutantStack const &Org);
        ~MutantStack();

		// Member functions
		typedef typename std::stack<T>::container_type::const_iterator iterator;
		iterator begin() const;
		iterator end() const;
};

#endif

#include "MutantStack.tpp"

// stack has member of c which is container (in this case deque)
// deque has member function of begin and end. 
// deque has member of iterator and const_iterator
// https://en.cppreference.com/w/cpp/container/stack
// https://en.cppreference.com/w/cpp/container/deque
