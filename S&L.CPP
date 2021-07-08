//by aditya-rk01
//date: 18-02-2021
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

char *tname[] = { "DEFAULT font",
  "TRIPLEX font",
  "SMALL font",
  "SANS SERIF font",
  "GOTHIC font"
};

char *lname[] = {
   "SOLID_LINE",
   "DOTTED_LINE",
   "CENTER_LINE",
   "DASHED_LINE",
   "USERBIT_LINE"
   };
char *fname[] = { "EMPTY_FILL",
  "SOLID_FILL",
  "LINE_FILL",
  "LTSLASH_FILL",
  "SLASH_FILL",
  "BKSLASH_FILL",
  "LTBKSLASH_FILL",
  "HATCH_FILL",
  "XHATCH_FILL",
  "INTERLEAVE_FILL",
  "WIDE_DOT_FILL",
  "CLOSE_DOT_FILL",
  "USER_FILL"
};

void ladder(int a,int b,int c,int d)
{
    int userpat=1;
    setlinestyle(DOTTED_LINE, userpat, 1);
    line(a,b,c,d);
    line(a+5,b,c+5,d);
    setlinestyle(SOLID_LINE, userpat, 1);
}

void alladder()
{
    setcolor(2);
    ladder(300,20,220,100);
    ladder(60,60,100,140);
    ladder(20,100,60,340);
    ladder(300,100,300,220);
    ladder(180,140,140,220);
    ladder(100,180,140,300);
    ladder(380,180,20,380);
    setcolor(255);
}

void snake()
{
   setcolor(100);
   line(300,380,340,20);
   line(60,380,140,140);
   line(100,340,60,100);
   line(340,340,380,220);
   line(260,260,340,100);
   line(60,220,20,60);
   line(260,180,300,20);
   setcolor(255);
}

void board()
{
   setbkcolor(8);
   int i,j,y,pts[]={450,100,600,100,600,200,450,200};
   char x[100];
   strcpy(x,"1");
   for(i=0;i<400;i=i+40)
   {
	for(j=0;j<400;j=j+40)
	{
		rectangle(j,i,j+40,i+40);
		outtextxy(j+20,i+20,x);
		y=atoi(x);
		y++;
		itoa(y,x,10);
	}
   }
   fillpoly(4,pts);
   setcolor(BLACK);
   settextstyle(3,HORIZ_DIR,2);
   outtextxy(455,125,"SNAKES AND");
   outtextxy(465,175,"LADDERS");
   settextstyle(0,HORIZ_DIR,1);
   alladder();
   snake();
}

void dice(int t)
{
      char str[100];
      itoa(t,str,10);
      rectangle(420,420,460,460);
      outtextxy(440,440,str);
}

void coin(int p)
{
      int x,y;
      if(p%10==0)
      {
	x=380;
	y=20+(((p/10)-1)*40);
      }
      else
      {
	x=20+(((p%10)-1)*40);
	y=20+((p/10)*40);
      }

      setcolor(BLUE);
      circle(x,y,10);
      setcolor(WHITE);
     // floodfill(x,y,BLUE);
}

int chckforsnakeladder(int p)
{
	switch(p)
	{
		//ladder
		case 8:	p=26;
			break;
		case 12:p=33;
			break;
		case 21:p=82;
			break;
		case 28:p=58;
			break;
		case 35:p=54;
			break;
		case 43:p=74;
			break;
		case 50:p=91;
			break;

		//snake
		case 98:p=9;
			break;
		case 92:p=34;
			break;
		case 89:p=60;
			break;
		case 83:p=22;
			break;
		case 67:p=29;
			break;
		case 52:p=11;
			break;
		case 47:p=9;
			break;
	};
	return p;
}
main()
{
   int gdriver = DETECT, gmode, errorcode;
   int x,y,d,play=1,temp=1,points[]={100,100,300,100,300,300,100,300};
   char ch;
   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "//TurboC3//bgi");

   /* read result of initialization */
   errorcode = graphresult();

   board();

   while(play!=100)
   {
      cin>>ch;
      if(ch=='p')
      {
	randomize();
	d=random(6)+1;
	temp+=d;
       /*	d=rand()%7;
	temp+=d;*/
      }
      else
      {
	exit(0);
      }
      if(temp>100)
      {
	temp-=d;
      }
      temp=chckforsnakeladder(temp);
      play=temp;
      clrscr();
      cleardevice();
      dice(d);
      board();
      /*
      while(temp<=play)
      {
	++temp;
	coin(temp);
      }
      */
      coin(play);
   }
   fillpoly(4,points);
   setcolor(BLACK);
   settextstyle(4,HORIZ_DIR,3);
   outtextxy(150,200,"WINNER");
   getch();
   closegraph();
   return 0;
}
