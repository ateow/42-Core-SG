/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:36:18 by ateow             #+#    #+#             */
/*   Updated: 2024/06/09 17:54:24 by ateow            ###   ########.fr       */
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
    
    private:
        std::vector<int> arr;
        std::vector<int>::iterator current_it;
        std::size_t size;
};

#endif