#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;

typedef struct node
         { int data;
           struct node *next;
           } *list;
typedef struct node larik[101];

int s=0;

void BuatDataBeda(int x[101],int &n)
{ int i,j;bool ada;
  cout<<"banyak data : ";cin>>n;
  srand(time(NULL));
  for (i=1;i<=n;i++) {
    do {   
        x[i]=rand()%100+1;
        j=i-1;ada=false;
        while (j>=1){ 
           if (x[i]==x[j]) {
              ada=true;j=0;
           } else j--;
         }
     } while (ada);
     cout<<x[i]<<" ";
  }
}    

long prima(int N)
{long p;
 bool prima;
 do {
  if ((N==2)||(N==3)) prima=true;
  else if ((N%2==0)||(N<2)) prima=false;
       else
       { p=3;prima=true;
	      do {
	         if ((N%p)==0)  prima=false; else p=p+2;
	        }
	      while ( prima && p<=(sqrt(N)+1));
       }
   if (!prima) N++;    
 } while (!prima);
 return N;
}

void hashing(int X[101],int N)
{larik H;int IH,I,p,t;list Q,b;
  p=prima(N);
  for(int i=1;i<=p;i++) {
    H[i].data=0;H[i].next=NULL;
  }
  for(int i=1;i<=N;i++) {
      IH = X[i]%p+1;
      if (H[IH].data==0) H[IH].data=X[i];
      else {
        b=new node;b->data=X[i];b->next=NULL;
        if (H[IH].next==NULL) H[IH].next=b; 
        else {
           Q=H[IH].next;
           while (Q->next!=NULL) Q=Q->next;
           Q->next=b;
        }          
      }
   }
   cout<<endl;
   for (int I=1;I<=p;I++) {
     cout<<I<<"  "<<H[I].data<<" ";
     if (H[I].data!=0) s++;
     if(H[I].next!=NULL) {
       Q=H[I].next;t=2;
       while(Q!=NULL) {s+=t;t++;
         cout<<Q->data<<" "; Q=Q->next; 
         }   
     }
     cout<<endl;
  }
}

main()
{ int x[101],n;
  BuatDataBeda(x,n);
  cout<<endl;
  hashing(x,n);
  cout<<endl;
  cout<<"rata-rata : "<<(float)s/n;
  getch();
}


