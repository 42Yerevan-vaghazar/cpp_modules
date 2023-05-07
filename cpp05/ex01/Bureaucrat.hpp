#pragma once
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, const int grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &obj);
        std::string getName() const;
        short getGrade() const;
        void increment();
        void decrement();
        void signForm(Form &form);
    private:
        const   std::string m_name;
        short   m_grade;
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);