class   Fixed
{
	private:


	public:
		//construct
		Fixed();

		//copy construct
		Fixed(const Fixed& orignal);
		
		//copy operator assign
    	Fixed& operator=(const Fixed& original);
		
		//destructor
		~Fixed();
};

Fixed::Fixed(void)
{
	
}

Fixed::Fixed(const Fixed& orignal)
{

}

Fixed& Fixed::operator=(const Fixed &original)
{
    if (this != &original) 
	{
        // Implement the copy assignment logic here
    }
    return *this;
}


Fixed::~Fixed(){};