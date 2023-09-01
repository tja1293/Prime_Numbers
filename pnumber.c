#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//open - fopen
//read = fgetc (get next character), fscanf (get next line (in a specific format))
//write - 
// close
// to run.................. gcc text.c...................... ( ./a.out   )

void main()
{

	FILE *file;
	FILE *writefile;

	file = fopen( "pnumbers.txt" , "r"); // r = read w = write
	
	
	char c;
	int n; // n is lines of code (numbers in list)
	n = 0; // line count
	int p = 0; //item in list
	int i = 0;

	
	while ((c = fgetc(file)) !=EOF)
	{
		if (c =='\n') // if character gets to a (new line character) + 1 to the n variable
		{
			n++;
		}

	}
	
	printf("lines = %d\n", n);
	
	fclose(file);
	
	
		int * numberList = malloc( n * sizeof(int) ); //creating a numberlist
		//int numberList[n]; is the same
	
	

	file = fopen( "pnumbers.txt" , "r"); // r = read w = write
	
	for (int i =0; i < n; i++) // storing numbers into the number list
	{
		fscanf(file, "%d", &numberList[i]);
	}
	
		fclose(file);
		

	
	int m;
	int num;
	int countprime = 0;	// variable to count how many primes
	bool isPrime = true; 	// bool 
	
	writefile = fopen( "primes.txt" , "w"); //creating new file to write too
	
	
	for(int j = 0; j < n; j++) // loop to itterate through the number list
	{
		
	int num = numberList[j]; // num is the number in the NumberList as j
	//m = num / 2; // halving each number in the numberlist
	m = num; // halving each number in the numberlist
	
		isPrime = true; // resetting isPrime to true 
		
		if (num == 1 || num == 0) // hard coding 1 and 0 and not prime
		{
			isPrime = false;
		}
	
		for (i=2; i<m; i++) //itterating from 2 till the number (not incliding itself and 1)
		{
			if(num%i==0)
			{
				isPrime = false;
				break;
			}
			
		} 
		if(isPrime)
		{
			fprintf(writefile, "%d - Number is prime\n", num);
			countprime += 1;
		}
			
	}
	

	fprintf(writefile, "Number of prime numbers - %d\n", countprime); // printing the countprime variable
	
	fclose(writefile); // close file that has been written to

}
