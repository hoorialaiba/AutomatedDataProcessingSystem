// program to read output file made before in file_handling_out_1.cpp
// and creating another input file with same but modified data of ex-output now input file after processing it

#include<iostream>
#include<fstream>
#include <string>
#include<cmath>
#define intasci 48
using namespace std;

int power(int x, int y) {
	int i, n = 1;
	for (i = 0; i < y; i++) {
		n = n * x;
	}
	return n;
}

int get_h(string height) {
	int j, h = 0, i = 0, inch = 0;
	string x;
	/*for(j = 0; j < height.length(); j++) {
		if(height[j] >= '0'  &&  height[j] <= '9') {
			if(j==0) {  
			h = (height[j] - intasci) * 12;  
			}
			else if(height[j+1]>='0' && height[j+1]<='9') {
			h += (height[j] - intasci) * 10;  
			}
			else {  hooraan.txt
			
			h += height[j] - intasci;  
			}
		}
	}*/
	h = atof(height.c_str());
	h *= 12;
	j = height.find_first_of('\'');
	if(j > 0) {
		i = j+1;
	    height.erase(0,i);
	    inch = atof(height.c_str());
	    h += inch;
	}
	return h;
}

float get_l(string length) {
	float l = 0, dec = 0;
	int j = 0, num = 0, a = 0, k; 

	 l = stof(length);
	
	/*for(k = 0; k < length.length(); k++) {
		if(length[k] != '.'  &&  length[k] != ' ' ) {
			num += 1;
		}
		if(length[k]=='.' || length[k]==' ') {
			break;  
		}
	}
	a = num-1;
	for(k = 0; k < num; k++) {
		if(length[k] >= '0' && length[k] <= '9') {
			l += (length[k] - 48) * (power(10 , a)); 
			a -= 1;
		}
	}
	for(j = k + 1; j < k + 3; j++) {
		if(length[j] >= '0' && length[j] <= '9' && j == k + 1) {   
		    dec = (length[j] - 48) * 10; 
		}
		else if(length[j] >= '0' && length[j] <= '9') {  
		    dec = dec + (length[j] - 48);	
		}
	}
	dec = dec / 100.0;
	l += dec;*/
	l *= 12;
	return l;
}

int get_age_type(string age) {
	int j, num=0;
	for(j = 0; j < age.length(); j++) { // Task-5 - functions 5
		if(age[j] == ' ') {  
		    num++;  
		}
	}
	return num;
}

int get_type_1(string age, int num) {
	int x = 0, a = 0, age_y = 0, j;
	/*for(j = 0; age[j] != ' '; j++) {
		x++; 
	}
	a = x - 1;
	for(j = 0; age[j] != ' '; j++) {
		if(age[j] >= '0' && age[j] <= '9') {
			age_y += (age[j] - 48) * (power(10 , a)); 
			a -= 1;
		}
	}*/
	age_y = atof(age.c_str());
	age_y *= 365;
	return age_y;
}

int get_type_3(string age, int num) {
	int	x = 0, age_y = 0, a = 0, j, k, m;
	for(j = 0; j < age.length(); j++) {
		if(age[j] == ' ') {  
		    break;  
		}
		else {  
		    x++; 
		}
	}
	a = x - 1;
	for(j = 0; j < x; j++) {
		if(age[j] >= '0' && age[j] <= '9') {
			age_y += (age[j] - 48) * (power(10 , a)); 
			a -= 1;
		}
	}
	age_y *= 12;
	x = a = 0;
	for(k = j + 1; k < age.length(); k++) {
		if(age[k] == ' ') {  
		    break;  
		}
	}
	for(m = k + 1; m < age.length(); m++) {
			if(age[m] == ' ') { 
			    break;  
			} 
			else {  
			    x++;  
			}
	}
	a = x - 1;
	for(j = k; j < k + x + 1; j++) {
		if(age[j] >= '0' && age[j] <= '9') {
			age_y += ( (age[j] - 48) * (power(10 , a)) ); 
			a -= 1;
		}
	}
	age_y *= 30;
	return age_y;
}

int get_type_5(string age, int num) {
	int x = 0, age_y = 0, a = 0, j, k, m;
	for(j = 0; j < age.length(); j++) {
		if(age[j] == ' ') {  
		    break;  
		}
		else {  
		    x++; 
		}
	}
	a = x - 1;
	for(j = 0; j < x; j++) {
		if(age[j] >= '0' && age[j] <= '9') {
			age_y += (age[j] - 48) * (power(10 , a)); 
			a -= 1;
		}
	}
	age_y *= 12;
	x = a = 0;
	for(k = j + 1; k < age.length(); k++) {
		if(age[k] == ' ') {  
		    break;  
		}
	}
	for(m = k + 1; m < age.length(); m++) {
		if(age[m] == ' ') { 
		    break;  
		}
		else {  
		    x++;  
		}
	}
	a = x - 1;
	for(j = k; j < k + x + 1; j++) {
		if(age[j] >= '0' && age[j] <= '9') {
			age_y += ( (age[j] - 48) * (power(10 , a)) ); 
			a -= 1;
		}
	}
	age_y *= 30;
	m = x = a = 0;
	for(m = j; m < age.length(); m++) {
		if(age[m] >= '0' && age[m] <= '9') {
			x++;
		}
	}
	a = x - 1;
	for(m = j; m < age.length(); m++) {
		if(age[m] >= '0' && age[m] <= '9') {
			age_y += ((age[m] - 48) * (power(10 , a))); 
			a -= 1;
		}
	}
		
	return age_y;
}

int main()
{
	string c, s, name, age, height, length, file1, file2;
	int  n, i, k, j, age_y, h, num = 0, x = 0, m;
	double l, a, dec = 0; // Task-3 code formatting
	
	cout << "Input file name you want to read : ";
	cin >> file1;
	//cin.sync();
	//cin.clear();
	//cin.get();
	cin.ignore(); 
	ifstream inputf;
	inputf.open(file1.c_str());
	if (inputf.is_open()) {
        cout << "File is opened." << endl;
        // You can perform read operations on the file here.
    } else {
        cout << "File is not opened." << endl;
    }
	  
	//file to be read
	
	file2 = ".output" + file1; 
	file1 = file2;
	ofstream outputf(file1.c_str());
		if (outputf.is_open()) {
        cout << "File2 is opened." << endl;
        // You can perform read operations on the file here.
    } else {
        cout << "File2 is not opened." << endl;
    }  
	//output file
	getline(inputf, c);
	
	n = ( static_cast<int>(c[0]) ) - '0' ; // int 48 == '0' char '0'
	for(i = 0; i < n; i++) {
		getline(inputf, name);

		getline(inputf, age);
		num = get_age_type(age);
		
		if(num == 1) {
			age_y = get_type_1(age, num);
		}
		if(num == 3) {
			age_y = get_type_3(age, num);
		}
		if(num == 5) {
			age_y = get_type_5(age, num);
		}
		
		getline(inputf, height);
		h = get_h(height);
			
		getline(inputf, length);
		l = get_l(length);
		
		outputf << name << "  " << age_y << " Days"<< "  " << h << " inch" << "  " << l << " inch" << "\n"; 
	}
    outputf.close();
    inputf.close();
	return 0;
}

