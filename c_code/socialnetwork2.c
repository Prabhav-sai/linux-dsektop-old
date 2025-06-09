#include <stdio.h>
#include <string.h>

/*Declaring a structure for each member of the social Network */

typedef struct Person {
    char name[100];
    int age;
    int count_friends;
    struct Person *friends[5];
} Person;

/* Structure corresponding to the Social Network */

typedef struct SocialNet {
    Person members[100];
    int size;
} SocialNet;


/*Function to print the Name, age, Friends and Total no of friends of a member*/

void print_person(Person p) {
    printf(
        "----------------------------------------------\n"
        "Name: %s\tAge: %d\nFriends: \t", p.name, p.age);
    for(int i = 0; i < p.count_friends; i++) {
        printf("%s ", (p.friends[i])->name);
    }
   printf("\t Total Friends: %d", p.count_friends); 
   printf("\n");
}


int main()
{
    SocialNet sn;   	/*New variable sn of type Social Net */
    sn.size = 0;
    int d;
         
  
    strcpy(sn.members[0].name, "Alice");
    sn.members[0].age = 24;
    strcpy(sn.members[1].name, "Bob");
    sn.members[1].age = 22;
    strcpy(sn.members[2].name, "Charlie");
    sn.members[2].age = 28;
    strcpy(sn.members[3].name, "Dorothy");
    sn.members[3].age = 26;
    strcpy(sn.members[4].name, "Eve");
    sn.members[4].age = 30;
    sn.size=5;
    
    sn.members[0].friends[0] = &sn.members[2];
    sn.members[0].friends[1] = &sn.members[3];
    sn.members[0].friends[2] = &sn.members[4];
    sn.members[0].count_friends=3;

   
    sn.members[1].friends[0] = &sn.members[2];
    sn.members[1].count_friends=1;
   
    sn.members[2].friends[0] = &sn.members[3];
    sn.members[2].count_friends=1;

  sn.members[3].count_friends=0;
  sn.members[4].count_friends=0;  	
	

  /* If A is a friend of B, then B must also be a friend of A ---------------Incomplete --- improve later. */
	
	for(int j=0;j<sn.size;j++)
	{
	for(int k=0;k<sn.members[j].count_friends;k++)
		{
		   for(int l=j+1;l<sn.size;l++)
			{
			
			       if(sn.members[j].friends[k]==&sn.members[l])		
				{
					d=sn.members[l].count_friends;
					sn.members[l].friends[d]=&sn.members[j];
					sn.members[l].count_friends++;
				
				}	
			}
		 }
	}
		
		
    for (int i=0;i <sn.size; i++)
        print_person(sn.members[i]);

   
    return 0;

/*What about mutual friends of any two members? Try this at home. */
}