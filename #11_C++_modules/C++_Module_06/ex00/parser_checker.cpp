# include "ScalarConverter.hpp"

bool isValidFloatLiteral(const std::string& str) 
{
    if (str.empty())
        return false;
    size_t i = 0;
    bool hasDecimal = false;
    if (str[i] == '-' || str[i] == '+')
        i++; // Skip optional sign
    while (i < str.size() - 1) 
    {
        if (str[i] == '.') 
        {
            if (hasDecimal) 
                return false;
            hasDecimal = true;
        } 
        else if (!isdigit(str[i])) 
            return false;
        i++;
    }
    if (str[i] != 'f')
        return false;
    return true;
}

bool isValidDoubleLiteral(const std::string& str) 
{
    if (str.empty())
        return false;
    size_t i = 0;
    bool hasDecimal = false;
    if (str[i] == '-' || str[i] == '+')
        i++; // Skip optional sign
    while (i < str.size()) 
    {
        if (str[i] == '.') 
        {
            if (hasDecimal) 
                return false;
            hasDecimal = true;
        } 
        else if (!isdigit(str[i])) 
            return false;
        i++;
    }
    return true;
}

bool isValidIntLiteral(const std::string& str) 
{
    if (str.empty())
        return false;
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++; // Skip optional sign
    while (i < str.size()) 
    {
        if (!isdigit(str[i])) 
            return false;
        i++;
    }
    return true;
}
