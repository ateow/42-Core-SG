/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/09 18:55:47 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int main()
{
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "\n===== Span overflow ======" << std::endl;
    try
    {
        Span sp = Span(2);
        sp.addNumber(-6);
        sp.addNumber(-3);
        sp.addNumber(-17);
        sp.addNumber(-9);
        sp.addNumber(-11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << msg << '\n';
    }

    std::cout << "\n===== Span Valid ======" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(-6);
        sp.addNumber(-3);
        sp.addNumber(-17);
        sp.addNumber(-9);
        sp.addNumber(-11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << msg << '\n';
    }

    std::cout << "\n===== Span too small ======" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(-6);
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << msg << '\n';
    }
    
    std::cout << "\n-----------------------------------------" << std::endl;
    return 0;
}