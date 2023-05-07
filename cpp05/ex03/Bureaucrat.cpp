#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("default") {
    std::cout << __func__ << " called" << std::endl;
    m_grade = 50;
};

Bureaucrat::Bureaucrat(const std::string &name, const int grade) :
    m_name(name) {
    std::cout << __func__ << " called" << std::endl;
    if (grade > 150) {
        throw GradeError("GradeTooLowException");
    }
    if (grade < 1) {
        throw GradeError("GradeTooHighException");
    }
    m_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : m_name(obj.m_name) {
    m_grade = obj.m_grade;
};

Bureaucrat::~Bureaucrat() {};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    m_grade = obj.m_grade;
    return  (*this);
};

std::string Bureaucrat::getName() const {
    return (m_name);
};

short Bureaucrat::getGrade() const {
    Bureaucrat::getName();
    return (m_grade);
};

void Bureaucrat::increment() {
    if (m_grade == 1) {
        throw GradeError("GradeTooHighException");
    }
    --m_grade;
};

void Bureaucrat::decrement() {
    if (m_grade == 150) {
        throw GradeError("GradeTooLowException");
    }
    ++m_grade;
};

void Bureaucrat::signForm(AForm &form) {
	try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn’t sign " << form.getName()
            << " because of " << e.what() << std::endl;
    }
};

void Bureaucrat::executeForm(AForm const & form) {
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn’t execute " << form.getName()
           << " because of " << e.what() << std::endl;
    }
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
    std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (out);
};

Bureaucrat::GradeError::GradeError(const std::string &message) {
    m_message = message;
};

Bureaucrat::GradeError::~GradeError() throw() {};

const char* Bureaucrat::GradeError::what() const throw() {
    return (m_message.c_str());
};

void Bureaucrat::GradeError::setMessage(const std::string &message) {
    m_message = message;
}
