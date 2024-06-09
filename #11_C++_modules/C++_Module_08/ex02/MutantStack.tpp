/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:24:42 by kali              #+#    #+#             */
/*   Updated: 2024/06/10 01:15:05 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {};


// template <typename T>
// MutantStack<T>::MutantStack(MutantStack const &Org) : std::stack<T>(Org) {}

// template <typename T>
// MutantStack<T>& MutantStack<T>::operator=(MutantStack const &Org) 
// {
//     if (this != &Org) {
//         std::stack<T>::operator=(Org);
//     }
//     return *this;
// }


// template <typename T>
// MutantStack<T>::~MutantStack() {};
