#pragma once

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &obj);
        ~Fixed();
        Fixed& operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int m_raw;
    private:
        static const int m_nFractBits;
};