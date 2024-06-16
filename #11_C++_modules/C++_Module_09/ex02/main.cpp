/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:59:25 by kali              #+#    #+#             */
/*   Updated: 2024/06/16 11:45:52 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc <= 2)
    {
        std::cerr << "Usage: ./PmergeMe <unsorted int>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    // Parse command line arguments
    for (int i = 1; i < argc; ++i) 
    {
        for (unsigned int j = 0; j < std::string(argv[i]).length(); ++j)
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                std::cerr << "Error: Only integers are allowed." << std::endl;
                return 1;
            }
        }
        int value = atoi(argv[i]);
        if (value < 0) 
        {
            std::cerr << "Error: Only positive integers are allowed." << std::endl;
            return 1;
        }
        vec.push_back(value);
        lst.push_back(value);
    }

    // USING LIST
    std::cout << "\n======== LIST ========\n";
    clock_t start = clock();
    std::list<int> sortedList = FJ_Merge_Insertion_Sort_list(lst.begin(), lst.end());
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "Before:   ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "After:    ";
    for (std::list<int>::iterator it = sortedList.begin(); it != sortedList.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Time taken to sort " << lst.size() << " elements with std::list : " << time << " us (microseconds) or " << time / 1000000 << " seconds" << std::endl;


    // USING VECTOR
    std::cout << "\n======== VECTOR ========\n";
    start = clock();
    std::vector<int> sortedVector = FJ_Merge_Insertion_Sort_vector(vec.begin(), vec.end());
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "Before:   ";
    for (std::vector<int>::iterator it2 = vec.begin(); it2 != vec.end(); it2++)
        std::cout << *it2 << " ";
    std::cout << std::endl;
    std::cout << "After:    ";
    for (std::vector<int>::iterator it2 = sortedVector.begin(); it2 != sortedVector.end(); it2++)
        std::cout << *it2 << " ";
    std::cout << std::endl;
    std::cout << "Time taken to sort " << vec.size() << " elements with std::vector : " << time << " us (microseconds) or " << time / 1000000 << " seconds" << std::endl;

}

// Vector (faster): Uses contiguous memory allocation, which can lead to better cache utilization and thus better performance in scenarios where locality of reference matters.
// List (slower): Uses nodes with pointers, which adds overhead per element but allows for efficient insertions and deletions.Use std::vector when:

//     You need efficient random access.
//     You frequently add or remove elements at the end (push_back(), pop_back()).
//     Memory locality is important for performance.

// Use std::list when:

//     You frequently insert or delete elements in the middle or front of the container (insert(), erase()).
//     You need iterators or references to remain valid after insertion or deletion.