/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:09:09 by kali              #+#    #+#             */
/*   Updated: 2024/06/07 00:55:53 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array()
{
    std::cout << "default constructor called" << std::endl;
    arr_size = 0;
    arr = new T[0];
};

template <typename T>
Array<T>::Array(unsigned int n)
{
    std::cout << "constructor called" << std::endl;
    arr_size = n;
    arr = new T[n];
    unsigned int i = 0;
    while (i < arr_size)
    {
        arr[i] = i;
        i++;
    }
};

template <typename T>
Array<T>::Array(const Array &Org)
{
    arr_size = Org.arr_size;
    arr = new T[Org.arr_size];
    unsigned int i = 0;
    while (i < arr_size)
    {
        arr[i] = 0;
        i++;
    }
};

template <typename T>
Array<T>& Array<T>::operator=(Array& Org)
{
    arr_size = Org.arr_size;
    arr = new T[Org.arr_size];
    unsigned int i = 0;
    while (i < arr_size)
    {
        arr[i] = 0;
        i++;
    }
    return *this;
};

template <typename T>
Array<T>::~Array()
{
    delete [] arr;
};

template <typename T>
unsigned int Array<T>::size()
{
    return (arr_size);
};

template <typename T>
T& Array<T>::operator[](unsigned int index) 
{
    if (index >= arr_size) 
	{
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}