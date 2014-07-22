

#include "stdafx.h"
#include "Bitmap.h"
//#include "ASCII.h"
//#include "BlackAndWhite.h"
//#include "Contrast.h"
//#include "Speckler.h"
//#include "Exploder.h"
//#include "Peano.h"
#include <iostream>
#include "math.h"
#include <random>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	Bitmap I(512, 512);
	I.read_from("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\Hokusai2\\Hokusai2.bmp");
	I.equals_greyscale(I);
	Bitmap P(512, 512);
	P.equals_paper(I);
	P.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\Hokusai2\\Hokusai2_paper.bmp");
	I.remove_paper(P);
	I.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\Hokusai2\\Hokusai2_wo_paper.bmp");


	/*
	Bitmap I(256, 256);
	I.read_from("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\Hokusai.bmp");
	I.equals_greyscale(I);
	Bitmap P(256, 256);
	P.equals_paper(I);
	*/
	//P.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\Hokusai_paper.bmp");
	//P.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\Hokusai_Paper_0775.bmp");
	
	//P.read_from("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\3000\\STEP_1500.bmp");
	
	/*Bitmap B0(256, 256);
	B0.equals_naive_blur(P);
	Bitmap B1(256, 256);
	B1.equals_naive_blur(B0);
	Bitmap B2(256, 256);
	B2.equals_naive_blur(B1);
	Bitmap B3(256, 256);
	B3.equals_naive_blur(B2);
	B3.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\3000\\Hokusai_paper_blurred.bmp");
	I.remove_paper(B3);
	I.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\3000\\Hokusai_wo_paper.bmp");*/
	//I.remove_paper(P);
	//I.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\for_blog\\paper\\3000\\Hokusai_wo_unblurredpaper.bmp");
	


	//Bitmap I(256, 256);
	//fill_peano(I);
	//I.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\P2.bmp");

	//Bitmap I(256, 256);
	//I.read_from("C:\\Users\\Sam\\Desktop\\Elegant\\David.bmp");
	//Bitmap M(256, 256);
	////contrast_map(I, M);
	//M.equals_sepia(I);
	//M.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\F.bmp");

	//Bitmap I(256, 256);
	//I.read_from("C:\\Users\\Sam\\Desktop\\Elegant\\Hat_O.bmp");
	//turn_BW_scratched(I);
	//I.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\BW.bmp");

	//Bitmap I(256, 256);
	//I.read_from("C:\\Users\\Sam\\Desktop\\Elegant\\hat_O.bmp");
	//ASCIIfier A("C:\\Users\\Sam\\Desktop\\Elegant\\text.bmp", 16, 8);
	//(*A.ASCII['~'-' ']).write_to("C:\\Users\\Sam\\Desktop\\Elegant\\A.bmp");
	//cout << "`````" << endl;
	//A.print_ascii(&I);
	//cout << "`````" << endl;
	//char l;
	//cin >> l;

	//Bitmap I(256, 256);
	//I.read_from("C:\\Users\\Sam\\Desktop\\Elegant\\WoahBIG.bmp");
	//Bitmap F(256, 256);
	//F.equals_clean(I);
	//F.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\F.bmp");

	//explode("C:\\Users\\Sam\\Desktop\\Elegant\\DEMO\\17_SciOly.bmp",
	//		"C:\\Users\\Sam\\Desktop\\Elegant\\DEMO\\EXAMPLE.bmp",
	//		4);

	//Bitmap I(256, 256);
	//I.read_from("C:\\Users\\Sam\\Desktop\\Elegant\\hat_O.bmp");
	//turn_8(I);
	//I.write_to("C:\\Users\\Sam\\Desktop\\Elegant\\8.bmp");

	return 0;
}

