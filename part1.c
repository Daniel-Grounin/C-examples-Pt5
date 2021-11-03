/* Assignment 5: Author- Daniel Grounin*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include<malloc.h>
#include<string.h>

int countOdd(int num);
int GetNum(int Arr[], int num, int size);
int EqualStrings(char* str1, char* str2);

int main(){
	int num = 76767;
	printf("%d\n", countOdd(num));
	puts("****************");
	int num2 = 10;
	int Arr[] = { 926,560,36,90,681,405,707 };
	int size = 7;
	printf("%d\n", GetNum(Arr, num, size));
	puts("****************");

	char* str1 = "Abc$123$dEfG";
	char* str2 = "AbCA123$DEfg";

	printf("%d", EqualStrings(str1, str2));
}

int countOdd(int num){
	if (num == 0)
		return 0;
	else if (num % 2 == 0)
		return countOdd(num / 10);
	else
		return 1 + countOdd(num / 10);
}

int GetNum(int Arr[], int num, int size){
	if (num == 0) {
		return 0;
	}
	if (size == 0) {
		return 0;
	}
	if (Arr[size - 1] % num == 0){
		return 1 + GetNum(Arr, num, size - 1);
	}
	else
		return 0 + GetNum(Arr, num, size - 1);
}

int EqualStrings(char* str1, char* str2){
	if (*str1 == '\0' || *str2 == '\0')
		if (*str2 == '\0' && *str1 == '\0')
			return 1;
		else
			return 0;
	if (*str1 >= 'a' && *str1 <= 'z' || *str1 >= 'A' && *str1 <= 'Z' && *str2 >= 'a' && *str2 <= 'z' || *str2 >= 'A' && *str2 <= 'Z')

		if (*str1 == *str2 || *str1 + 32 == *str2 || *str2 + 32 == *str1)

			return EqualStrings(str1 + 1, str2 + 1);
		else
			return 0;
	if (*str1 == *str2)
		return EqualStrings(str1 + 1, str2 + 1);
	else
		return 0;

}