/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/12 15:55:06 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int main()
{
    // By default, when you instantiate a std::stack, it uses std::deque as the underlying container.
	std::cout  << "======== mutant stack int ========" << std::endl;
	MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17); // btt 5, 17 top

    std::cout  << "top value in stack: " << mstack.top() << std::endl; // 17
    std::cout << "stack size before pop: " << mstack.size() << std::endl; // 2

    mstack.pop();

    std::cout  << "top value in stack: " << mstack.top() << std::endl; // 5
    std::cout << "stack size after pop: " <<  mstack.size() << std::endl; // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0); // btt 5, 3, 5, 737, 0 top

    MutantStack<int>::iterator it = mstack.begin(); // btt
    MutantStack<int>::iterator ite = mstack.end(); // top
    
    ++it;
    --it;
    std::cout << "\nstack values btt to top: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // By default, when you instantiate a std::stack, it uses std::deque as the underlying container.

	std::cout  << "======== mutant stack string ========" << std::endl;
	MutantStack<std::string> mstacks;

    mstacks.push("5_s");
    mstacks.push("17_s"); // btt 5, 17 top

    std::cout  << "top value in stack: " << mstacks.top() << std::endl; // 17
    std::cout << "stack size before pop: " << mstacks.size() << std::endl; // 2

    mstacks.pop();

    std::cout  << "top value in stack: " << mstacks.top() << std::endl; // 5
    std::cout << "stack size after pop: " <<  mstacks.size() << std::endl; // 1

    mstacks.push("3_s");
    mstacks.push("5_s");
    mstacks.push("737_s");
    mstacks.push("0_s"); // btt 5, 3, 5, 737, 0 top

    MutantStack<std::string>::iterator s_it = mstacks.begin(); // btt
    MutantStack<std::string>::iterator s_ite = mstacks.end(); // top
    
    ++s_it;
    --s_it;
    std::cout << "\nstack values btt to top: " << std::endl;
    while (s_it != s_ite)
    {
        std::cout << *s_it << std::endl;
        ++s_it;
    }

	std::cout  << "======== std::list ========" << std::endl;
	std::list<int>	mstack2;
	
	mstack2.push_back(17);
	mstack2.push_back(5); // front 17, 5 back

    std::cout  << "top value in stack: " << mstack2.front() << std::endl; // 17
    std::cout << "stack size before pop: " << mstack2.size() << std::endl; // 2

	mstack2.pop_front();

    std::cout  << "top value in stack: " << mstack2.front() << std::endl; // 5
    std::cout << "stack size after pop: " <<  mstack2.size() << std::endl; // 1

	mstack2.push_back(3);
	mstack2.push_back(5);
	mstack2.push_back(737);
	mstack2.push_back(0); // front 5, 3, 5, 737, 0 back
	
	std::list<int>::iterator it2 = mstack2.begin(); // front
	std::list<int>::iterator ite2 = mstack2.end(); // back
	
	++it2;
	--it2;
    std::cout << "\nstack values front to back: " << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}


	std::cout  << "======== other tests ========" << std::endl;

	MutantStack<int> copiedStack(mstack);
	MutantStack<int>::iterator it3 = copiedStack.begin(); // btt
    MutantStack<int>::iterator ite3 = copiedStack.end(); // top
    
    ++it3;
    --it3;
    std::cout << "\nCopy Constructor stack values btt to top: " << std::endl;
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }

	MutantStack<int> equalStack = copiedStack;
	MutantStack<int>::iterator it4 = equalStack.begin(); // btt
    MutantStack<int>::iterator ite4 = equalStack.end(); // top
    
    ++it4;
    --it4;
    std::cout << "\nOperator Assignment stack values btt to top: " << std::endl;
    while (it4 != ite4)
    {
        std::cout << *it4 << std::endl;
        ++it4;
    }
    return 0;
}




//     // std::stack<int> s(mstack);
    
//     // // Copy constructor test
//     // MutantStack<int> copiedStack(mstack);
//     // std::cout << "Copied stack elements:" << std::endl;
//     // for (MutantStack<int>::iterator it = copiedStack.begin(); it != copiedStack.end(); ++it) {
//     //     std::cout << *it << std::endl;
//     // }

//     // // Assignment operator test
//     // MutantStack<int> assignedStack;
//     // assignedStack = mstack;
//     // std::cout << "Assigned stack elements:" << std::endl;
//     // for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
//     //     std::cout << *it << std::endl;
//     // }

//     // // Demonstrate usage with a different container type
//     // MutantStack<int, std::list<int> > listBasedStack;
//     // listBasedStack.push(42);
//     // listBasedStack.push(21);
//     // std::cout << "List-based stack elements:" << std::endl;
//     // for (MutantStack<int, std::list<int> >::iterator it = listBasedStack.begin(); it != listBasedStack.end(); ++it) {
//     //     std::cout << *it << std::endl;
//     // }

//     // // Check if the stack can be reversed
//     // std::cout << "Reversed stack elements:" << std::endl;
//     // for (MutantStack<int>::iterator it = --mstack.end(); it != --mstack.begin(); --it) {
//     //     std::cout << *it << std::endl;
//     //     if (it == mstack.begin()) break; // Avoid infinite loop