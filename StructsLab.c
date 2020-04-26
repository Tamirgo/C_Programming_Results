#include<stdio.h>
#include<stdlib.h>
typedef struct student_init_data {
	int sid,num_of_tests, *tests;
}init;

typedef struct student_processed_data {
	int sid;//student id.
	float avg;//student average.
}processed;

typedef struct statistics {
	processed* beneath_avg, *above_avg;//two dynamic arrays of students.
	int beneath_size, above_size;
	float total_avg;
}stats;
init input_data(init Student);
processed Student_Average(init Student);
float Total_Average(float*averages,int size);
stats Classification(init*students, int size);
void printTab(stats stat);
void main()
{
	init students[5];//static array of size 5.
	int i, amount,id;/*id for sid and amount for amount of tests.*/
	stats stat;
	processed test;
	for (i = 0; i < 5; i++)
	{
		printf("Please input the student's id:\n");
		scanf("%d", &id);
		printf("Please input the amount of tests they did:\n");
		scanf("%d", &amount);
		students[i].sid = id;
		students[i].num_of_tests = amount;
	}
	for (i = 0; i < 5; i++)
	{
		students[i] = input_data(students[i]);
	}
	stat = Classification(students, 5);
	printTab(stat);



	

}
init input_data(init Student)
{
	/*This function will recive a student - students' information and will
	return a student with the dynamic array full of their grades.*/

	int i;
	Student.tests = (int*)calloc(Student.num_of_tests, sizeof(int));
	for (i = 0; i < Student.num_of_tests; i++)
	{
		printf("Please enter the %dth grade:\n", i + 1);
		scanf("%d", &Student.tests[i]);
	}
	return Student;
}
processed Student_Average(init Student)
{
	int i;
	float sum = 0.0;
	processed proccesed_student;

	proccesed_student.sid = Student.sid;
	if (Student.num_of_tests == 0)
	{
		proccesed_student.avg = 0;
		return proccesed_student;
	}
	for (i = 0; i < Student.num_of_tests; i++)
	{
		sum += Student.tests[i];
	}
	sum /= Student.num_of_tests;
	proccesed_student.avg = sum;
	return proccesed_student;
}
float Total_Average(float*averages,int size)
{
	int i;
	float total_avg = 0;
	if (size == 0)
	{
		return 0;
	}
	for (i = 0; i < size; i++)
	{
		total_avg += averages[i];
	}
	return total_avg / size;
}

stats Classification(init*students, int size)
{
	stats result;//we will store both arrays here.
	processed* temp_array = (processed*)malloc(size, sizeof(processed));
	int i,below_counter,above_counter;
	float* avg = (float*)calloc(size, sizeof(float)),total_avg;
	result.above_size = result.beneath_size = 0;//just in case, realoc it later.

	result.above_avg = (processed*)calloc(size, sizeof(processed));
	result.beneath_avg = (processed*)calloc(size, sizeof(processed));
	//so now we have both dynamic arrays of size : size which will be changed with realoc in the end.

	//filling in the tmp array which will be traversed later so i can diviate them.
	for (i = 0; i < size; i++)
	{
		temp_array[i] = Student_Average(students[i]);
		avg[i] = temp_array[i].avg;
	}
	total_avg = Total_Average(avg, size);
	below_counter = above_counter = 0;
	for (i = 0; i < size; i++)
	{
		if (temp_array[i].avg < total_avg)
		{
			//beneath
			result.beneath_avg[result.beneath_size++] = temp_array[i];

		}
		else
		{
			result.above_avg[result.above_size++] = temp_array[i];

		}
	}
	
	result.above_avg = realloc(result.above_avg, result.above_size * sizeof(processed));
	result.beneath_avg = realloc(result.beneath_avg, result.beneath_size * sizeof(processed));
	return result;
}

void printTab(stats stat)
{
	int i;
	printf("Above average students:\n");
	for (i = 0; i < stat.above_size; i++)
	{
		printf("id: %d, average: %.2f\n", stat.above_avg[i].sid, stat.above_avg[i].avg);
	}
	printf("\n");
	printf("below average students:\n");
	for (i = 0; i < stat.beneath_size; i++)
	{
		printf("id: %d, average: %.2f\n", stat.beneath_avg[i].sid, stat.beneath_avg[i].avg);
	}
}
