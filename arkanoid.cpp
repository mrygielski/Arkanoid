

#include <windows.h>	
#include <gl\gl.h>	
#include <time.h>


#include "_include\api_.h"
#include "_include\bmp_.h"
#include "_include\variables_.h"
#include "_include\class_.h"
#include "_include\levels_.h"
#include "_include\fps_.h"
#include "_include\other_.h"
#include "_include\fonts_.h"
#include "_include\procedure_.h"
#include "_include\init_.h"


void DrawGLScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	

	glTranslatef(0,0,-30);


	ShowText();

	ShowSky();

	glPushMatrix();	
	
	for (i=0; i<ilosc_blokow; i++)	blok[i].Block(blok[i].x,blok[i].y,0,3.3f,1,1,texture[blok[i].type]);
	
	player.Block(move_x-0.5f,-11,0,5,1,1,texture[0]);


	BallPsyhisc();



	glPushMatrix();


	Ball(ballX,ballY,ballZ,texture[4]); 

    glPopMatrix();
	
	glPopMatrix();
}


void DrawGLMenu(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	

	glTranslatef(0,0,-30);


//	ShowText();

	ShowMenu();

	glPushMatrix();	
	
	glPushMatrix();

    glPopMatrix();
	
	glPopMatrix();
}



int WINAPI WinMain(	HINSTANCE	hInstance,
					HINSTANCE	hPrevInstance,
					LPSTR		lpCmdLine,
					int			nCmdShow)
{
 /*   Tscore[0]=0;
	Tscore[1]=0;
	Tscore[2]=0;
	Tscore[3]=0;
	Tscore[4]=0;
	Tscore[5]=0;
	Tscore[6]=0;
	Tscore[7]=0;
	Tscore[8]=0;
	Tscore[9]=0;
	Tscore[10]=0;

	plik = fopen ("score.dat","w");

	fwrite(&Tscore,sizeof(Tscore),1,plik);

	fclose(plik);
	// zerowanie pliku
	*/

	plik = fopen ("score.dat","r");

	fread(&Tscore,sizeof(Tscore),1,plik);

	fclose(plik);


	if (CreateGLWindow("ARKANOID v1.0",640,480,16,fullscreen)==FALSE) return 0;

	InitTextures();

	InitGame();




	menu_texture=7;
	while(!done)
	{if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)){if (msg.message==WM_QUIT){done=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}else
	
	{
		if (keys[VK_UP]) menu_texture=7;
		if (keys[VK_DOWN]) menu_texture=6;
		
		DrawGLMenu();
		Draw_FPS();


		if (keys[VK_RETURN] && (menu_texture==7))	//uruchamianie gry
		{

				InitTextures();

				InitGame();
				
				Level(1);

				done2=false;

				while(!done2)
				{if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)){if (msg.message==WM_QUIT){done2=TRUE;}else{TranslateMessage(&msg);DispatchMessage(&msg);}}else
				
				{
					DrawGLScene();
					Draw_FPS();

					SwapBuffers(hDC);

					
					move_x=((float)mouseX/25)-12.3;


					if (ilosc_b==0 && level==1) 
					{
						start=0; 
						for (i=0; i<48; i++) blok[i].RESET();
						Level(2);			
						ballX=0;
						ballY=-3;
						ballZ=0;
						level++;
					}

					if (ilosc_b==0 && level==2) 
					{
						start=0; 
						done2=true;
						
						sprawdz_wynik();
					}
					

					

					for (i=0; i<ilosc_blokow; i++) if (blok[i].rotate_start)blok[i].RotateBlock(blok[i].rotate_where);

				
					if (keys[VK_ESCAPE])
					{
						done2=TRUE;
					
						sprawdz_wynik();
					}
				
				}}

		}



		SwapBuffers(hDC);

		if (keys[VK_RETURN] && (menu_texture==6)) // wyjscie
		{
			done=TRUE;
					
		}
		
	}}

	KillGLWindow(); 
	return (msg.wParam);
}