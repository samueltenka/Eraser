#include "stdafx.h"
#include "Bitmap.h"

void Bitmap::equals_naive_blur(Bitmap &original)
{
	allocate_bitmap(original.height, original.width);

	// get the body:
	for(int r = 1; r < height-1; r++)
	{
		for(int c = 1; c < width-1; c++)
		{
			bitmap[r][c].set(0);
			for(int y = -1; y <= 1; y++)
			{
				for(int x = -1; x <= 1; x++)
				{
					bitmap[r][c] += original[r+y][c+x];
				}
			}
			bitmap[r][c] /= 9;
		}
	}

	// get the edges and corners:
	for(int r = 0; r < height; r++)
	{
		int c_skip = (r==0 || r==height-1) ? 1 : width-1;
		for(int c = 0; c < width; c += c_skip)
		{
			bitmap[r][c].set(0);
			int count = 0;
			for(int y = -1; y <= 1; y++)
			{
				for(int x = -1; x <= 1; x++)
				{
					int new_r = r+y, new_c = c+x;
					if(	0 <= new_r && new_r < height &&		// the conditions since we know we're on some edge
						0 <= new_c && new_c < width)
					{
						bitmap[r][c] += original[r+y][c+x];
						count += 1;
					}
				}
			}
			bitmap[r][c] /= count;
		}
	}
}
