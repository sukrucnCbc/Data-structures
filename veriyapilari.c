#include<stdio.h>
#include<conio.h>
#define MAX 10 // Changing this value will change length of array
int kuyruk[MAX];
int on = -1, son = -1;
void ekle(void);
int delete_element(void);
int peek(void);
void display(void);
void TersCevir(void);
int val;
int main()
{
int option, val;
do
{
printf("\n\n ***** Ana MENU *****");
printf("\n 0. KUYRUGUN ELEMANLARINI TERS CEVIR");
printf("\n 1. Eleman ekleme");
printf("\n 2.Eleman Silme");
printf("\n 3. Peek");
printf("\n 4. Kuyrugu Gosterme");
printf("\n 5. EXIT");
printf("\n Birini secin : ");
scanf("%d", &option);
switch(option)
{
case 1:
ekle();
break;
case 2:
val = delete_element();
if (val != -1)
printf("\n The number deleted is : %d", val);
break;
case 3:
val = peek();
if (val != -1)
printf("\n The first value in kuyruk is : %d", val);
break;
case 4:
display();
        break;
case 0:
    TersCevir();
break;
}
}while(option != 5);
getch();
return 0;
}
void ekle()
{  
int num;
printf("\n Enter the number to be ekleed in the kuyruk : ");
scanf("%d", &num);
if(son == MAX-1)  printf("\n OVERFLOW");
else if(on == -1 && son == -1)
on = son = 0;
else
son++;
kuyruk[son] = num;
}
int delete_element()
{
if(on == -1 || on>son)
{
printf("\n UNDERFLOW");
return -1;
}
else
{
val = kuyruk[on];
on++;
if(on > son)
on = son = -1;
return val;
}
}
int peek()
{
if(on==-1 || on>son)
{
printf("\n kuyruk IS EMPTY");
return -1;
}
else
{
return kuyruk[on];
}
}
void display()
{
int i;
printf("\n");
if(on == -1 || on > son)
printf("\n kuyruk IS EMPTY");
else
{
for(i = on;i <= son;i++)
printf("\t %d", kuyruk[i]);
}
}
void TersCevir(){
    if(on == -1 || on > son)
        printf("\n kuyruk IS EMPTY");
    else {
        int sonGecici = 0;
        int geciciKuyruk[MAX];
        for (int i = son; i >= on; i--) {
            geciciKuyruk[sonGecici] = kuyruk[i];
            sonGecici++;
        }
        for (int i = on; i < sonGecici + 1; ++i) {
            kuyruk[i] = geciciKuyruk[i];
        }
        printf("KUYRUK ELEMANLARI TERS CEVRILDI \n ");
    }
}