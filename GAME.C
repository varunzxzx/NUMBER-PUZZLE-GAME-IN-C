/*############################################
  #					     #
  #		NUMBER PUZZLE		     #
  #		  by VARUN 		     #
  #					     #
  #	  http://noobsvilla.blogspot.com     #
  #					     #
  #		________________	     #
  #	Uploaded on github.com/varunzxzx     #
  ############################################*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct cood{
		int top;
		int right;
		int left;
		int down;
	}c[50][50];
int tmp[15],a[15];
int check(int);
int put();
int box();
int cur_pos();
int getkey();
int get_pos1(int,int);
int get_pos2(int,int);
int get_pos3(int,int);
int get_pos4(int,int);
void main()
{
	int i,r,j;
	clrscr();
	randomize();
	for(i=0,j=0;i<15;)
	{
		r=rand()%16;
		if(check(r)==0)
		{
			a[i]=r;
			tmp[j]=r;
			i++;j++;
		}
	}
	box();
	put();
	gotoxy(34,14);
	cur_pos();
}
int check(int r)
{
	int i;
	for(i=0;i<16;i++)
	{
		if(tmp[i]==r)
			return 1;
	}
	return 0;
}
int box()
{
	int i;
	for(i=22;i<37;i++)
	{
		gotoxy(i,9);
		cprintf("-");
	}
	for(i=22;i<37;i++)
	{
		gotoxy(i,11);
		cprintf("-");
	}
	for(i=22;i<37;i++)
	{
		gotoxy(i,13);
		cprintf("-");
	}
	return 0;
}
int put()
{
	int i,j;
	for(i=22,j=0;i<35,j<4;i=i+4,j++)
	{
		gotoxy(i,8);
		printf("%d",a[j]);
	}
	for(i=22;i<35,j<8;i=i+4,j++)
	{
		gotoxy(i,10);
		printf("%d",a[j]);
	}
	for(i=22;i<35,j<12;i=i+4,j++)
	{
		gotoxy(i,12);
		printf("%d",a[j]);
	}
	for(i=22;i<35,j<15;i=i+4,j++)
	{
		gotoxy(i,14);
		printf("%d",a[j]);
	}
	gotoxy(20,17);
	puts("NOTE: Use Arrow Keys To Shift Numbers");
	gotoxy(15,20);
	puts("Press ESC to exit...");
	return 0;
}
int cur_pos()
{
	int ch,x=34,y=14;
	set_pos();
	while(1)
	{
		ch=getkey();
		if(ch==80)
		{
			if(c[x][y].top==0)
				continue;
			printf("%d",c[x][y].top);
			get_pos1(x,y);
			y=y-2;
			gotoxy(x,y);
			cprintf("  ");
			gotoxy(x,y);
		}
		else if(ch==72)
		{
			if(c[x][y].down==0)
				continue;
			printf("%d",c[x][y].down);
			get_pos2(x,y);
			y=y+2;
			gotoxy(x,y);
			cprintf("  ");
			gotoxy(x,y);
		}
		else if(ch==77)
		{
			if(c[x][y].left==0)
				continue;
			printf("%d",c[x][y].left);
			get_pos3(x,y);
			x=x-4;
			gotoxy(x,y);
			cprintf("  ");
			gotoxy(x,y);
		}
		else if(ch==75)
		{
			if(c[x][y].right==0)
				continue;
			printf("%d",c[x][y].right);
			get_pos4(x,y);
			x=x+4;
			gotoxy(x,y);
			cprintf("  ");
			gotoxy(x,y);
		}
		else
			break;
	}
	return 0;
}
int get_pos1(int x,int y)
{
	if(c[x][y].left!=0)
	{
		c[x-4][y].right=c[x][y].top;
	}
	if(c[x][y].right!=0)
	{
		c[x+4][y].left=c[x][y].top;
	}
	if(c[x][y].down!=0)
	{
		c[x][y+2].top=c[x][y].top;
	}
	if(c[x][y].top!=0)
	{
		c[x][y-2].down=c[x][y].top;
	}
	return 0;
}
int get_pos2(int x,int y)
{
	if(c[x][y].left!=0)
	{
		c[x-4][y].right=c[x][y].down;
	}
	if(c[x][y].right!=0)
	{
		c[x+4][y].left=c[x][y].down;
	}
	if(c[x][y].down!=0)
	{
		c[x][y+2].top=c[x][y].down;
	}
	if(c[x][y].top!=0)
	{
		c[x][y-2].down=c[x][y].down;
	}
	return 0;
}
int get_pos3(int x,int y)
{
	if(c[x][y].left!=0)
	{
		c[x-4][y].right=c[x][y].left;
	}
	if(c[x][y].right!=0)
	{
		c[x+4][y].left=c[x][y].left;
	}
	if(c[x][y].down!=0)
	{
		c[x][y+2].top=c[x][y].left;
	}
	if(c[x][y].top!=0)
	{
		c[x][y-2].down=c[x][y].left;
	}
	return 0;
}
int get_pos4(int x,int y)
{
	if(c[x][y].left!=0)
	{
		c[x-4][y].right=c[x][y].right;
	}
	if(c[x][y].right!=0)
	{
		c[x+4][y].left=c[x][y].right;
	}
	if(c[x][y].down!=0)
	{
		c[x][y+2].top=c[x][y].right;
	}
	if(c[x][y].top!=0)
	{
		c[x][y-2].down=c[x][y].right;
	}
	return 0;
}
int set_pos()
{
	c[22][8].top=0;         	//c[22][8]={0,a[1],0,a[4]};
	c[22][8].right=a[1];
	c[22][8].left=0;
	c[22][8].down=a[4];
	c[26][8].top=0;                  //c[26][8]={0,a[2],a[0],a[5]};
	c[26][8].right=a[2];
	c[26][8].left=a[0];
	c[26][8].down=a[5];
	c[30][8].top=0;                  //c[30][8]={0,a[3],a[1],a[6]};
	c[30][8].right=a[3];
	c[30][8].left=a[1];
	c[30][8].down=a[6];
	c[34][8].top=0;			//c[34][8]={0,0,a[2],a[7]};
	c[34][8].right=0;
	c[34][8].left=a[2];
	c[34][8].down=a[7];
	c[22][10].top=a[0];	       //c[22][10]={a[0],a[5],0,a[8]};
	c[22][10].right=a[5];
	c[22][10].left=0;
	c[22][10].down=a[8];
	c[26][10].top=a[1];		//c[26][10]={a[1],a[6],a[4],a[9]};
	c[26][10].right=a[6];
	c[26][10].left=a[4];
	c[26][10].down=a[9];
	c[30][10].top=a[2];	       //c[30][10]={a[2],a[7],a[5],a[10]};
	c[30][10].right=a[7];
	c[30][10].left=a[5];
	c[30][10].down=a[10];
	c[34][10].top=a[3];		//c[34][10]={a[3],0,a[6],a[11]};
	c[34][10].right=0;
	c[34][10].left=a[6];
	c[34][10].down=a[11];
	c[22][12].top=a[4];		//c[22][12]={a[4],a[9],0,a[12]};
	c[22][12].right=a[9];
	c[22][12].left=0;
	c[22][12].down=a[12];
	c[26][12].top=a[5];		//c[26][12]={a[5],a[10],a[8],a[13]};
	c[26][12].right=a[10];
	c[26][12].left=a[8];
	c[26][12].down=a[13];
	c[30][12].top=a[6];		//c[30][12]={a[6],a[11],a[9],a[14]};
	c[30][12].right=a[11];
	c[30][12].left=a[9];
	c[30][12].down=a[14];
	c[34][12].top=a[7];		//c[34][12]={a[7],0,a[10],0};
	c[34][12].right=0;
	c[34][12].left=a[10];
	c[34][12].down=0;
	c[22][14].top=a[8];		//c[22][14]={a[8],a[13],0,0};
	c[22][14].right=a[13];
	c[22][14].left=0;
	c[22][14].down=0;
	c[26][14].top=a[9];		//c[26][14]={a[9],a[14],a[12],0};
	c[26][14].right=a[14];
	c[26][14].left=a[12];
	c[26][14].down=0;
	c[30][14].top=a[10];		//c[30][14]={a[10],0,a[13],0};
	c[30][14].right=0;
	c[30][14].left=a[13];
	c[30][14].down=0;
	c[34][14].top=a[11];		//c[34][14]={a[11],0,a[14],0};
	c[34][14].right=0;
	c[34][14].left=a[14];
	c[34][14].down=0;
	return 0;
}
int getkey()
{
	int ch;
	ch=getch();
	if(ch==0)
	{
		ch=getch();
		return ch;
	}
	return ch;
}

