#include "AForm.hpp"

AForm::AForm() :
	m_name("default"), m_gradeToSign(isValid(60)), m_gradeToExecute(isValid(50)) {
	m_isSigned = false;
};

AForm::AForm(const std::string name,  const short gradeToSign, const short gradeToExecute) :
	m_name(name), m_gradeToSign(isValid(gradeToSign)), m_gradeToExecute(isValid(gradeToExecute)) {
		m_isSigned = false;
};

AForm::AForm(const AForm &obj) :
	m_name(obj.m_name), m_gradeToSign(isValid(obj.m_gradeToSign)), m_gradeToExecute(isValid(obj.m_gradeToExecute))  {
		m_isSigned = obj.m_isSigned;
};

AForm::~AForm() {};

AForm &AForm::operator=(const AForm &obj) {
	m_isSigned = obj.m_isSigned;
	return (*this);
};

void AForm::beSigned(const Bureaucrat &Bureaucrat) {
	if (m_isSigned == true) {
        throw GradeError("GradeAlreadySigned");
	} if (Bureaucrat.getGrade() <= m_gradeToSign) {
		m_isSigned = true;
	} else {
        throw GradeError("GradeTooLowException");
	}
};

std::string AForm::getName() const {
	return (m_name);
};

bool        AForm::isSigned() const {
	return (m_isSigned);
};

short AForm::getGradeToSign() const {
	return (m_gradeToSign);
};

short AForm::getGradeToExecute() const {
	return (m_gradeToExecute);
};

void AForm::execute(Bureaucrat const & executor) const {
	if (m_isSigned == false) {
		throw GradeError("FormIsNotSignedException");
	} if (executor.getGrade() > m_gradeToExecute) {
		throw GradeError("GradeTooLowToExecuteException");
	}
	this->action();
};

short AForm::isValid(const int grade) const {
	if (grade > 150) {
		throw GradeError("GradeTooLowException");
	} if (grade < 1) {
		throw GradeError("GradeTooHighException");
	}
	return (grade);
}

const char* AForm::GradeError::what() const throw() {
	return (m_message.c_str());
};

AForm::GradeError::GradeError(const std::string &message) {
	m_message = message;
}

void AForm::GradeError::setMessage(const std::string &message) {
	m_message = message;
}

AForm::GradeError::~GradeError() throw() {};

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
	std::cout << obj.getName() << ", Form grade to sign "
		<< obj.getGradeToSign() << ", grade to execute "
		<< obj.getGradeToExecute();
		obj.isSigned() == false ? std::cout << ", is not signed " << "." :
		std::cout << ", is signed" << std::endl;
	return (out);
};