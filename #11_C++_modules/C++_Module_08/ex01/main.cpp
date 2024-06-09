/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/10 00:11:08 by kali             ###   ########.fr       */
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

        Span sp2(sp);
        Span sp3 = sp;

        sp.print_span();
        std::cout << std::endl;
        sp2.print_span();
        std::cout << std::endl;
        sp3.print_span();
        std::cout << std::endl;

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp3.shortestSpan() << std::endl;
        sp3.print_span();
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;
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

    std::cout << "\n===== Span initi with iterators ======" << std::endl;
    try
    {
        std::srand(time(NULL));
        int sizeofarr = 10000;
        std::vector<int> big(sizeofarr);
        for (int i = 0; i < sizeofarr; ++i)
            big[i] = rand() % 100000;
        Span sp = Span(sizeofarr);
        sp.addRange(big.begin(), big.end());
        // sp2.print_span();
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