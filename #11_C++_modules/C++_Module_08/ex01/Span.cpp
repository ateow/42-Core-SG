/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:10:47 by ateow             #+#    #+#             */
/*   Updated: 2024/06/09 18:48:27 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): arr(0) 
{
    size = 0;
    current_it = arr.begin();
}

Span::Span(int N) : arr(N) 
{
    size = 0;
    current_it = arr.begin();
}

Span::Span(const Span& Org) : arr(Org.arr), current_it(Org.current_it), size(Org.size) {}

Span& Span::operator=(const Span& Org) 
{
    if (this != &Org) 
    {
        arr = Org.arr;
        current_it = Org.current_it;
        size = Org.size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int N)
{
    if (current_it == arr.end())
        throw ( "Unable to add number. Span is full." );
    else
    {
        *current_it = N;
        current_it++;
        size++;
    }
}

int Span::shortestSpan()
{
    if (arr.size() < 2 || size < 2)
        throw ( "Span too small." );

    std::vector<int> sorted(size);
    unsigned int j = 0;
    while (j < size)
    {
        sorted[j] = arr[j];
        // std::cout << sorted[j] << std::endl;
        j++;
    }

    std::sort(sorted.begin(),sorted.end());
    int result = *std::max_element(arr.begin(), current_it);
    for(std::vector<int>::iterator i = sorted.begin() + 1; i < sorted.end(); i++)
		result = std::min(abs(result), abs(*i - *(i - 1)));
    return (result);
}

int Span::longestSpan()
{   
    if (arr.size() < 2 || size < 2)
        throw ( "Span too small." );
    int max = *std::max_element(arr.begin(), current_it);
    int min = *std::min_element(arr.begin(), current_it);
    return (abs(max - min));
}

void Span::print_span()
{
    unsigned int i = 0;
    while (i < arr.size())
    {
        std::cout << arr[i] << std::endl;
        i++;
    }
}
