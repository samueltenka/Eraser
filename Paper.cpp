#include "stdafx.h"
#include "Bitmap.h"
#include <iostream>
using namespace std;


// to get Hokusai_Paper_bad_2.bmp and _3, set (s, k) = (10, 10) or (10, 100).
#define num_steps 1500
#define epsilon 0.02
#define threshold 150
#define epsilon2 0.02
#define m 10
#define k 100
#define s 30
#define t 64

void Bitmap::equals_paper(Bitmap &original)
{
	// initialize to all white:
	allocate_bitmap(original.height, original.width);
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			bitmap[r][c].set(255);
		}
	}

	// gradient descent:
	Bitmap gradient = Bitmap(original.height, original.width);
	for(int i = 0; i < num_steps; i++)
	{
		cout << i << endl;

		// calculate gradient, which depends on blur for s-term
		Bitmap blur(height, width);
		blur.equals_naive_blur((*this));
		for(int r = 0; r < height; r++)
		{
			for(int c = 0; c < width; c++)
			{
				val p = bitmap[r][c].value(),
					o = original.bitmap[r][c].value(),
					b = blur.bitmap[r][c].value();

				gradient[r][c].set(	m +							// positive: makes paper fall.
									k*(p<o ? 2*(p-o) : 0) +		// negative if too low, else zero: pins paper up.
									s*(2*(p-b)));				// away from neighbors (so -gradient is toward): stiffens paper.
			}
		}

		// paper = paper - epsilon * gradient...
		for(int r = 0; r < height; r++)
		{
			for(int c = 0; c < width; c++)
			{
				bitmap[r][c] -= gradient[r][c] * (i < threshold ? epsilon : epsilon2);

				// and bound: [t, 256)...
				val p = bitmap[r][c].value();
				bitmap[r][c].set(p<t ? t : p>=256 ? 255 : p);
			}
		}

		if(/*i==1200*/ i%50 == 0)
		{
			write_to("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\STEP.bmp");
			//char l; cin >> l;
		}
	}
}

void Bitmap::remove_paper(Bitmap &paper)
{
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			// additive:
			//bitmap[r][c].set(bitmap[r][c].value() + 255 - paper[r][c].value());

			// multiplicative:
			bitmap[r][c] *= 255;
			bitmap[r][c] /= paper[r][c].value();

			if(bitmap[r][c].value() > 248)
			{
				bitmap[r][c].set(255);
			}
			bitmap[r][c].bound();
		}
	}
}




/*
//
// TO GET Hokusai_Paper_bad.bmp effect, set count to 9 in Naive Blur, then do:
//
#include "stdafx.h"
#include "Bitmap.h"
#include <iostream>
using namespace std;

#define num_steps 200
#define epsilon 0.1
#define m 10
#define k 100
#define s 1000
#define t 64

void Bitmap::equals_paper(Bitmap &original)
{
	// initialize to all white:
	allocate_bitmap(original.height, original.width);
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			bitmap[r][c].set(255);
		}
	}

	// gradient descent:
	Bitmap gradient = Bitmap(original.height, original.width);
	for(int i = 0; i < num_steps; i++)
	{
		cout << i << endl;

		// calculate gradient, which depends on blur for s-term
		Bitmap blur(height, width);
		blur.equals_naive_blur((*this));
		for(int r = 0; r < height; r++)
		{
			for(int c = 0; c < width; c++)
			{
				int p = bitmap[r][c].value(),
					o = original.bitmap[r][c].value(),
					b = blur.bitmap[r][c].value();

				gradient[r][c].set(	m +							// positive: makes paper fall.
									k*(p<o ? 2*(p-o) : 0) +		// negative if too low, else zero: pins paper up.
									s*(2*(p-b)));				// away from neighbors (so -gradient is toward): stiffens paper.
			}
		}

		// paper = paper - epsilon * gradient...
		for(int r = 0; r < height; r++)
		{
			for(int c = 0; c < width; c++)
			{
				bitmap[r][c] -= gradient[r][c] * epsilon;

				// and bound: [t, 256)...
				int p = bitmap[r][c].value();
				bitmap[r][c].set(p<t ? t : p>=256 ? 255 : p);
			}
		}
	}
}
*/

