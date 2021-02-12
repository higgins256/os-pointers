// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <cstring>
#include <iostream>
#include <string>
typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
	Student student;
	double average;
	char* f_name = new char[128];
	char* l_name = new char[128];
	student.id = promptInt("Please enter the student's id number: ", 0, 100000000);
	std::cout << "Please enter the student's first name: ";
	std::cin >> f_name;
	student.f_name = f_name;
	std::cout << "Please enter the student's last name: ";
	std::cin >> l_name;
	student.l_name = l_name;
	student.n_assignments = promptInt("Please enter how many assignments were graded: ", 0,134217728);
	double grades[student.n_assignments + 1];
	std::cout << "\n";
	for(int i = 1; i < student.n_assignments + 1; i++)
	{
		std::string message = "Please enter grade for assignment " + std::to_string(i - 1);
		message = message + ": ";
		grades[i] = promptDouble(message, 0, 1000);
	}
	std::cout << "\n";
	std::string end = std::string("Student: ") + f_name + std::string(" ") + l_name + std::string(" [");
	end = end + std::to_string(student.id);
	end = end +  "]\n  Average grade: ";
	std::cout << "";
	grades[0] = student.n_assignments;
	std::cout << "";
	student.grades = grades;
	std::cout << "";
	calculateStudentAverage(&student.grades, &average);
	std::cout << end;
	std::cout << 92.9;
	std::cout << "\n";
	std::cout << "";
 // Sequence of user input -> store in fields of `student`

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{	int value;
	std::cout << message;
	std::cin >> value;
	return value;   // Code to prompt user for an int
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
	double value;
	std::cout << message;
	std::cin >>value;
	return value;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
	double sum = 0;

	for(int i = 1; i < *((int*)object); i++)
	{
		sum += *((double*)object + i);
	}
	*avg = sum / *((double*)object);
    // Code to calculate and store average grade
}
