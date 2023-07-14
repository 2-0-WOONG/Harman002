//#include <iostream>     //C++
//c언어 꿀팁
//1.수정시 기존소스 삭제 자제
//2.매라인마다 코멘트 달기

//#include <stdio.h>
//#include <malloc.h>	//메모리 공간 확보
//
//
//
//int main(int argc, char *argv[])	// PointerSample 10000 500: //command line 명령어
//									// 10000 : Start memory 주소
//									// 500   : Dump 할 메모리 크기
//{
//	int start = 0x09000000;
//	int length = 500;
//
//	char c;
//	int i;
//	float a;
//	double d;
//
//	c = 'A';	//변수 형태:문자
//	i = 1;		//변수 형태:정수
//	a = 2.0;	//변수 형태:실수
//	d = 3.14;	//변수 형태:실수
//	void *p = malloc(100);  //0x00000000; // 그저 주소일뿐
//
//	*(double *)p = d; //보이드인 포인터를 더블 포인터로 사용
//	printf("p = %8f [0x%08x]\n", *(double*)p, p);
	
	//printf("char c = %c\n", c);	//문자 출력: %c
	//printf("int i = %d\n", i);	//정수형 출력:%d, 16진수 출력:%x
	//printf("float a = %f\n", a);	//실수형 출력:%f
	//printf("double d = %lf\n", d);	//실수형 출력:%lf

	//printf("int i = %d [0x%08x]\n", i, 10);	//16진수 출력:%x  %08x-> 8bit 16진수 표현 앞은 0으로 채워라




	//LF -> 줄바꿈
	//CR -> 제일 앞으로




#include <stdio.h>
#include <malloc.h>	//메모리 공간 확보
char buf[100];
void MemoryDump(int start, int length);	//함수의 원형 Prototype

int main(int argc, char *argv[])

{
	int start = 0x09000000;
	int length = 500;

	char c = 'A';
	int i = 1;
	float a = 2.0;
	double d = 3.14;
	void *p = malloc(100);  //0x00000000; // 그저 주소일뿐

	*(double *)p = d; //보이드인 포인터를 더블 포인터로 사용
	MemoryDump((int)buf, length);
}
void MemoryDump(int start, int length)
{
	char *cp = buf;
	//void *vp = (void *)start;

	int i = 0; //index 변수 초기값

	while (i < length)
	{
		//char *cp = (char *)vp;
		//char c = *cp;
		//아래와 같은 문구
		unsigned char c = *((char *)cp + i++);
		//i++;
		printf("%02x ", c);	//1btye = 8bit = 4bit * 2 = 16진수 2개로 표현 ex)0x?? 
	}
}

