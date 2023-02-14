#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>

int score=0,chance=3,level=1;
int lineX=300,lineX2=350;
int ballX=215,ballY=190;


char str[10];
char lev[10];
char cnc[10];
int moveBall()
{
    int i=4;
    if(chance<1) return 1;
    else
    {
        sprintf(cnc," %d ",chance);
        sprintf(lev,"%d ",level);
        sprintf(str," %d ",score);

        ballY+=i;
        if((ballX+15>= lineX  &&  ballX-15 <= lineX2 && ballY>=360 && ballY<=365))
        {

            score++;
            ballX=rand()%460+90;
            ballY=180;
            if(score>=5 && score<10)
            {
                i=7;
               level=2;
            }
            else if(score>=10)
            {
                i=10;
                level=3;
            }
            else level=1;


        }
        else if(ballY>=367)
        {
            chance--;
            ballX=rand()%460+90;
            ballY=180;
        }

    }

    return 0;
}



void GameBody()
{
    setfillstyle(SOLID_FILL,3);
    floodfill(0,0,5);

    setcolor(14);
    settextstyle(9,0,3);   //font,direction,font_size);
    // https://www.geeksforgeeks.org/settextstyle-function-c/
    outtextxy(220,30," Catch The Ball ");

    settextstyle(3,0,2);
    setcolor(7);
    outtextxy(215,385," Press ' Esc ' to Exit ");

    settextstyle(3,0,2);
    setcolor(13);
    outtextxy(460,116," Score : ");
    outtextxy(525,116,str);

    outtextxy(90,116," Level : ");
    outtextxy(155,116,lev);

    outtextxy(260,116," Chance : ");
    outtextxy(335,116,cnc);

    setcolor(1);
    setlinestyle(3,3,4);  //(linestyle, upattern, thickness);
    rectangle(90,140,550,380);

    setcolor(5);
    setfillstyle(SOLID_FILL,10);
    circle(ballX,ballY,15);
    floodfill(ballX,ballY,5);

    setcolor(14);
    line(lineX,365,lineX2,367);
}

int moveLine()
{
    char ch;
    int j=10;
    if(kbhit())  // https://www.cprogramming.com/fod/kbhit.html
    {
        ch=getch();
        switch(ch)
        {
        case 27:
            return 1;
        case 75:
            if(lineX>90)
            {
                if(score==5)j+=1;
                else if(score==10)j+=2;
                lineX-=j;
                lineX2-=j;
            }
            break;
        case 77:
            if(lineX2<550)
            {
                if(score>=5 && score<10)j+=1;
                else if(score==10)j+=2;
                lineX+=j;
                lineX2+=j;
            }
            break;
        }
        }
        return 0;
    }


int main()
{
    int gd=DETECT,gm,end=0,end2=0,i=0;
    char ch;

    system("cls");
    initgraph(&gd,&gm,"");//initgraph initialize graphical system
    restart:
        end=0;
    while(1)
    {
        GameBody();
        end=moveBall();
        end2=moveLine();

        delay(80);
        cleardevice();
        if(i>=1000) i=100;
        else i+=100;
        if(end==1  || end2==1) break;
    }
    cleardevice();
    setcolor(4);
    settextstyle(10,0,6);
    outtextxy(180,160," GAME END ");
    setcolor(14);
    settextstyle(10,0,4);
    outtextxy(240,210," SCORE ");
    sprintf(str," %d",score);
    outtextxy(360,210,str);
    setcolor(7);
    settextstyle(10,0,2);
    outtextxy(140,300," IF YOU WANT TO PLAY AGAIN THEN ");
    outtextxy(180,330," PRESS 'Y' OTHERWISE 'N' ");
    renter:
        ch=getch();
        if(ch=='y' || ch=='Y')
        {
            chance=3,score=0;
            lineX=280,lineX2=330;
            ballX=rand()%460+90,ballY=190;
            goto restart;
        }
        else if(ch=='n' || ch=='N')
        {
            exit(0);
        }
        else
        {
            setcolor(2);
            outtextxy(230,400," ENTER VALID KEY ");
            goto renter;
        }
        getch();
        closegraph();

    return 0;
}

