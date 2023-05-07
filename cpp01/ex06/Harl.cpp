#include "Harl.hpp"

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void	(Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    unsigned int i = 0;

    while (i < 4 && levels[i] != level)
        ++i;
    switch (i) {
        case 0:
            (this->*func[i])();
            i++;
        case 1:
            (this->*func[i])();
            i++;
        case 2:
            (this->*func[i])();
            i++;
        case 3:
            debug();
            (this->*func[i])();
            i++;
            break ;
        default:
            std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
            break ;
    }
};

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup\
burger. I really do!" << std::endl;
};

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for\
years whereas you started working here since last month." <<  std::endl;
};

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
};