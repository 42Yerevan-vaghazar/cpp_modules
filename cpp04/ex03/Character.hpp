#pragma once
#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character();
        Character(const std::string &name);
        Character(const Character &obj);
        virtual ~Character();
        Character &operator=(const Character &obj);
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
    private:
        int         slotIndex;
        std::string m_name;
        AMateria* m_materias[4];
        AMateria* m_dropedMaterias[10];
        int m_dropedCount;
};
