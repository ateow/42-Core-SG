/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/12 12:00:28 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int main()
{
    // By default, when you instantiate a std::stack, it uses std::deque as the underlying container.
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout  << "top value in stack: " << mstack.top() << std::endl; // 17
    std::cout << "stack size before pop: " << mstack.size() << std::endl; // 2

    mstack.pop();

    std::cout  << "top value in stack: " << mstack.top() << std::endl; // 17
    std::cout << "stack size after pop: " <<  mstack.size() << std::endl; // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(10);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    std::cout << "\nstack values: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    // Copy constructor test
    MutantStack<int> copiedStack(mstack);
    std::cout << "Copied stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = copiedStack.begin(); it != copiedStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Assignment operator test
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Assigned stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Demonstrate usage with a different container type
    MutantStack<int, std::list<int> > listBasedStack;
    listBasedStack.push(42);
    listBasedStack.push(21);
    std::cout << "List-based stack elements:" << std::endl;
    for (MutantStack<int, std::list<int> >::iterator it = listBasedStack.begin(); it != listBasedStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Check if the stack can be reversed
    std::cout << "Reversed stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = --mstack.end(); it != --mstack.begin(); --it) {
        std::cout << *it << std::endl;
        if (it == mstack.begin()) break; // Avoid infinite loop
    }












    return 0;
}