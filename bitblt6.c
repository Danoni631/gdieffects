#include <windows.h>
#include <math.h>

#define M_PI   3.14159265358979323846264338327950288

typedef struct
{
	HDC hdc;
	int w;
	int h;
	HDC dcCopy;
} GDIPayload_t;

double angle = 0;

void Effect(HDC hdc, int w, int h)
{
	int x = (sin(angle)) * 135.f;

	BitBlt(hdc, x, 0, w, h, hdc, x, 5, NOTSRCERASE);
	ReleaseDC(NULL, hdc);

	angle = fmod(angle + M_PI / 15.f, M_PI * 15.f) / 1.001;
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
