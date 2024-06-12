/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/12 12:24:34 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

// int main()
// {
//     // By default, when you instantiate a std::stack, it uses std::deque as the underlying container.
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);

//     std::cout  << "top value in stack: " << mstack.top() << std::endl; // 17
//     std::cout << "stack size before pop: " << mstack.size() << std::endl; // 2

//     mstack.pop();

//     std::cout  << "top value in stack: " << mstack.top() << std::endl; // 17
//     std::cout << "stack size after pop: " <<  mstack.size() << std::endl; // 1

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(10);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
    
//     ++it;
//     --it;
//     std::cout << "\nstack values: " << std::endl;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     return 9
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
// }



// int main()
// {
// 	std::list<int>	mstack;
	
// 	mstack.push_back(5);
// 	mstack.push_back(17);

// 	std::cout << mstack.back() << std::endl;

// 	mstack.pop_back();
	
// 	std::cout << mstack.size() << std::endl;
	
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
	
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
	
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::list<int> s(mstack);
// 	std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
// 	while (!mstack.empty())
// 	{
// 		mstack.pop_back();
// 	}
// 	std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
// 	return 0;
// }


int main()
{
	std::deque<int>	mstack;
	
	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	
	std::deque<int>::iterator it = mstack.begin();
	std::deque<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::deque<int> s(mstack);
	std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
	while (!mstack.empty())
	{
		mstack.pop_back();
	}
	std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
	return 0;
}
