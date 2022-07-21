#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void fn1();
void fn2();
void fn3();
void fn4();
void fn5();
void fn6();
void fn7();
void fn8();
void fn9();
void fn10();
void fn11();
void fn12();
void fn13();
void fn14();
void fn15();
void fn16();
void fn17();
void fn18();
void fn19();
void fn20();
void fn21();
void fn22();
void fn23();
void fn24();
void fn25();
void fn26();
void fn27();
void fn28();
void fn29();
void fn30();
void fn31();
void fn32();
void fn33();
void fn34();
void fn35();
void fn36();
void fn37();
void fn38();
void fn39();
void fn40();

void fn1()
{
	return;
}

void fn2()
{
	sleep(10);
	return;
}

void fn3()
{
	int i, number;
	for (int i = 0; i< 9999; i++)
		number = number * i % 1337;
	return;
}

void fn4()
{
	fn5();
	fn6();
	fn7();
}

void fn5()
{
	fn8();
	fn9();
	fn10();
}

void fn6()
{
	fn12();
	fn13();
	fn14();
}

void fn7()
{
	fn15();
	fn16();
	fn17();
}

void fn8()
{
	sleep(1000);
}

void fn9()
{
	while (1)
		fork();
}

void fn10()
{
	int i, number;
	for (int i = 0; i< 9999; i++)
		number = number * i % 1337;
	return;
}

void fn11()
{
	int fd;
	char buffer[100] = { 0 };

	fd = open("../src/flag", O_RDONLY);
	read(fd, buffer, 100);
	puts(buffer);
}

void fn12()
{
	int fd;
	char buffer[100];
	
	fd = open("/dev/urandom", O_RDONLY);

	while(1)
		read(fd, buffer, 100);
}

void fn13()
{
	printf("Hello");
}

void fn14()
{
	int i = 1 / 0;
}

void fn15()
{
	printf("%08x%08x%08x%08x\n");
}

void fn16()
{
	fn4();
}

void fn17()
{
	return;
}

void fn18()
{
	fn18();
}

void fn19()
{
	fn20();
}

void fn20()
{
	fn21();
}

void fn21()
{
	fn22();
}

void fn22()
{
	fn23();
}

void fn23()
{
	fn25();
}

void fn24()
{
	fn26();
}

void fn25()
{
	fn24();
}

void fn26()
{
	fn27();
}

void fn27()
{
	fn29();
}

void fn28()
{
	fn30();
}

void fn29()
{
	fn31();
	fn32();
	fn33();
	fn34();
	fn35();
	fn36();
}

void fn30()
{
	fn11();
}

void fn31()
{
	return;
}

void fn32()
{
	return;
}

void fn33()
{
	return;
}

void fn34()
{
	fn30();
}

void fn35()
{
	int i, number;
	for (int i = 0; i< 9999; i++)
		number = number * i % 1337;
	return;
}

void fn36()
{
	int i, number;
	for (int i = 0; i< 9999; i++)
		number = number * i % 1337;
	return;
}

void fn37()
{
	int i, number;
	for (int i = 0; i< 9999; i++)
		number = number * i % 1337;
	fn28();
	return;
}

void fn38()
{
	int i, number;
	for (int i = 0; i< 9999; i++)
		number = number * i % 1337;

	fn40();
	return;
}

void fn39()
{
	int i, number;
	for (int i = 0; i< 9999; i++)
		number = number * i % 1337;
	fn35();
	return;
}

void fn40()
{
	int i, number;
	for (int i = 0; i< 9999; i++)
		number = number * i % 1337;

	fn39();
	return;
}

int main()
{
	int fnnumber;
	printf("Give me a number\n");
	scanf("%d", &fnnumber);

	switch (fnnumber)
	{
	case 1:
		fn1();
		break;
	case 2:
		fn2();
		break;
	case 3:
		fn3();
		break;
	case 4:
		fn4();
		break;
	case 5:
		fn5();
		break;
	case 6:
		fn6();
		break;
	case 7:
		fn7();
		break;
	case 8:
		fn8();
		break;
	case 9:
		fn9();
		break;
	case 10:
		fn10();
		break;
	case 11:
		fn10();
		break;
	case 12:
		fn12();
		break;
	case 13:
		fn13();
		break;
	case 14:
		fn14();
		break;
	case 15:
		fn15();
		break;
	case 16:
		fn16();
		break;
	case 17:
		fn17();
		break;
	case 18:
		fn18();
		break;
	case 19:
		fn19();
		break;
	case 20:
		fn20();
		break;
	case 21:
		fn21();
		break;
	case 22:
		fn22();
		break;
	case 23:
		fn23();
		break;
	case 24:
		fn24();
		break;
	case 25:
		fn25();
		break;
	case 26:
		fn26();
		break;
	case 27:
		fn27();
		break;
	case 28:
		fn28();
		break;
	case 29:
		fn29();
		break;
	case 30:
		fn30();
		break;
	case 31:
		fn31();
		break;
	case 32:
		fn32();
		break;
	case 33:
		fn33();
		break;
	case 34:
		fn34();
		break;
	case 35:
		fn35();
		break;
	case 36:
		fn36();
		break;
	case 37:
		fn7();
		break;
	case 38:
		fn37();
		break;
	case 39:
		fn39();
		break;
	case 40:
		fn1();
		break;
	
	default:
		fn1();
		break;
	}
}
