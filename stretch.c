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
	StretchBlt(hdc, 0, 0, w + 2, h + 2, hdc, 2, 2, w, h, SRCCOPY);
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
