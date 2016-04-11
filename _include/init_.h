void InitTextures()
{
	texture[0]=LoadTexture("gfx/brick_0.bmp");
	texture[1]=LoadTexture("gfx/brick_1.bmp");
	texture[2]=LoadTexture("gfx/brick_2.bmp");
	texture[3]=LoadTexture("gfx/brick_3.bmp");
	texture[4]=LoadTexture("gfx/ball.bmp");
	texture[5]=LoadTexture("gfx/background.bmp");
	texture[6]=LoadTexture("gfx/menu1.bmp");
	texture[7]=LoadTexture("gfx/menu2.bmp");
	fonttext=LoadTexture("gfx/fonts.bmp");
}

void InitGame()
{
	glClearColor(0,0,0,0);

	for (i=0; i<48; i++) blok[i].RESET();



	player.live=1;
	player.godmode=true;

	move_x=0;

	ballX=0;
	ballY=-3;
	ballZ=0;
	

	TimerInit();
	framerate=.01f;

	score=0;
	record=Tscore[10];

	RandomBall();

	ball=gluNewQuadric(); 
	gluQuadricNormals(ball, GLU_NONE);
	gluQuadricTexture(ball, GL_TRUE); 

}
FILE *plik; 

void sprawdz_wynik()
{
	if (score>Tscore[0])
	{
		Tscore[0]=score;
		sortowanie(Tscore,11);

		
		plik = fopen ("score.dat","w");

		fwrite(&Tscore,sizeof(Tscore),1,plik);

		fclose(plik);

	}
}

void BallPsyhisc()
{


	if (start>200)
	{
	   ballX=ballX+stx;
	   ballY=ballY+sty;
	}

    
	if (lives<=0) 
	{
		start=0; 
		
		sprawdz_wynik();
		
		done2=true; 
	}
		
	if (ballY<-13) {sty=-sty; start=0; lives--; ballX=0;	ballY=-3;}
    if (ballY>11) sty=-sty;

    if (ballX<-15) stx=-stx;
    if (ballX>15) stx=-stx;
}