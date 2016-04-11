

int Ball(float x, float y, float z, int texture)
{
	glTranslatef(x,y,z);

	glBindTexture(GL_TEXTURE_2D, texture);
	gluSphere(ball,0.3f,16,16);

	return true;
}

int RandomBall()
{
	randomize();
	rx = Random(0,19);

	if (rx==0) stx=0.12f;
	if (rx==1) stx=0.14f;
	if (rx==2) stx=0.16f;
	if (rx==3) stx=-0.12f;
	if (rx==4) stx=-0.14f;
	if (rx==5) stx=-0.16f;
	
	if (rx==6) stx=0.18f;
	if (rx==7) stx=0.20f;
	if (rx==8) stx=0.22f;
	if (rx==9) stx=-0.22f;
	if (rx==10) stx=-0.20f;
	if (rx==11) stx=-0.18f;

	if (rx==11) stx=0.23f;
	if (rx==12) stx=0.24f;
	if (rx==13) stx=0.25f;
	if (rx==14) stx=-0.25f;
	if (rx==15) stx=-0.24f;
	if (rx==16) stx=-0.23f;
	if (rx==17) stx= 0.3f;
	if (rx==18) stx=-0.3f;


	sty=0.4f;

	return true;
}

int ballIN(float x, float y, float x1, float y1, float x2, float y2)
{
	if ((x>=x1) && (x<=x2) && (y>=y1) && (y<=y2)) return true; else return false;
}

int Rectangle(float x1, float y1, float z1, float x2, float y2, float z2,
              float x3, float y3, float z3, float x4, float y4, float z4, int texture)
{
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_TRIANGLE_STRIP);
	    glTexCoord2f(1,0);glVertex3f(x1,y1,z1);
	    glTexCoord2f(1,1);glVertex3f(x2,y2,z2);
	    glTexCoord2f(0,0);glVertex3f(x3,y3,z3);
	    glTexCoord2f(0,1);glVertex3f(x4,y4,z4);
    glEnd();
	return true;
}

int BLOCK::Block(float x1, float y1, float z1, float width, float height, float thickness, int texture)
{
	if (live<0 && !dead) {ilosc_b--; dead=true;}
	if (live>0 || godmode==true || live==1000)
	{
   
		if (ballIN(ballX,ballY-sty,x1-(width/2),y1-(height/2),x1+(width/2),y1+(height/2))) 
		{
			if (ballY<y1) {sty=-sty;}
			if (!godmode) {live-=6; score+=20;}
			{rotate_block=true; rotate_where=false;}
		}
		if (ballIN(ballX,ballY+sty,x1-(width/2),y1-(height/2),x1+(width/2),y1+(height/2))) 
		{
			if (ballY<y1+height) {sty=-sty;}
			if (!godmode) {live-=6; score+=20;}
			if (rxy>300) {RandomBall();rxy=0;}
			{rotate_block=true; rotate_where=false;}
		}
	    rxy++;

		if (ballIN(ballX-stx,ballY,x1-(width/2),y1-(height/2),x1+(width/2),y1+(height/2))) 
		{
			if (ballX<x1) {stx=-stx;}
			if (!godmode) {live-=6;score+=20;} 
			{rotate_block=true; rotate_where=false;}
		}
		if (ballIN(ballX+stx,ballY,x1-(width/2),y1-(height/2),x1+(width/2),y1+(height/2))) 
		{
			if (ballX<x1+width) {stx=-stx;}
			if (!godmode) {live-=6; score+=20;}
			{rotate_block=true; rotate_where=false;}
		}


		glPushMatrix();


		glTranslatef(0,y1,0);

		glRotatef(rott,1,0,0);

    
		glPushMatrix();
    
    

		glTranslatef(x1-(width/2),-(height/2),z1-(thickness/2)); 

	//	glEnable(GL_BLEND);
		glBlendFunc(1,GL_SRC_COLOR);
		glEnable(GL_BLEND); 
		glColor4ub(255,255,255,255);

		Rectangle(0,0,0, width, 0, 0,
				  0,0+height,0, width,0+height,0, texture);

		Rectangle(0,0,0+thickness, 0+width, 0, 0+thickness,
				  0,0+height,0+thickness, 0+width,0+height,0+thickness, texture);

		Rectangle(0,0+height,0, 0+width,0+height,0,
				  0,0+height,0+thickness, 0+width,0+height,0+thickness, texture);

		Rectangle(0,0,0, 0+width,0,0,
				  0,0,0+thickness, 0+width,0,0+thickness, texture);


		Rectangle(0,0,0, 0, 0, 0+thickness,
				  0, 0+height, 0, 0, 0+height, 0+thickness, texture);

		Rectangle(0+width,0,0, 0+width, 0, 0+thickness,
				  0+width, 0+height, 0, 0+width, 0+height, 0+thickness, texture);

		glDisable(GL_BLEND);

		
		glPopMatrix();

	   glPopMatrix();

	}

   return true;

}

int BLOCK::RotateBlock(bool up_down)
{
	if (rotate_block) 
	{
		ii++;
		speed_rotate-=speed_b*(float)0.01;

		if (up_down) if (rott<=360) rott+=speed_rotate; else rott=0; // gora
		if (!up_down) if (rott>=0) rott-=speed_rotate; else rott=360; // dol

		if (ii>100) {ii=0; speed_rotate=6; rotate_block=false;}
	}
	return true;
}

int BLOCK::RESET()
{
	rott=0;
	ii=0;
	speed_rotate=0;
	speed_b=0;
	x=0;
	y=0;;
	live=0;
	type=0;
	rotate_start=0;
	rotate_block=false;
	rotate_where=false;
	godmode=false;
	dead=false;
	return true;
}

void ShowSky()
{
	glBindTexture(GL_TEXTURE_2D, texture[5]);		
	glBegin(GL_QUADS);								
		glTexCoord2f(roll+0.0f, 0.0f); glVertex3f(-16.1f, -11.4f,  -1.0f);	
		glTexCoord2f(roll+4.0f, 0.0f); glVertex3f( 16.1f, -11.4f,  -1.0f);	
		glTexCoord2f(roll+4.0f, 4.0f); glVertex3f( 16.1f,  11.4f,  -1.0f);	
		glTexCoord2f(roll+0.0f, 4.0f); glVertex3f(-16.1f,  11.4f,  -1.0f);
	glEnd();							

	roll+=0.005f;										
	if (roll>1.0f)										
	{
		roll-=1.0f;										
	}

}

typedef int TYP;

void sortowanie( TYP a[], int n ) 
{
  int i,j;
  TYP tmp;
  bool change;

  for (i=0; i<n-1; i++) 
  {
       change=false;
       for (j=0; j<n-1-i; j++)
          if (a[j+1] < a[j])   
          {  
              tmp = a[j];      
              a[j] = a[j+1];
              a[j+1] = tmp;      
              change=true;
          }
       if(!change) break;     
  }
}


void ShowMenu()
{
	glBindTexture(GL_TEXTURE_2D, texture[menu_texture]);		
	glBegin(GL_QUADS);								
		glTexCoord2f(0, 0); glVertex3f(-17.1f, -13.1f,  -1.0f);	
		glTexCoord2f(1, 0); glVertex3f( 17.1f, -13.1f,  -1.0f);	
		glTexCoord2f(1, 1); glVertex3f( 17.1f,  13.1f,  -1.0f);	
		glTexCoord2f(0, 1); glVertex3f(-17.1f,  13.1f,  -1.0f);
	glEnd();							

	sortowanie(Tscore,11);

	for (i=0; i<10; i++) 
	{
		if (i>=9) piszTXT(-16, 6.3f-(i*1.55),1.5f,2,2,255,255,255,255,fonttext,"%d. %d",i+1,Tscore[10-i]);  
		  else piszTXT(-16, 6.3f-(i*1.55),1.5f,2,2,255,255,255,255,fonttext,"0%d. %d",i+1,Tscore[10-i]);
	}


}



void ShowText()
{
	start++;
	if (start<200 && lives>0) piszTXT(-4.7f,-11.5f,1.1f,1,1,255,255,255,255,fonttext,"GET READY!");  
	if (start<200 && lives<=0) piszTXT(-4.7f,-11.5f,1.1f,1,1,255,255,255,255,fonttext,"GAME OVER!");  

    piszTXT(-16, 12.1f,0.5f,1,1,255,255,255,255,fonttext,"score=%d record=%d",score,record);  
	piszTXT(-16,-11.5f,0.5f,1,1,255,255,255,255,fonttext,"lives=%d",lives);  

	if (score>record) record=score;
}