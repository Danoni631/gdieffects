#include <windows.h>

typedef struct
{
	HDC hdc;
	int w;
	int h;
	HDC dcCopy;
} GDIPayload_t;

void Effect(HDC hdc, int w, int h)
{
	BitBlt(hdc, rand() % 30, rand() % 30, w, h, hdc, rand() % 30, rand() % 30, SRCERASE);
	ReleaseDC(NULL, hdc);
}

int main()
{
	while (true)
	{
		GDIPayload_t GDIdefs;
		GDIdefs.hdc = GetDC(NULL);
		GDIdefs.w = GetSystemMetrics(0);
		GDIdefs.h = GetSystemMetrics(1);

		Effect(GDIdefs.hdc, GDIdefs.w, GDIdefs.h);
		Sleep(1);
	}
}
