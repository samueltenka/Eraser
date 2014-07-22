#include "stdafx.h"
#include "Bitmap.h"


void Bitmap::equals_greyscale(Bitmap &original)
{
	allocate_bitmap(original.height, original.width);

	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			bitmap[r][c].set(original[r][c].value());
		}
	}
}



int mask[5][5] = {	{0, 1, 1, 1, 0},
					{1, 2, 2, 2, 1},
					{1, 2, 3, 2, 1},
					{1, 2, 2, 2, 1},
					{0, 1, 1, 1, 0}};
int tot = 3 + 8*2 + 12;
void Bitmap::equals_blur_for_sepia(Bitmap &original)
{
	allocate_bitmap(original.height, original.width);

	for(int r = 2; r < height-2; r++)
	{
		for(int c = 2; c < width-2; c++)
		{
			RGB average;
			for(int i = -2; i <= 2; i++)
			{
				for(int j = -2; j <= 2; j++)
				{
					average += original[r+i][c+j] * mask[i+2][j+2];
				}
			}
			average /= tot;

			bitmap[r][c] = average;
		}
	}
}


void Bitmap::equals_sepia(Bitmap &original)
{
	allocate_bitmap(original.height, original.width);

	Bitmap blurred(original.height, original.width);
	blurred.equals_blur_for_sepia(original);

	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			// blur out light areas
			int v = original[r][c].value();
			int sep_tone = blurred[r][c].value()*v + v*(255-v);
			sep_tone /= 255;

			// sepia-tone
			bitmap[r][c] = RGB(255, 255, 255)/6;
			bitmap[r][c] += RGB(sep_tone, sep_tone, sep_tone)/3;
			bitmap[r][c] += RGB(sep_tone/3, sep_tone/6, 0);
		}
	}
}

