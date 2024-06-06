/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:38:30 by kali              #+#    #+#             */
/*   Updated: 2024/06/07 00:54:50 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
    public:
        // constructor
        Array();
        Array(unsigned int n);
        // Copy constructor
        Array(const Array &Org);
        // copy operator assign
        Array& operator=(Array& Org);
        // destructor
        ~Array();
        // methods
        unsigned int size();
        T& operator[](unsigned int index);

    private:
        T* arr;
        unsigned int arr_size;
};

# include "Array.tpp"

#endif