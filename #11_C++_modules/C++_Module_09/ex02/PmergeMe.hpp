/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:39:11 by kali              #+#    #+#             */
/*   Updated: 2024/06/17 14:58:39 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <ctime>
#include <cstdlib>

template <typename Iterator>
Iterator prev(Iterator it)
{
    --it;
    return it;
}

template <typename Iterator>
void recursive_insertion_sort(Iterator start, Iterator end)
{
    if (start == end) // Base case: if the range is empty, return
        return;

    // Get the iterator to the element just before end
    Iterator last = end;
    --last;

    // Recursively sort the sub-array up to the second last element
    recursive_insertion_sort(start, last);

    // Insert the last element into the sorted sub-array
    int value = *last;
    Iterator j = last;

    // Move elements of the sorted segment that are greater than key one position to the right
    while (j != start && *prev(j) > value)
    {
        *j = *prev(j);
        --j;
    }

    // Insert the value into the correct position
    *j = value;
}

template <typename Iterator, typename container>
void get_chain_pend(Iterator start, Iterator end, container &chain, container &pend) 
{
    int distance = std::distance(start, end);
    while (distance >= 2 && start != end) // if pair left
    {
        distance = std::distance(start, end);        
        Iterator v1 = start; // first of pair
        Iterator v2 = start; // second of pair
        std::advance(v2, 1);
        if (v2 == end) // for odd
        {
            chain.push_back(*v1);
            break;
        }
        if (*v1 > *v2) // pushing larger element of pair to chain. smaller to pend
        {
            pend.push_back(*v2);
            chain.push_back(*v1);
        }
        else
        {
            pend.push_back(*v1);
            chain.push_back(*v2);
        }
        start++;
        start++;
    }
}

template <typename container>
void merge_chain_pend(container &chain, container &pend) 
{   
    typename container::iterator it;
    typename container::iterator v1;
    typename container::iterator v2;
    typename container::iterator insertPoint;

    while (!pend.empty())    
    {

        it = pend.begin();
        insertPoint = chain.begin();
        insertPoint = std::lower_bound(chain.begin(), chain.end(), *it);

        chain.insert(insertPoint, *it); // insert current element

        v1 = pend.begin(); 
        v2 = pend.begin();
        std::advance(v2, 1); // find next element
        insertPoint = chain.begin();

        while (v2 != pend.end() && *v2 > *v1) // if next pend is bigger, dont have to compare from start
        {   
            insertPoint = std::lower_bound(insertPoint, chain.end(), *v2);
            chain.insert(insertPoint, *v2);
            pend.erase(v1); // Erase and move to the next element in pend
            v1 = pend.begin();
            v2 = pend.begin();
            std::advance(v2, 1);
        }
        pend.erase(pend.begin()); // Erase the current element from pend
    }
}

template <typename Iterator>
std::list<int> FJ_Merge_Insertion_Sort_list(Iterator start, Iterator end)
{
    std::list<int> chain;
    std::list<int> pend;
    get_chain_pend(start, end, chain, pend); // Pair them up and pass the larger element of each pair into chain and smaller element into pend.
    recursive_insertion_sort(chain.begin(), chain.end()); // Recursively sort the chain elements, creating a sorted sequence S of the input elements, in ascending order.

    //Insert the remaining elements into S, one at a time, with a specially chosen insertion ordering described below.
    //Use binary search in subsequences of S to determine the position at which each element should be inserted.
    merge_chain_pend(chain, pend);

    return chain;
}

template <typename Iterator>
std::vector<int> FJ_Merge_Insertion_Sort_vector(Iterator start, Iterator end)
{
    std::vector<int> chain;
    std::vector<int> pend;
    get_chain_pend(start, end, chain, pend); // Pair them up and pass the larger element of each pair into chain and smaller element into pend.
    recursive_insertion_sort(chain.begin(), chain.end()); // Recursively sort the chain elements, creating a sorted sequence S of the input elements, in ascending order.
    
    //Insert the remaining elements into S, one at a time, with a specially chosen insertion ordering described below.
    //Use binary search in subsequences of S to determine the position at which each element should be inserted.
    merge_chain_pend(chain, pend);

    return chain;
}

#endif