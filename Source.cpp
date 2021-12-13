#include <iostream>
#include <random>
#include <time.h>

// Task 1 

char* initArr(int length)
{
	char* ptr = new char[length];
	
	std::mt19937 rand;
	rand.seed(time(NULL));
	std::uniform_int_distribution<int> range((int) 'a', (int) 'z');
	
	for (int i = 0; i < length - 1; i++)
		ptr[i] = (char)range(rand);
	ptr[length - 1] = '\0';

	return ptr;
}

void printArr(char* ptr)
{
	if (ptr != nullptr)
	{
		int idx = 0;
		while (ptr[idx] != '\0')
		{
			printf("%3c", ptr[idx++]);
		}
		printf("\n");
	}
	else printf("Empty string\n");
}

unsigned int sumSymbols(char* string)
{
	if (string != nullptr)
	{
		int idx = 0;
		unsigned int sum = 0;
		while (string[idx] != '\0')
		{
			sum += string[idx++];
		}
		return sum;
	}
	else return 0;
}

// Task 2

void greedyAlg(int sum)
{
	int coins [] {50, 10, 5, 2, 1, -1};
	int idx{ 0 }, total{ 0 };
	
	while (coins[idx] != -1)
	{
		printf("Number of %d coins: %d\n", coins[idx], sum / coins[idx]);
		total += sum / coins[idx];
		sum = sum % coins[idx++];
	}
	printf("Total: %d", total);
}


int main ()
{
	// Task 1
	char* string;
	string = initArr(30);
	printArr(string);
	printf("String sum:%4u\n", sumSymbols(string));

	//Task 2

	greedyAlg(98);



	return 0;
}