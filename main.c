/*
Welcome to the "THE SCRABBLE GAME" made by Sakshi Mittal.
     
Overview of the project:
    This project asks the user to enter a heap of letters and then checks in the dictionary (which is already sorted according to the lengths of the words in it) that if there is any word which can be formed out of the given heap of letters. If yes, the program calculates it's score. And the process goes on.The word with the best score is stored in the variable, "bestword". If no word can be formed out of the heap of letters, the compiler simply shows that no word can be formed.
Thank You !!
*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
int countnumber=0, score=-1000,s=0,v,good,bad,mult;
char bestword[9];
char temp[9];int x,h,u,r,no,star=0;;
struct node
{
    	char ch;
 	struct node *next;
};
struct node *top=NULL;
void push(char v)							
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	assert(ptr!=NULL);
	ptr->ch=v;
	if(top==NULL)
	{
		ptr->next=NULL;
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
}
char pop()								
{
	struct node *ptr;
	ptr=top;
	if(top==NULL)
		printf("Stack underflow");
	else
	{
		top=top->next; 
		return(ptr->ch);
	}
}
int calscore(char word[],int length,int r)			// Function to calculate the score of the word formed out of the heap of letters
{
    int weight=0-r;
    for(int q=0; word[q]!='\0';q++)				// Calculation of weight
    {
        if(word[q]=='E' || word[q]=='A' || word[q]=='I' || word[q]=='O' || word[q]=='N' || word[q]=='R' || word[q]=='L' || word[q]=='T' || word[q]=='S' || word[q]=='U')
            weight+=1;
        if(word[q]=='D' || word[q]=='G')
            weight+=2;
        if(word[q]=='B' || word[q]=='C' || word[q]=='M' || word[q]=='P')
            weight+=3;
        if(word[q]=='F' || word[q]=='H' || word[q]=='V' || word[q]=='W' || word[q]=='Y')
            weight+=4;
        if(word[q]=='K')
            weight+=5;
        if(word[q]=='J' || word[q]=='X')
            weight+=8;
        if(word[q]=='Q' || word[q]=='Z')
            weight+=10;
    }
    good=(s-1)*length;						// Calculation of value of good, bad and mult
    v=3*(s+1-length);
    if(v>1)
        bad=v;
    else 
        bad=1;
    mult=good-bad;
    if(weight*mult>score)
    {
        score=weight*mult;
	printf("%s	%d \n", word,score);
        strcpy(bestword,word);
    }
    
}
int check(char charac)							
{   
	int j;
        for(int i=0;temp[i]!='\0';i++)				// Here, temp stores the word scanned from the file by the compiler. And, charac stores the letters being popped out of the heap of letters. 
        {
		if(temp[i]==charac)
		{						// As the charac matches with any letter in temp, we are removing that character from temp to keep a track of the letters which don't match.
			    for( j=i;temp[j]!='\0';j++)
			    {
	                    	temp[j]=temp[j+1];
			    }
			
			    temp[j]='\0'; break;
		}
	}
}
int checkthedictionary(char heap[],int star)
{
    FILE *fp;
    if(s>=2)
    {
	char scanned[2];
	fp=fopen("2.txt","r");
	strcpy(scanned," ");
	while(!feof(fp))
	{
		

		no=star;
		r=0;
		strcpy(temp,scanned);
		 for(u=0;heap[u]!='\0';u++)
			push(heap[u]);
		while(top!=NULL)
        	{
                	char alpha=pop();
        		check(alpha);
		}
		if(temp[0]=='\0')				// The scanned word can be formed out of the heap of letters
		{
			countnumber++;
			calscore(scanned,2,r);
		}
		else if(temp[0]=='A'||temp[0]=='E'||temp[0]=='I'||temp[0]=='O'||temp[0]=='U')
		{
			for(h=0;temp[h]!='\0'&& no>=0;)
			{
				no--;
			
				if(temp[h]=='A'||temp[h]=='E'||temp[h]=='I'||temp[h]=='O'||temp[h]=='U')
				{
					r++;
					for(x=h;temp[x]!='\0';x++)
			    		{
	                    			temp[x]=temp[x+1];
			    		}
					temp[x]='\0';
				
				}
			
			
			}
			if(no>=0 && temp[0]=='\0')		// The scanned word can be formed out of the heap of letters but is formed only after using * as a vowel
			{
				countnumber++;
				calscore(scanned,2,r);
			}
		}
		fscanf(fp,"%s",scanned);
	}
	fclose(fp);
    }
    if(s>=3)
    {
	char scanned[3];
	fp=fopen("3.txt","r");
	strcpy(scanned," ");
	while(!feof(fp))
	{
		

		no=star;
		r=0;
		strcpy(temp,scanned);
		 for(u=0;heap[u]!='\0';u++)
			push(heap[u]);
		while(top!=NULL)
        	{
                	char alpha=pop();
        		check(alpha);
		}
		if(temp[0]=='\0')				// The scanned word can be formed out of the heap of letters
		{
			countnumber++;
			calscore(scanned,3,r);
		}
		else if(temp[0]=='A'||temp[0]=='E'||temp[0]=='I'||temp[0]=='O'||temp[0]=='U')
		{
			for(h=0;temp[h]!='\0'&& no>=0;)
			{
				no--;
			
				if(temp[h]=='A'||temp[h]=='E'||temp[h]=='I'||temp[h]=='O'||temp[h]=='U')
				{
					r++;
					for(x=h;temp[x]!='\0';x++)
			    		{
	                    			temp[x]=temp[x+1];
			    		}
					temp[x]='\0';
				
				}
			
			
			}
			if(no>=0 && temp[0]=='\0')			// The scanned word can be formed out of the heap of letters but is formed only after using * as a vowel
			{
				countnumber++;
				calscore(scanned,3,r);
			}
		}
		fscanf(fp,"%s",scanned);
	}
	fclose(fp);
    }
    if(s>=4)
    {
	char scanned[4];
	fp=fopen("4.txt","r");
	strcpy(scanned," ");
	while(!feof(fp))
	{
		

		no=star;
		r=0;
		strcpy(temp,scanned);
		 for(u=0;heap[u]!='\0';u++)
			push(heap[u]);
		while(top!=NULL)
        	{
                	char alpha=pop();
        		check(alpha);
		}
		if(temp[0]=='\0')				// The scanned word can be formed out of the heap of letters
		{
			countnumber++;
			calscore(scanned,4,r);
		}
		else if(temp[0]=='A'||temp[0]=='E'||temp[0]=='I'||temp[0]=='O'||temp[0]=='U')
		{
			for(h=0;temp[h]!='\0'&& no>=0;)
			{
				no--;
			
				if(temp[h]=='A'||temp[h]=='E'||temp[h]=='I'||temp[h]=='O'||temp[h]=='U')
				{
					r++;
					for(x=h;temp[x]!='\0';x++)
			    		{
	                    			temp[x]=temp[x+1];
			    		}
					temp[x]='\0';
				
				}
			
			
			}
			if(no>=0 && temp[0]=='\0')			// The scanned word can be formed out of the heap of letters but is formed only after using * as a vowel
			{
				countnumber++;
				calscore(scanned,4,r);
			}
		}
		fscanf(fp,"%s",scanned);
	}
	fclose(fp);
    }
    if(s>=5)
    {
	char scanned[5];
	fp=fopen("5.txt","r");
	strcpy(scanned," ");
	while(!feof(fp))
	{
		

		no=star;
		r=0;
		strcpy(temp,scanned);
		 for(u=0;heap[u]!='\0';u++)
			push(heap[u]);
		while(top!=NULL)
        	{
                	char alpha=pop();
        		check(alpha);
		}
		if(temp[0]=='\0')				// The scanned word can be formed out of the heap of letters
		{
			countnumber++;
			calscore(scanned,5,r);
		}
		else if(temp[0]=='A'||temp[0]=='E'||temp[0]=='I'||temp[0]=='O'||temp[0]=='U')
		{
			for(h=0;temp[h]!='\0'&& no>=0;)
			{
				no--;
			
				if(temp[h]=='A'||temp[h]=='E'||temp[h]=='I'||temp[h]=='O'||temp[h]=='U')
				{
					r++;
					for(x=h;temp[x]!='\0';x++)
			    		{
	                    			temp[x]=temp[x+1];
			    		}
					temp[x]='\0';
				
				}
			
			
			}
			if(no>=0 && temp[0]=='\0')				// The scanned word can be formed out of the heap of letters but is formed only after using * as a vowel
			{
				countnumber++;
				calscore(scanned,5,r);
			}
		}
		fscanf(fp,"%s",scanned);
	}
	fclose(fp);
    }
    if(s>=6)
    {
	char scanned[6];
	fp=fopen("6.txt","r");
	strcpy(scanned," ");
	while(!feof(fp))
	{
		

		no=star;
		r=0;
		strcpy(temp,scanned);
		 for(u=0;heap[u]!='\0';u++)
			push(heap[u]);
		while(top!=NULL)
        	{
                	char alpha=pop();
        		check(alpha);
		}
		if(temp[0]=='\0')				// The scanned word can be formed out of the heap of letters
		{
			countnumber++;
			calscore(scanned,6,r);
		}
		else if(temp[0]=='A'||temp[0]=='E'||temp[0]=='I'||temp[0]=='O'||temp[0]=='U')
		{
			for(h=0;temp[h]!='\0'&& no>=0;)
			{
				no--;
			
				if(temp[h]=='A'||temp[h]=='E'||temp[h]=='I'||temp[h]=='O'||temp[h]=='U')
				{
					r++;
					for(x=h;temp[x]!='\0';x++)
			    		{
	                    			temp[x]=temp[x+1];
			    		}
					temp[x]='\0';
				
				}
			
			
			}
			if(no>=0 && temp[0]=='\0')			// The scanned word can be formed out of the heap of letters but is formed only after using * as a vowel
			{
				countnumber++;
				calscore(scanned,6,r);
			}
		}
		fscanf(fp,"%s",scanned);
	}
	fclose(fp);
    }
    if(s>=7)
    {
	char scanned[7];
	fp=fopen("7.txt","r");
	strcpy(scanned," ");
	while(!feof(fp))
	{
		

		no=star;
		r=0;
		strcpy(temp,scanned);
		 for(u=0;heap[u]!='\0';u++)
			push(heap[u]);
		while(top!=NULL)
        	{
                	char alpha=pop();
        		check(alpha);
		}
		if(temp[0]=='\0')				// The scanned word can be formed out of the heap of letters
		{
			countnumber++;
			calscore(scanned,7,r);
		}
		else if(temp[0]=='A'||temp[0]=='E'||temp[0]=='I'||temp[0]=='O'||temp[0]=='U')
		{
			for(h=0;temp[h]!='\0'&& no>=0;)
			{
				no--;
			
				if(temp[h]=='A'||temp[h]=='E'||temp[h]=='I'||temp[h]=='O'||temp[h]=='U')
				{
					r++;
					for(x=h;temp[x]!='\0';x++)
			    		{
	                    			temp[x]=temp[x+1];
			    		}
					temp[x]='\0';
				
				}
			
			
			}
			if(no>=0 && temp[0]=='\0')				// The scanned word can be formed out of the heap of letters but is formed only after using * as a vowel
			{
				countnumber++;
				calscore(scanned,7,r);
			}
		}
		fscanf(fp,"%s",scanned);
	}
	fclose(fp);
    }
    if(s>=8)
    {
	char scanned[8];
	fp=fopen("8.txt","r");
	strcpy(scanned," ");
	while(!feof(fp))
	{
		

		no=star;
		r=0;
		strcpy(temp,scanned);
		 for(u=0;heap[u]!='\0';u++)
			push(heap[u]);
		while(top!=NULL)
        	{
                	char alpha=pop();
        		check(alpha);
		}
		if(temp[0]=='\0')					// The scanned word can be formed out of the heap of letters
		{
			countnumber++;
			calscore(scanned,8,r);
		}
		else if(temp[0]=='A'||temp[0]=='E'||temp[0]=='I'||temp[0]=='O'||temp[0]=='U')
		{
			for(h=0;temp[h]!='\0'&& no>=0;)
			{
				no--;
			
				if(temp[h]=='A'||temp[h]=='E'||temp[h]=='I'||temp[h]=='O'||temp[h]=='U')
				{
					r++;
					for(x=h;temp[x]!='\0';x++)
			    		{
	                    			temp[x]=temp[x+1];
			    		}
					temp[x]='\0';
				
				}
			
			
			}
			if(no>=0 && temp[0]=='\0')			// The scanned word can be formed out of the heap of letters but is formed only after using * as a vowel
			{
				countnumber++;
				calscore(scanned,8,r);
			}
		}
		fscanf(fp,"%s",scanned);
	}
	fclose(fp);
    }
    if(s>=9)
    {
	char scanned[9];
	fp=fopen("9.txt","r");
	strcpy(scanned," ");
	while(!feof(fp))
	{
		

		no=star;
		r=0;
		strcpy(temp,scanned);
		 for(u=0;heap[u]!='\0';u++)
			push(heap[u]);
		while(top!=NULL)
        	{
                	char alpha=pop();
        		check(alpha);
		}
		if(temp[0]=='\0')				// The scanned word can be formed out of the heap of letters
		{
			countnumber++;
			calscore(scanned,9,r);
		}
		else if(temp[0]=='A'||temp[0]=='E'||temp[0]=='I'||temp[0]=='O'||temp[0]=='U')
		{
			for(h=0;temp[h]!='\0'&& no>=0;)
			{
				no--;
			
				if(temp[h]=='A'||temp[h]=='E'||temp[h]=='I'||temp[h]=='O'||temp[h]=='U')
				{
					r++;
					for(x=h;temp[x]!='\0';x++)
			    		{
	                    			temp[x]=temp[x+1];
			    		}
					temp[x]='\0';
				
				}
			
			
			}
			if(no>=0 && temp[0]=='\0')			// The scanned word can be formed out of the heap of letters but is formed only after using * as a vowel
			{
				countnumber++;
				calscore(scanned,9,r);
			}
		}
		fscanf(fp,"%s",scanned);
	}
	fclose(fp);
    }
}
int main()
{
    char heap[50];
    printf("Enter the bag of letters: ");
    scanf("%[^\n]s", heap);
    for(int i=0; heap[i]!='\0';i++)
    {
        s++;						// s contains the total letters in the bag of letters given by the user
        if(heap[i]>='a' && heap[i]<='z')
            heap[i]-=32;
        if(heap[i]=='*')
            star++;
    }
    checkthedictionary(heap,star);
    if(countnumber>0)					// countnumber contains the number of words that can be formed from the given heap of letters.
    {
        printf("The total words that can be formed are: %d \n",countnumber);
        printf("The best word is: %s with the score: %d  \n", bestword, score);
    }
    else 
        printf("Sorry! No words can be formed.");
    return 0;
}



