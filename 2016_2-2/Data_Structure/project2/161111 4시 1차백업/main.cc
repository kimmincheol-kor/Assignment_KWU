#include "Manager.h"

int main(void){
	cout.setf(ios::fixed);
	cout.precision(2);

	int bpOrder = 3;

	Manager ds(bpOrder);
	ds.run("command.txt");

	return 0;
}

bool compare( pair< pair< double, int>, StudentData* > a, pair< pair< double, int>, StudentData* > b ){
	if( a.first.first == b.first.first){
		return a.first.second > b.first.second;
	}else{
		return a.first.first < b.first.first;
	}
}