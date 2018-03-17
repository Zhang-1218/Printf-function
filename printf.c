
#include <stdio.h>
#include<stdarg.h>

void dispaly(int num)
{
	if (num > 9)
	{
		dispaly(num / 9);
	}
	putchar(num % 10 + '0');
}

void my_printf(const char* format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format != '\0')
	{
		switch (*format)
		{
			case 'd':
			{
				int ret = va_arg(arg, int);
				dispaly(ret);
			}
				break;
			case 's':
			{
				char* str = va_arg(arg, char*);
				while (*str)
				{
					putchar(*str);
					str++;
				}
			}
				break;
			case  'c':
			{
				 char word = va_arg(arg, char);
				 putchar(word);
			}
				break;
			default:
				putchar(*format);
				break;
		}
		format++;
	}
	va_end(arg);
}

int main()
{
	int a = 10;
	char arr[] = "abcdef";
	char c = '1';
	my_printf("s d c", arr, a, c);
	system("pause");
	return 0;
}