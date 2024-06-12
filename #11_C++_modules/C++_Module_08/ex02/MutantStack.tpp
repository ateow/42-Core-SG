/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:24:42 by kali              #+#    #+#             */
/*   Updated: 2024/06/12 12:21:19 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {};

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &Org) : std::stack<T>(Org) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const &Org) 
{
    if (this != &Org) 
        std::stack<T>::operator=(Org);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

// template <typename T>
// typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
// {
// 	return (std::stack<T>::c.begin());
// }

// template <typename T>
// typename MutantStack<T>::const_iterator MutantStack<T>::end() const
// {
// 	return (std::stack<T>::c.end());
// }


// template <typename T>:

//     This indicates that MutantStack is a template class that operates with a generic type T.

// typename MutantStack<T>::iterator:

//     typename: Required to inform the compiler that MutantStack<T>::iterator is a type. This is necessary because MutantStack<T> is a dependent type (dependent on the template parameter T), and the compiler needs explicit clarification.
//     MutantStack<T>::iterator: Refers to the type alias iterator defined within the MutantStack<T> class. This is an alias for typename std::stack<T>::container_type::iterator.

// MutantStack<T>::begin():

//     This is the full qualification of the method name begin() belonging to the class template MutantStack<T>. The MutantStack<T>:: part ensures that the compiler knows this begin method belongs to the MutantStack class template instantiated with T.

// Method Body:

//     return std::stack<T>::c.begin();: This line returns the result of calling begin() on the underlying container c of the std::stack class.