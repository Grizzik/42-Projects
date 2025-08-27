#ifndef FORM_HPP
# define FORM_HPP
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
		
	public:
		Form(void);
		Form(const std::string name, int gradeSign, int gradeExec);
		Form(const Form &form);
		virtual ~Form();

		Form	&operator=(const Form &form);

		// member functions
		const std::string	getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSigned(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(const Bureaucrat &bureaucrat) const = 0;
		virtual void		executeCheck(const Bureaucrat &bureaucrat) const;

		// exceptions
		class GradeTooHigh : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("grade is too high"); }
		};

		class GradeTooLow : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("grade is too low"); }
		};
		
		class ExecuteNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("form is not signed"); }
		};
		
		class FileOpeningFail : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("file cannot be opened"); }
		};
};

std::ostream	&operator<<(std::ostream &flux, const Form &form);

#endif