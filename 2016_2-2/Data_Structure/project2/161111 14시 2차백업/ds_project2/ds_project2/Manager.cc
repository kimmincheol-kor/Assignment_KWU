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
		
	if(!fin){ // fail to open file
		fout<<"[ERROR] command file open error!"<<endl;
		return;
	}

	char*	str=NULL;
	char	buf[128]={0};
	char	buf2[128]={0};

	fout << ">> Program Start <<" << endl;
	while(fin.getline(buf, 64)){
		strcpy(buf2, buf);
		str=strtok(buf, " ");	
		
		if(strcmp(str, "LOAD") == 0){
			if(load == 1){
				printErrorCode(100);
			}else if((str=strtok(NULL, " \n")) != NULL || !LOAD()){
				printErrorCode(100);
			}
			else{
				fout << "======== LOAD= ========" << endl;
				fout << "Success" << endl;
				fout << "=======================" << endl;
			}
			load = 1; // flag : load complete.
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
		else if (strcmp(str, "EXIT") == 0) {
			fout << ">> EXIT <<" << endl << endl;
		}
		else
			fout << "Wrong Command" << endl << endl;
		fout<<endl;
	}
	fin.close();
}

bool Manager::LOAD(){
	char*	str=NULL;
	char	buf[128]={0};
	char	buf2[128]={0};

	ifstream fin;
	fin.open("grade_list.txt");
	
	if(!fin){ // fail to open file
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
		
		// insert to tree
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
	if(!avl->Rank())		return false;
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