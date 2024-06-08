/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:16 by kali              #+#    #+#             */
/*   Updated: 2024/06/08 14:50:31 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() 
{
    // Create a Data object
    Data myData;
	myData.nbr = 42;
	myData.s = "hello world";

    // Serialize the pointer to myData
    uintptr_t serialized = Serializer::serialize(&myData);

    // Print the serialized value (the address as an unsigned integer)
    std::cout << "Serialized value: " << serialized << std::endl;

    // For demonstration purposes, let's deserialize it back
    Data* deserialized = Serializer::deserialize(serialized);

    // Verify the deserialization
    std::cout << "Deserialized value: " << deserialized->nbr << ", " << deserialized->s << std::endl;

    return 0;
}