#pragma once
#include <iostream>


class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &obj);
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        Fixed& operator=(const Fixed &fixed);
        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int m_raw;
    private:
        static const int m_nFractBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);