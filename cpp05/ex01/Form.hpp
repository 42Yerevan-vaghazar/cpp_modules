#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const std::string name,  const short gradeToSign, const short gradeToExecute);
        Form(const Form &obj);
        ~Form();
        Form &operator=(const Form &obj); // TODO implement constructors
        void beSigned(const Bureaucrat &Bureaucrat);
        std::string getName() const;
        bool        isSigned() const;
        short getGradeToSign() const;
        short getGradeToExecute() const;
    private:
        const std::string m_name;
        bool m_isSigned;
        const short m_gradeToSign;
        const short m_gradeToExecute;  // TODO what is this for.
        short isValid(const int grade) const;
    private:
        class GradeError : public std::exception
        {
            public:
                GradeError(const std::string &message);
                virtual ~GradeError() throw();
                virtual const char* what() const throw();
                virtual void setMessage(const std::string &message);
            private:
                std::string m_message;
        };
};


std::ostream &operator<<(std::ostream &out, const Form &obj);