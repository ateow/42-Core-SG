/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:24:46 by kali              #+#    #+#             */
/*   Updated: 2024/06/10 01:14:43 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        MutantStack();
        // MutantStack(MutantStack const &Org);
        // MutantStack& operator=(MutantStack const &Org);
        // ~MutantStack();

};

#endif

#include "MutantStack.tpp"
