/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:34:56 by kali              #+#    #+#             */
/*   Updated: 2024/02/24 15:55:58 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"


//========== A_MATERIA =============//


AMateria::AMateria() : type("Default")
{
	std::cout << "Default Constructor: AMateria Class" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "Initialising " << type << std::endl;
}

AMateria::AMateria(const AMateria& original)
{
  	std::cout << "Initialising AMateria copy " << original.type << std::endl;
	*this = original;
}

AMateria& AMateria::operator=(const AMateria &original)
{
	if (this != &original) 
	{
        this->type = original.type;
	    std::cout << "AMateria " << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Class: "<< "Goodbye " << this->type << std::endl;
}

std::string const & AMateria::getType() const
{
    return(this->type);
}

void AMateria::use(ICharacter& target)
{
    if (this->type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if (this->type == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


//========== ICE =============//

Ice::Ice()
{
    this->type = "ice";
	std::cout << "Default Constructor: Ice Class" << std::endl;
}

Ice::Ice(const Ice& original) : AMateria()
{
  	std::cout << "Initialising Ice copy " << original.type << std::endl;
	*this = original;
}

Ice& Ice::operator=(const Ice &original)
{
	if (this != &original) 
	{
        this->type = original.type;
	    std::cout << "Ice " << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice Class: " << "Goodbye " << this->type << std::endl;
}

AMateria* Ice::clone() const
{  
    return (new Ice(*this));
}


//========== CURE =============//

Cure::Cure()
{
    this->type = "cure";
	std::cout << "Default Constructor: Cure Class" << std::endl;
}

Cure::Cure(const Cure& original) : AMateria()
{
  	std::cout << "Initialising Cure copy " << original.type << std::endl;
	*this = original;
}

Cure& Cure::operator=(const Cure &original)
{
	if (this != &original) 
	{
        this->type = original.type;
	    std::cout << "Cure " << this->type << " = " << original.type << std::endl;
    }
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure Class: " << "Goodbye " << this->type << std::endl;
}

AMateria* Cure::clone() const
{  
    return (new Cure(*this));
}


//========== CHARACTER =============//

Character::Character() : name("Default")
{
	std::cout << "Default Constructor: Character Class" << std::endl;
    this->materia[0] = NULL;
    this->materia[1] = NULL;
    this->materia[2] = NULL;
    this->materia[3] = NULL;
}

Character::Character(std::string name) : name(name)
{
	std::cout << "Initialising " << name << std::endl;
    this->materia[0] = NULL;
    this->materia[1] = NULL;
    this->materia[2] = NULL;
    this->materia[3] = NULL;
}

Character::Character(const Character& original)
{
  	std::cout << "Initialising copy " << original.name << std::endl;
	this->name = original.name;
    int i = 0;
    while (i < 4) 
    {
        if (original.materia[i] != NULL)
            this->materia[i] = original.materia[i]->clone();
        else
            this->materia[i] = NULL;
        i++;
    }
}

Character& Character::operator=(const Character &original)
{
	if (this != &original)
	{
        this->name = original.name;
        int i = 0;
        while (i < 4)
        {
            delete this->materia[i];
            if (original.materia[i] != NULL)
                this->materia[i] = original.materia[i]->clone();
            else
                this->materia[i] = NULL;
            i++;
        }
     
        std::cout << this->name << " = " << original.name << std::endl;
    }
	return *this;
}

Character::~Character()
{
    int i = 0;
    while (i < 4) 
    {
        delete this->materia[i];
        i++;
    }
	std::cout << "Character Class: Goodbye " << this->name << std::endl;
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    int i = 0;

    while (i < 4)
    {
        if (this->materia[i] == NULL)
        {
            this->materia[i] = m;
            break;
        }
        i++;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
        this->materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (this->materia[idx] != NULL)
    {
        this->materia[idx]->use(target);
    }
}

//========== MATERIA SOURCE =============//


MateriaSource::MateriaSource()
{
	std::cout << "Default Constructor: MateriaSource Class" << std::endl;
    this->materia[0] = NULL;
    this->materia[1] = NULL;
    this->materia[2] = NULL;
    this->materia[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& original)
{
  	std::cout << "Initialising copy " << std::endl;
	*this = original;
    int i = 0;
    while (i < 4) 
    {
        if (original.materia[i] != NULL)
            this->materia[i] = original.materia[i]->clone();
        else
            this->materia[i] = NULL;
        i++;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &original)
{
	if (this != &original)
	{    
        int i = 0;
        while (i < 4) 
        {
            delete this->materia[i];
            if (original.materia[i] != NULL)
                this->materia[i] = original.materia[i]->clone();
            else
                this->materia[i] = NULL;
            i++;
        }
    }
	return *this;
}

MateriaSource::~MateriaSource()
{
    int i = 0;
    while (i < 4) 
    {
        delete this->materia[i];
        i++;
    }
	std::cout << "MateriaSource Class: Goodbye " << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;

    while (i < 4)
    {
        if (this->materia[i] == NULL)
        {
            this->materia[i] = m;
            return;
        }
        i++;
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (type == "ice")
        return (new Ice());
    else if (type == "cure")
        return (new Cure());
    else
        return (0);   
}