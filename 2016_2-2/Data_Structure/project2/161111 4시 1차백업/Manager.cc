#include "Manager.h"

Manager::Manager(int bpOrder){
	fout.open("log.txt", ios::app);
	avl = new AVLTree(&fout);
	bp = new BpTree(&fout, bpOrder);	
}

Manager::~Manager(){
	delete avl;
	delete bp;
	fout.close();
}

void Manager::run(const char* command_txt){
	ifstream fin;		fin.open(command_txt);
	int	load = -1;
		
	if(!fin){
		fout<<"[ERROR] command file open error!"<<endl;
		return;
	}

	char*	str=NULL;
	char	buf[128]={0};
	char	buf2[128]={0};

	while(fin.getline(buf, 64)){
		strcpy(buf2, buf);
		str=strtok(buf, " ");	
		
		if(strcmp(str, "LOAD") == 0){
			if(load == 1){
				printErrorCode(100);
			}else if((str=strtok(NULL, " \n")) != NULL || !LOAD()){
				printErrorCode(100);
			}
			load = 1;
		}
		else if(strcmp(str, "SEARCH_AVL") == 0){
			if(SEARCH_AVL(strtok(NULL, "\n")) == false)
				printErrorCode(300);
		}
		else if(strcmp(str, "SEARCH_BP") == 0){
			double a = atof(strtok(NULL, " "));
			double b = atof(strtok(NULL, " "));
			int c = atoi(strtok(NULL, " "));
			if (SEARCH_BP(a, b, c) == false)
				printErrorCode(200);
		}
		else if(strcmp(str, "RANK") == 0){
			if (RANK() == false)
				printErrorCode(400);
		}
		else if(strcmp(str, "PRINT_AVL") == 0){
			if (PRINT_AVL() == false)
				printErrorCode(600);
		}
		else if(strcmp(str, "PRINT_BP") == 0){
			if (PRINT_BP() == false)
				printErrorCode(500);
		}
		fout<<endl;
	}	
	fin.close();
}

bool Manager::LOAD(){
	/* 아래 작성된 코드는 이용 또는 삭제, 변경이 가능함 -- 과제 제출 시 본 주석 삭제*/
	char*	str=NULL;
	char	buf[128]={0};
	char	buf2[128]={0};

	ifstream fin;
	fin.open("grade_list.txt");
	
	if(!fin){
		return false;
	}
		
	while(fin.getline(buf, 64)){
		StudentData* pStu;
		strcpy(buf2, buf);

		str=strtok(buf, " ");
		str=strtok(NULL, " ");
		str=strtok(NULL, " ");
			
		if(strcmp(str, "1") == 0){
			pStu = new Freshman();	
		}else if(strcmp(str, "2") == 0){
			pStu = new Sophomore();
		}else if(strcmp(str, "3") == 0){
			pStu = new Junior();
		}else if(strcmp(str, "4") == 0){
			pStu = new Senior();
		}

		str=strtok(buf2, " ");
		pStu->setStudentID(atoi(str));
		str=strtok(NULL, " ");
		pStu->setName(str);
		str=strtok(NULL, " ");
		pStu->setYear(atoi(str));
		pStu->setAvgGrade(strtok(NULL, " "), strtok(NULL, " "), strtok(NULL, " "));
		
		avl->Insert(pStu);
		bp->Insert(pStu);
	}
	return true;
}

bool Manager::SEARCH_AVL(char* name){
	if(!avl->Search(name))	return false;
	else							return true;
}

bool Manager::SEARCH_BP(double a, double b, int year){
	if(!bp->Search(a, b, year))			return false;
	else											return true;
}

bool Manager::RANK(){
	if(avl->Rank())		return false;
	else					return true;
}

bool Manager::PRINT_AVL(){
	if(!avl->Print())	return false;
	else					return true;
}

bool Manager::PRINT_BP(){
	if(!bp->Print())		return false;
	else					return true;
}

void Manager::printErrorCode(int n){
	fout<<"======== ERROR ========"<<endl;
	fout<<n<<endl;
	fout<<"======================="<<endl;
}