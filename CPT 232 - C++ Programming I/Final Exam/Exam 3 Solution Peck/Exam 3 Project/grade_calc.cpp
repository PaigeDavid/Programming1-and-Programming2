/************************************************************************************************
* FILENAME		: grade_calc.cpp														        *
* PROGRAMMER	: Paige-David Peck                                                              *
* PURPOSE		: Calculates and displays the grades and averages						        *
************************************************************************************************/

#include <iostream>
#include<iomanip>

using namespace std;

//Function Prototypes
int grade_input();
char grade_num_letter(int);
int average_calc(int, int);
void final_display(int, int, int, int, int, int, int, int);


int main()
{

		char grade_letter;
		
		int grade_num, average, total_grade_averaged = 0,
		total_valid = 0, total_grades = 0, total_a = 0,
		total_b = 0, total_c = 0, total_d = 0, total_f = 0;

		grade_num = grade_input();

		while(grade_num >= 0)
		{
			grade_letter = grade_num_letter(grade_num);

			if(grade_letter == 'A')
				total_a++;
			else if(grade_letter == 'B')
				total_b++;
			else if(grade_letter == 'C')
				total_c++;
			else if(grade_letter == 'D')
				total_d++;
			else
				total_f++;
			//END if

			total_grades++;

			if(grade_num > 0)
			{
				total_grade_averaged++;
				total_valid += grade_num;
			} //END if
				

			grade_num = grade_input();
		}
		//END while loop

		average = average_calc(total_valid, total_grade_averaged);

		system("pause");
		system("cls");

		final_display(total_grades, total_grade_averaged, average,
			total_a, total_b, total_c, total_d, total_f);



	return 0;
}
//END main


/****************************************
 * PURPOSE	: input numerical grade	*
 * PASSED IN: nothing				*
 * RETURNED: numberical grade		*
 ****************************************/
int grade_input()
{
	int grade_num;

	cout << "Please enter the numerical grade (Enter -1 to exit): ";
	cin >> grade_num;

	cout << endl;

	return grade_num;
} //END grade_input

/***************************************	*
 * PURPOSE	: Change numerical to letter grade	*
 * PASSED IN: Numerical grade					*
 * RETURNED: letter grade						*
 ****************************************/


char grade_num_letter(int grade_num)
{
	char grade_letter;

	if(grade_num > 90)
	{
		grade_letter = 'A';
		cout << "Letter grade: " << grade_letter << endl;
	}
	else if(grade_num > 80 && grade_num <= 90)
	{
		grade_letter = 'B';
		cout << "Letter grade: " << grade_letter << endl;
	}
	else if(grade_num > 70 && grade_num <= 80)
	{
		grade_letter = 'C';
		cout << "Letter grade: " << grade_letter << endl;
	}
	else if(grade_num >= 65 && grade_num <= 70)
	{
		grade_letter = 'D';
		cout << "Letter grade: " << grade_letter << endl;
	}
	else
	{
		grade_letter = 'F';
		cout << "Letter grade: " << grade_letter << endl;
	}
	//END if

	return grade_letter;
}//END grade_num_letter

/***********************************************************************	*
 * PURPOSE	: calc. average													*
 * PASSED IN: total valid grades & total number of grades to be averaged	*
 * RETURNED: average														*
 ***********************************************************************/


int average_calc(int total_valid, int total_grade_averaged)
{
	int average;

	average = total_valid / total_grade_averaged;

	return average;
}//END average_calc

/***************************************************************************************	*
 * PURPOSE	: Display final report															*
 * PASSED IN: total number of grades, total grades in average, average, total letter counts	*
 * RETURNED: nothing																		*
 ***************************************************************************************/

void final_display(int total_grades, int total_grade_averaged, int average,
			int total_a, int total_b, int total_c, int total_d, int total_f)
{

	cout	<< setw(50) << "PECK CODING UNLIMITED\n";
	cout	<< setw(50) << "Grade Calculator\n\n" << endl;

	cout << "\nFINAL REPORT\n\n" << endl;
	cout << fixed;

		cout << setw(20) << "TOTAL GRADES" << setw(30) << "TOTAL GRADES IN AVERAGE" << setw(15) << "AVERAGE" << endl;
		cout << setw(15) << total_grades << setw(24) << total_grade_averaged << setw(25) << average << "\n" << endl;
		cout << setw(18) << "TOTAL A's" << setw(22) << "TOTAL B's" << setw(22) << "TOTAL C's" << endl;
		cout << setw(15) << total_a << setw(23) << total_b << setw(22) << total_c << "\n" << endl;
		cout << setw(18) << "TOTAL D's" << setw(22) << "TOTAL F's" << setw(25) <<  endl;
		cout << setw(15) << total_d << setw(23) << total_f << "\n\n" << endl;
}//END final_display