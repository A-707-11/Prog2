#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

typedef struct {
	char title[20];
	char album[20];
	char singer[20];
	char composer[20];
	int recording_co_id;
	int year;
}songtype;

typedef struct node{
	songtype data;
	struct node* next;
}LIST;

void insertSongNode(LIST **head, songtype s);
void inputSongs(songtype s[]);
void recordSongs(songtype s);
void releaseSongs();
void updateTaylorSwiftSongs();
void display(LIST *head);
void line();

int main()
{
	FILE *ptr = fopen("songs.txt","wb");
	LIST *head = NULL;
	int i = 0;
	fclose(ptr);
	songtype s1[MAX];

	
	s1[0] = (songtype) {"STAY","OVER","Justine","Kid",10001,2012};
	s1[1] = (songtype) {"Wants and Needs","Scary Hours","Drake","Polo",10002,2021};
	s1[2] = (songtype) {"Easy On Me","Planet Her","Taylor Swift","Doja Cat",10003,2022};
	//inputSongs(s1);
	//inputSongs(s1);
	insertSongNode(&head, s1[0]);
	insertSongNode(&head, s1[1]);
	insertSongNode(&head, s1[2]);
	
	while(head != NULL && i < MAX)
	{
		recordSongs(s1[i]);
		
		i++;
		head = head->next;
	}
	

	
	releaseSongs();
	updateTaylorSwiftSongs();
	
}

void inputSongs(songtype s[])
{
	int i;
	
	for(i = 0; i < MAX; i++)
	{
		printf("Enter Title: ");
		gets(s[i].title);
		printf("Enter Album: ");
		gets(s[i].album);
		printf("Enter Singer: ");
		gets(s[i].singer);
		printf("Enter Composer: ");
		gets(s[i].composer);
		printf("Enter Recording ID: ");
		scanf("%d", &s[i].recording_co_id);
		printf("Enter Year: ");
		scanf("%d", &s[i].year);
		fflush(stdin);
		printf("\n");
	}

}

void insertSongNode(LIST **head, songtype s)
{
	LIST *newNode = malloc(sizeof(LIST));
	
	if(newNode != NULL)
	{
		newNode->data = s;
		newNode->next = *head;
		*head = newNode;
	}
	
}

void recordSongs(songtype s)
{
	FILE *ptr;

	ptr = fopen("songs.txt","ab");
	fwrite(&s,sizeof(songtype),1,ptr);

	fclose(ptr);
}

void releaseSongs()
{
	LIST *newHead = NULL;
	songtype y;
	int i, count = 0;
	
	FILE *ptr = fopen("songs.txt","rb");
	
	while(fread(&y,sizeof(songtype),1,ptr) == 1)
	{
		insertSongNode(&newHead, y);
	}
	
	
	printf("\tREAD_SONGS_FILE\n\n");
	while(newHead != NULL)
	{
		printf("          Song Title: %s\n", newHead->data.title);
		printf("               Album: %s\n", newHead->data.album);
		printf("              Singer: %s\n", newHead->data.singer);
		printf("            Composer: %s\n", newHead->data.composer);
		printf("Recording Company Id: %d\n", newHead->data.recording_co_id);
		printf("       Year Released: %d\n", newHead->data.year);
		printf("\n");
		newHead = newHead->next;
	}
	
	fclose(ptr);
}

void updateTaylorSwiftSongs()
{
	LIST *newHead2 = NULL;
	LIST *current;
	songtype songs[MAX];
	int i;
	FILE *ptr = fopen("songs.txt","rb");
	
	fread(songs,sizeof(songtype),5,ptr);
	
	insertSongNode(&newHead2, songs[0]);
	insertSongNode(&newHead2, songs[1]);
	insertSongNode(&newHead2, songs[2]);	
    
	line();
    printf("\tTAYLOR_SWIFT_READ_1\n\n");
	display(newHead2);
	
	current = newHead2;
	while(current != NULL)
	{
		if(strcmp(current->data.singer,"Taylor Swift") == 0)
		{
			current->data.recording_co_id = 0;
			strcpy(current->data.album,"The Eras");
		}		
		current = current->next;
	}
	
	line();
	printf("\tTAYLOR_SWIFT_READ_2\n\n");
	display(newHead2);
	
	
	fclose(ptr);
}

void display(LIST *head)
{
	while(head != NULL)
	{
		printf("          Song Title: %s\n", head->data.title);
		printf("               Album: %s\n", head->data.album);
		printf("              Singer: %s\n", head->data.singer);
		printf("            Composer: %s\n", head->data.composer);
		printf("Recording Company Id: %d\n", head->data.recording_co_id);
		printf("       Year Released: %d\n", head->data.year);
		printf("\n");
		head = head->next;
	}
}

void line()
{
	printf("------------------------------------------------\n");
}
