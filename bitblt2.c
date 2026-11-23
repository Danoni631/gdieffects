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
	BitBlt(hdc, 2, 0, w, h, hdc, 0, 2, SRCINVERT);
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
