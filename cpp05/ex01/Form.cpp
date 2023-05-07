#include "Form.hpp"

Form::Form() : m_name("default"), m_gradeToSign(isValid(50)), m_gradeToExecute(isValid(70)) {
	m_isSigned = false;
};

Form::Form(const std::string name,  const short gradeToSign, const short gradeToExecute) :
	m_name(name), m_gradeToSign(isValid(gradeToSign)), m_gradeToExecute(isValid(gradeToExecute)) {
		m_isSigned = false;
};

Form::Form(const Form &obj) :
	m_name(obj.m_name), m_gradeToSign(isValid(obj.m_gradeToSign)), m_gradeToExecute(isValid(obj.m_gradeToExecute)) {
	m_isSigned = obj.m_isSigned;
};

Form::~Form() {};

Form &Form::operator=(const Form &obj) {
	if (this != &obj) {
		m_isSigned = obj.m_isSigned;
	}
	return (*this);
};

void Form::beSigned(const Bureaucrat &Bureaucrat) {
	if (m_isSigned == true) {
        throw GradeError("GradeAlreadySigned");
	} if (Bureaucrat.getGrade() <= m_gradeToSign) {
		m_isSigned = true;
	} else {
        throw GradeError("GradeTooLowException");
	}
};

std::string Form::getName() const {
	return (m_name);
};

bool        Form::isSigned() const {
	return (m_isSigned);
};

short Form::getGradeToSign() const {
	return (m_gradeToSign);
};

short Form::getGradeToExecute() const {
	return (m_gradeToExecute);
};

short Form::isValid(const int grade) const {
	if (grade > 150) {
		throw GradeError("GradeTooLowException");
	} if (grade < 1) {
		throw GradeError("GradeTooHighException");
	}
	return (grade);
}

const char* Form::GradeError::what() const throw() {
	return (m_message.c_str());
};

Form::GradeError::GradeError(const std::string &message) {
	m_message = message;
}

void Form::GradeError::setMessage(const std::string &message) {
	m_message = message;
}

Form::GradeError::~GradeError() throw() {};

std::ostream &operator<<(std::ostream &out, const Form &obj) {
	std::cout << obj.getName() << ", Form grade to sign "
		<< obj.getGradeToSign() << ", grade to execute "
		<< obj.getGradeToExecute();
		obj.isSigned() == false ? std::cout << ", is not signed " << "." :
		std::cout << ", is signed" << std::endl;
	return (out);
};