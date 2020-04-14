#define _CRT_SECURE_NO_WARNINGS

// график sin(x)
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <conio.h>

	int main()
	{
		float x;
		HDC hDC = GetDC(GetConsoleWindow());
		HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
		SelectObject(hDC, Pen);
		MoveToEx(hDC, 0, 85, NULL);
		LineTo(hDC, 200, 85);
		MoveToEx(hDC, 100, 0, NULL);
		LineTo(hDC, 100, 170);
		for (x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - center
		{
			MoveToEx(hDC, 10 * x + 100, -10 * sin(x) + 85, NULL);//10 - scale
			LineTo(hDC, 10 * x + 100, -10 * sin(x) + 85);
		}

		//system("pause");
		getchar();
		return 0;
	}
	