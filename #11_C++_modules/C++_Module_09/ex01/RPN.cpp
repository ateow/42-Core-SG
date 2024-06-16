/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:07:07 by kali              #+#    #+#             */
/*   Updated: 2024/06/16 14:09:47 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& Org)  : stack(Org.stack) {}

RPN& RPN::operator=(const RPN& Org)
{
     stack = Org.stack;
     return *this;
}

RPN::~RPN() {}

void RPN::compute(std::string expression)
{
    if (expression == "")
    {
        std::cerr << "Error: No Expression Provided" << std::endl;
        return;
    }    // parse spaces and invalid char
    std::stack<int> stack;
    std::stack<char> operators;

    unsigned int i = 0;
    while (i < expression.length())
    {
        if ((expression[i] < '0' || expression[i] > '9') && (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/' && expression[i] != ' ' && expression[i] != '\t'))
        {
            std::cerr << "Error: Invalid Expression" << std::endl;
            return;
        }
        i++;
    }

    i = 0;
    while (i < expression.length())
    {
        while (expression[i] == ' ' || expression[i] == '\t')
            i++;
        if (i == expression.length())
            break;

        if (expression[i] >= '0' && expression[i] <= '9')
        {
            if (i + 1 != expression.length() && (expression[i + 1] >= '0' && expression[i + 1] <= '9'))
            {
                std::cerr << "Error: Number more then 9" << std::endl;
                return;
            }
            stack.push(expression[i] - '0');
        }
        else
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: Invalid Operations" << std::endl;
                return;
            }
            int tmp = stack.top();
            stack.pop();
            if (expression[i] == '+')
                stack.top() = stack.top() + tmp;
            else if (expression[i] == '-')
                stack.top() = stack.top() - tmp;
            else if (expression[i] == '*')
                stack.top() = stack.top() * tmp;
            else if (expression[i] == '/')
                stack.top() = stack.top() / tmp;
        }
        i++;
    }
    if (stack.size() != 1) 
    {
        std::cerr << "Error: Invalid Operations" << std::endl;
        return;
    }
    else
    {
        std::cout << stack.top() << std::endl;
        return;
    }
}