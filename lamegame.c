//test1.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A goofy project I created in two days to help me learn C.
// Maybe one day i'll make something of this.
void startup(void);
void characterMaker(void);
void colorChanger(void);

int main(void){
	colorChanger();
	startup();
	characterMaker();
	return 0;
}

void startup(void){
	// Variable Defining & General Matienance
	char name[20];


	printf("\n\n\n\nYou have been summoned. The great king of <LAND> demands your attention. \n");
	printf("But first, let's clear a few things up. What is your name, wanderer?\n: ");
	scanf("%s",&name);
	printf("The light shines brightly on you, %s. Welcome.\n\n",name);
}

void colorChanger(void){
	usleep(100000);
	system("COLOR 0F");
	usleep(100000);
	system("COLOR 01");
	usleep(100000);
	system("COLOR 02");
	usleep(100000);
	system("COLOR 03");
	usleep(100000);
	system("COLOR 04");
	usleep(100000);
	system("COLOR 05");
	usleep(100000);
	system("COLOR 06");
	usleep(100000);
	system("COLOR 0F");
}
void characterMaker(void){
	// Initialization
	char race[10];
	char class[10];
	int hp = 10;
	int attack = 5;
	int mana = 5;
	int sneak = 5;
	int speech = 5;
	// Character Race
	printf("{Please select your character from the list below. Type it exactly as it appears}\n");
	printf("{Argonian, Bosmer, Dunmer, Khajiit, Human, Orc}\n: ");
	scanf("%s",&race);
	
	if (strcmp(race,"Argonian") == 0)
	{
		printf("Your bright scales shine in the light as you awaken from your deep slumber.");
		hp = 11;
		sneak = 7;
		mana = 2;
		attack = 7;
		speech = 3;
	}
	else if (strcmp(race, "Bosmer") == 0)
	{
		hp = 7;
		sneak = 6;
		mana = 6;
		attack = 4;
		speech = 6;
		printf("Your eyes slowly open as you hear the feral instincts within you scream.");
	}
	else if (strcmp(race, "Dunmer") == 0)
	{
		hp = 7;
		sneak = 7;
		mana = 9;
		attack = 2;
		speech = 4;
		printf("You are reminded of your darkened past, covered in fire. The nightmare drives you out of your slumber.");
	}
	else if (strcmp(race, "Khajiit") == 0)
	{
		hp = 5;
		sneak = 9;
		mana = 3;
		attack = 6;
		speech = 7;
		printf("You awake from your power nap, ready to make more riches and assassinate those who attempt to stop you.");
	}
	else if (strcmp(race,"Human") == 0)
	{
		hp = 8;
		sneak = 5;
		mana = 5;
		attack = 5;
		speech = 9;
		printf("Feelings of regret, hatred, and fear of the other races drive you to your awakening.");
	}
	else if (strcmp(race,"Orc") == 0)
	{
		hp = 15;
		sneak = 2;
		mana = 1;
		attack = 8;
		speech = 2;
		printf("As the flashbacks to your rough upbringing haunt your mind, you awake in a cold sweat.");
	}
	else
	{
		printf("Your quest ends here. You soon fall into an eternal slumber. {Wrong Race Name}\n\n");
		exit(0);
	}


	// Begin the Class Selection. (Switching to switch cases & numerical selection?)
	printf("\n\nAs you awake, they realize that they are no longer where they first fell asleep.\n");
	printf("\nYou look around, and soon realize that you are in a mystical room full of writings.\n");
	printf("\nTo the left, you see 4 pedestals illuminated by light.\n");
	printf("\nThere are words above each pedestal indicating that this will determine how you begin this journey.\n");
	printf("\n{Please choose: Warrior, Mage, Thief, Wanderer}\n: ");
	scanf("%s",&class);
	if (strcmp(class, "Warrior") == 0)
	{
		printf("You feel the immense strength within you suddenly awakening to its full potential.");
		printf("\n{+1 attack, -1 mana}\n");
		mana = mana - 1;
		attack = attack + 1;
	}
	else if (strcmp(class, "Mage") == 0)
	{
		printf("Magical prowess and the arts of the unknown world fill your body and circle throughout your veins.");
		printf("\n{+2 Mana, -1 Attack, -1HP}\n");
	}
	else if (strcmp(class, "Thief") == 0)
	{
		printf("Theft is yet another form of art. You suddenly feel more nimble, and less clumsy.");
		printf("\n{+1 Speech, +1 Sneak, -1 Mana, -1 HP}\n");
	}
	else if (strcmp(class,"Wanderer") == 0)
	{
		printf("You are brave to choose this path, wanderer. You will start with nothing, but end up with everything.");
		printf("\n{-1 HP, -2 Attack, -1 Magicka, -1 Sneak, +4 Speech}\n");
	}
	else
	{
		printf("You are a fool for not choosing your path. You die instantly wheree you stand.\n\n");
		exit(1);
	}
	sleep(10);
}