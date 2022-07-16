#include<dos.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
int i,j,l,p,n,k,x[12],y[12],b[12],h[12],v[12];
char a,c[9][16]={"==","====","======","========","==========","============",
                   "=============="};
clrscr();textmode(2);textcolor(1);textbackground(0);randomize();
gotoxy(13,3);printf("Nombre de disque: ");scanf("%d",&n);
gotoxy(13,4);printf("Pilier final(1…3):");scanf("%d",&p);
gotoxy(13,5);printf("Etat d‚but al‚atoire?  ");a=getch();printf("%c",a);
_setcursortype(_NOCURSOR);h[1]=0;h[2]=0;h[3]=0;
/* -------------- affichage des disques au depart -------------------- */;
for(i=1;(i<=n);i++)
{
if (a=='n') {x[i]=1;y[i]=i;}
else {x[i]=random(3)+1;y[i]=h[x[i]]+1;h[x[i]]=y[i];}
gotoxy(x[i]*20-(n-i),20-y[i]);cprintf("%s",c[n-i]);
}
b[1]=p;k=0;gotoxy(p*20,21);printf("^^");
delay(3000);
for(;(k==0);)
{
for(l=1;(l<=n);l++)
 {
/* ------------ recalcul de h[1],h[2],h[3] et v[1],v[2],v[3] ----------- */;
h[1]=0;h[2]=0;h[3]=0;v[1]=0;v[2]=0;v[3]=0;
for(i=1;(i<=3);i++)
{
for(j=1;(j<=n);j++) {if ((x[j]==i)&&(y[j]>h[i])) {h[i]=y[j];v[i]=j;} }
}
/* ------------algorithme de deplacement sur le disque l ------------- */;
if (x[l]==b[l]) {b[l+1]=b[l];}
              else {
if ((y[l]==h[x[l]])&&(l>v[b[l]]))
{
textcolor(0);gotoxy(x[l]*20-(n-l),20-y[l]);cprintf("%s",c[n-l]);
x[l]=b[l];y[l]=h[x[l]]+1;b[l+1]=x[l];
textcolor(1);gotoxy(x[l]*20-(n-l),20-y[l]);cprintf("%s",c[n-l]);
delay(800);
}
  else {b[l+1]=6-x[l]-b[l];}
                   }
 }
for(k=99,i=1;(i<=n);i++) {if (x[i]!=p) {k=0;} }
}
delay(800);
}
