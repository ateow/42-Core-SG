/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:31:04 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 15:59:51 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	ICharacter;

//========== Materia =============//

class   AMateria
{
    protected:
        std::string type;

	public:
		//construct
		AMateria();
		AMateria(std::string const & type);

		//copy construct
		AMateria(const AMateria& original);
		
		// //copy operator assign
    	AMateria& operator=(const AMateria& original);
		
		//destructor
		virtual ~AMateria();

		//member functions:
        std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

class   Ice : public AMateria
{
	private:
		
	public:
		//construct
		Ice();

		//copy construct
		Ice(const Ice& original);
		
		// //copy operator assign
    	Ice& operator=(const Ice& original);
		
		//destructor
		~Ice();

		//member functions:
		AMateria* clone() const;
};

class   Cure : public AMateria
{
	private:
		
	public:
		//construct
		Cure();

		//copy construct
		Cure(const Cure& original);
		
		// //copy operator assign
    	Cure& operator=(const Cure& original);
		
		//destructor
		~Cure();

		//member functions:
		AMateria* clone() const;
};


//========== Char =============//

class	ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *materia[4];

	public:
		//construct
		Character();
		Character(std::string name);

		//copy construct
		Character(const Character& original);
		
		// //copy operator assign
    	Character& operator=(const Character& original);
		
		//destructor
		~Character();

		//member functions:
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};


//========== MATERIA SOURCE =============//

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materia[4];

    public:
		//construct
        MateriaSource();
		
		//copy construct
		MateriaSource(const MateriaSource& original);
		
		// //copy operator assign
    	MateriaSource& operator=(const MateriaSource& original);

		//destructor
        virtual ~MateriaSource();
        
		//member
		virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
};