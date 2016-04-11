

int SetBlok(float x, float y, int nr, int type, int start)
{
	blok[nr].x=x;
	blok[nr].y=y;
	blok[nr].speed_b=6;
	blok[nr].speed_rotate=6;
	blok[nr].type=type;
	blok[nr].rotate_start=start;
	if (blok[nr].type==1) blok[nr].live=5;
	if (blok[nr].type==2) blok[nr].live=31;
	if (blok[nr].type==3) {blok[nr].godmode=true; ilosc_b--;}
	ilosc_blokow++;
	ilosc_b++;
	return 1;
}

int Level(int number)
{
	if (number==1)
	{
		ilosc_blokow=0;
		SetBlok(-13,10,0,2,1);
		SetBlok(-9.3f,10,1,1,1);
		SetBlok(-5.6f,10,2,1,1);
		SetBlok(-1.9f,10,3,1,1);
		SetBlok( 1.8f,10,4,1,1);
		SetBlok( 5.5f,10,5,1,1);
		SetBlok( 9.2f,10,6,1,1);
		SetBlok( 12.9f,10,7,2,1);

		SetBlok(-13,8.5f,8,1,1);
		SetBlok(-9.3f,8.5f,9,2,1);
		SetBlok(-5.6f,8.5f,10,1,1);
		SetBlok(-1.9f,8.5f,11,1,1);
		SetBlok( 1.8f,8.5f,12,1,1);
		SetBlok( 5.5f,8.5f,13,1,1);
		SetBlok( 9.2f,8.5f,14,2,1);
		SetBlok( 12.9f,8.5f,15,1,1);

		SetBlok(-13,7,16,1,1);
		SetBlok(-9.3f,7,17,1,1);
		SetBlok(-5.6f,7,18,2,1);
		SetBlok(-1.9f,7,19,2,1);
		SetBlok( 1.8f,7,20,2,1);
		SetBlok( 5.5f,7,21,2,1);
		SetBlok( 9.2f,7,22,1,1);
		SetBlok( 12.9f,7,23,1,1);

		SetBlok(-1.9f,5.5f,24,1,1);
		SetBlok( 1.8f,5.5f,25,1,1);
	}
	if (number==2)
	{
		ilosc_blokow=0;
		SetBlok(-13,10,0,2,2);
		SetBlok(-9.3f,10,1,1,2);
		SetBlok(-5.6f,10,2,1,1);
		SetBlok(-1.9f,10,3,1,2);
		SetBlok( 1.8f,10,4,1,1);
		SetBlok( 5.5f,10,5,1,1);
		SetBlok( 9.2f,10,6,1,2);
		SetBlok( 12.9f,10,7,2,2);

		SetBlok(-13,8.5f,8,3,0);
		SetBlok(-9.3f,8.5f,9,2,1);
		SetBlok(-5.6f,8.5f,10,1,1);
		SetBlok(-1.9f,8.5f,11,1,1);
		SetBlok( 1.8f,8.5f,12,1,1);
		SetBlok( 5.5f,8.5f,13,1,1);
		SetBlok( 9.2f,8.5f,14,2,1);
		SetBlok( 12.9f,8.5f,15,3,0);

		SetBlok(-13,7,16,3,0);
		SetBlok(-9.3f,7,17,1,1);
		SetBlok(-5.6f,7,18,3,0);
		SetBlok(-1.9f,7,19,3,0);
		SetBlok( 1.8f,7,20,3,0);
		SetBlok( 5.5f,7,21,3,0);
		SetBlok( 9.2f,7,22,1,1);
		SetBlok( 12.9f,7,23,3,0);

		SetBlok(-13,5.5f,24,1,1);
		SetBlok(-9.3f,5.5f,25,2,1);
		SetBlok(-5.6f,5.5f,26,1,1);
		SetBlok(-1.9f,5.5f,27,1,1);
		SetBlok( 1.8f,5.5f,28,1,1);
		SetBlok( 5.5f,5.5f,29,1,1);
		SetBlok( 9.2f,5.5f,30,2,1);
		SetBlok( 12.9f,5.5f,31,1,1);
	}
	return 1;
}