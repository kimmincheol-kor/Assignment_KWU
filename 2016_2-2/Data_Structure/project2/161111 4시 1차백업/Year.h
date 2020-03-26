#ifndef _YEAR_H_
#define _YEAR_H_

#include "StudentData.h"

class Freshman : public StudentData
{
private:
	char CProgramming[3]; 
	char Calculus[3]; 
	char IntroToComputer[3];

public:
	Freshman(){};
	virtual ~Freshman(){};

	void setGrade(char* a, char* b, char *c){
		strcpy(CProgramming, a);
		strcpy(Calculus, b);
		strcpy(IntroToComputer, c);
	}

	void printGrade(){
		cout<<"C Programming : "<<CProgramming<<endl;
		cout<<"Calculus : "<<Calculus<<endl;
		cout<<"Intro To Computer : "<<IntroToComputer<<endl;
	}
};

class Sophomore : public StudentData
{
private:
	char AdvancedProgramming[3];
	char DigitalLogicCircuits[3];
	char DataStructure[3];

public:
	Sophomore(){};
	virtual  ~Sophomore(){};

	void setGrade(char* a, char* b, char *c){
		strcpy(AdvancedProgramming, a);
		strcpy(DigitalLogicCircuits, b);
		strcpy(DataStructure, c);
	}

	void printGrade(){
		cout<<"Advanced Programming : "<<AdvancedProgramming<<endl;
		cout<<"Digital Logic Circuits : "<<DigitalLogicCircuits<<endl;
		cout<<"DataStructure : "<<DataStructure<<endl;
	}
};


class Junior : public StudentData
{
private:
	char ComputerArchitecture[3];
	char SystemProgramming[3];
	char OperatingSystem[3]; 

public:
	Junior(){};
	virtual  ~Junior(){};

	void setGrade(char* a, char* b, char *c){
		strcpy(ComputerArchitecture, a);
		strcpy(SystemProgramming, b);
		strcpy(OperatingSystem, c);
	}

	void printGrade(){
		cout<<"Computer Architecture : "<<ComputerArchitecture<<endl;
		cout<<"System Programming : "<<SystemProgramming<<endl;
		cout<<"Operating System : "<<OperatingSystem<<endl;
	}
};

class Senior :public StudentData
{
private:
	char CapstoneDesign[3];
	char Database[3]; 
	char ImageProcessing[3]; 

public:
	Senior(){};
	virtual  ~Senior(){};
	
	void setGrade(char* a, char* b, char *c){
		strcpy(CapstoneDesign, a);
		strcpy(Database, b);
		strcpy(ImageProcessing, c);
	}

	void printGrade(){
		cout<<"Capstone Design : "<<CapstoneDesign<<endl;
		cout<<"Database : "<<Database<<endl;
		cout<<"Image Processing : "<<ImageProcessing<<endl;
	}
};

#endif