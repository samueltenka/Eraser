struct Dimensions
{
	int height, width;
};

template<class Pixel>
class Array2D: public Dimensions
{
protected:
	Pixel** bitmap;

public:
	Pixel* operator[](int r);	// so A[r][c] should be a Pixel.
								// TODO: THIS IS UNSAFE, RIGHT?!

	Array2D(int height, int width);
	void allocate_bitmap(int h, int w);
	void deallocate_bitmap();
	~Array2D();

	void copy_into(Array2D& other);
	void copy_from(Array2D& other);
};


// FOR SOME REASON,
// SINCE ARRAY2D IS A TEMPLATE CLASS, 
// THE SOURCE HAS TO GO IN THIS HEADER.
template <class Pixel>
Pixel* Array2D<Pixel>::operator[](int r)
{
	return bitmap[r];
}


template <class Pixel>
Array2D<Pixel>::Array2D(int h, int w)
{
	allocate_bitmap(h, w);
}

template <class Pixel>
void Array2D<Pixel>::allocate_bitmap(int h, int w)
{
	if(height != h || width != w)
	{
		deallocate_bitmap();

		height = h;
		width = w;

		bitmap = new Pixel*[height];
		for(int r = 0; r < height; r++)
		{
			bitmap[r] = new Pixel[width];
		}
	}
}

template <class Pixel>
void Array2D<Pixel>::deallocate_bitmap()
{
	if(bitmap != NULL)
	{
		for(int r = 0; r < height; r++)
		{
			delete[] bitmap[r];
			bitmap[r] = NULL;
		}
		delete[] bitmap;
		bitmap = NULL;

		height = -1; width = -1;
	}
}

template <class Pixel>
Array2D<Pixel>::~Array2D()
{
	deallocate_bitmap();
}

template <class Pixel>
void Array2D<Pixel>::copy_into(Array2D& other)
{
	other.allocate_bitmap(height, width);
	for(int r = 0; r < height; r++)
	{
		for(int c = 0; c < width; c++)
		{
			other.bitmap[r][c] = bitmap[r][c];
		}
	}
}

template <class Pixel>
void Array2D<Pixel>::copy_from(Array2D& other)
{
	other.copy_into(*this);
}
