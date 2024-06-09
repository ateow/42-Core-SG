/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:36:18 by ateow             #+#    #+#             */
/*   Updated: 2024/06/09 23:34:24 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector> 
# include <algorithm>

class Span
{
    public:
        Span();
        Span(int N);
        Span(const Span& Org);
        Span& operator=(const Span& Org);
        ~Span();

        void addNumber(int N);
        int shortestSpan();
        int longestSpan();
        void print_span();
        void addRange(std::vector<int>::iterator start,std::vector<int>::iterator end);
    
    private:
        std::vector<int> arr;
        std::vector<int>::iterator current_it;
        std::size_t size;
};

#endif