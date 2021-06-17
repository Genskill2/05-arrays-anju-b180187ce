#include <stdio.h>
#include <assert.h>

float average(int [], int);
int factors(int, int []);
int max(int [], int);
int min(int [], int);
int mode(int [], int);

float average(int a[], int b){
  float avg=0;
  for(int i=0;i<b;i++){
      avg=avg + a[i];
  }
  avg = avg / b ;
  return avg;
}

int max(int a[], int b){
   int i;
 int max = a[0];
 for (i=1;i<b;i++){
    if ( max<a[i])
     {max=a[i];
     }
 }
 return max; 
}


int min(int a[], int b)
{
 int i;
 int min = a[0];
 for (i=1;i<b;i++){
    if ( min>a[i])
     {min=a[i];
     }
 }
 return min;
}

int mode(int a[], int b)
{
  int c=0;
       
   for (int i=0;i<b;i++)
   {  c=a[i];
       for(int j=i+1;j<b;++j)
       {
           if ( c>a[j])
             { a[i]=a[j]; 
                a[j]=c;
                c=a[i] ;  }
       }
       
   }
    
  int count = 1 ;
  int y[] = {0,0,0,0,0,0,0,0,0,0,0,0};
  
  int d= a[0];
  for(int i=1;i<b;i++)
   { 
    if(a[i]==d)
      {
       count++;
       
      }
    else
      { y[i]=count;
       count =1;
       d=a[i];
       
      }

   }
  int pos=0; 
  int max = y[0];
  for (int i=1;i<b;i++)
   {
    if ( max<y[i])
     {max=y[i];
       pos=i-1;
     }
   } 
  return a[pos]; 
}

int factors(int n, int r[])
{
    int prime[n];
    int k=-1; 
     
   for (int j=1;j<n;j++) 
   {   
     int num =j;
     int p=0;
     for(int i=2;i<=num/2;i++)
     {
       if(num%i==0)
       {   p=1;
           break;}
       
     }
   if(p==0)
     {prime[k++]=j;}
   
   }
  int a=n;
  int z=-1;
  for(a;a>1;)
  {  for(int i=0;i<=k;i++)
    {  
      if(a%prime[i]==0)
      { z++; 
        r[z]=prime[i];
        a=a/prime[i];
        break;
        
      }
    }
  }
z++; 
return z;
}


