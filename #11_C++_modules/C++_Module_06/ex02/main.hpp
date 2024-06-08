/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:19:53 by kali              #+#    #+#             */
/*   Updated: 2024/06/08 14:52:25 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _MAIN_HPP_
# define _MAIN_HPP_

# include <iostream>
# include <cstdlib>

class Base
{
    public:
        virtual ~Base();
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

#endif