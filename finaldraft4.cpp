#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<limits>
#include<cctype>
#include <iomanip>
#include <cstdlib>
using namespace std;



void clear(){
		if (cin.fail()) {
    		cout << "\nInvalid input!\n";
    		cin.clear(); // clear error flag
    		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
    	}
}



//extract data from file and stores in array
void getdata(vector<string>&a, vector<string>&b,const string& filename){// extract data in txt file into array

	ifstream object(filename,ios::in);

	string line;
	while(getline(object,line)){
	size_t pos= line.find(":");
		if(pos != string::npos){

			string token1= line.substr(0,pos);
			string token2= line.substr(pos+1);

			a.push_back(token1);
			b.push_back(token2);

		}
	}
}



bool PasswordChecker(string &password){

    bool hasSymbol= false, hasDigit= false, hasLower=false, hasUpper=false;
    //bool pswdpass=false;

    if (password.find(':') != string::npos){//checks the password if it contains colons (:)
        cout<<"password must not have colon symbol (:)";
        return false;
    }

    if(password.length()<8 || password.length()>30){//varifies length of password
        cout<<"password must contain 8-30 characters";
        return false;
    }
    
    else{
        for (int i = 0; i < password.length(); i++) {//check every character of password
            char c = password[i];
            if (isupper(c)) hasUpper = true;
            else if (isdigit(c)) hasDigit = true;
            else if (ispunct(c)) hasSymbol = true;
            else if (islower(c)) hasLower  = true;
        }
    }
    //conditions that fail acceptation
    if (!hasUpper) {
        cout << "Password must contain at least 1 uppercase letter.\n";
        return false;
    }
    if (!hasLower) {
        cout << "Password must contain at least 1 lowercase letter.\n";
        return false;
    }
    if (!hasDigit) {
        cout << "Password must contain at least 1 number.\n";
        return false;
    }
    if (!hasSymbol) {
        cout << "Password must contain at least 1 symbol.\n";
        return false;
    }

    //varifies accepted input
    cout<<"\npassword accepted";
    cout<<"\npassword :"<<password;
    return true;

}

//validated username
bool usernamechecker(string &username){
    //colonchecker(username)
    
    if(username.length()<8 || username.length()>30){// validates username length
        cout<<"Username must contain 8-30 characters. ";
        return false;}

    for (int i = 0; i < username.length(); i++) {//checks every character of username
        char c = username[i];
        if(!isalnum(c)){
            cout<<"User name must only contain letters or numbers. ";
            return false;}
    }
    //varifies accepted input
    cout<<"\nUsername accepted";
    cout<<"\nUsername :"<<username;
    return true;
}























void login(bool &isLoggedIn){

	// creates variables
	string username, password;
	vector<string>usernames;
	vector<string>passwords;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');//aligns cursor

	//opens file
	ifstream logindata("udata.txt",ios::in);

	//gets login information
	cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);


	string logdata;
	//this while loop converst every username and passwords into 2 arrays
	while(getline(logindata,logdata)){

		size_t pos= logdata.find(":");//search for colon(:)
		if(pos != string::npos){//colon splits data 
			string username1= logdata.substr(0,pos);//left side is usernames
			string password1= logdata.substr(pos+1);//right side is password

			//stores data into array
			usernames.push_back(username1);//extract all usernames from file into 
			passwords.push_back(password1);

		}
	}
	// index remains -1 if input data does not mathch stored data
	int index=-1;
	//for loop compares input data and stored data
	for(int i=0; i<usernames.size(); i++){
		if(usernames[i]==username ){
			index =i;
			break;
		}
	}
	//informs that data does not match 
	if(index==-1)cout<<"Invalid username.";
	if(index!=-1 && password==passwords[index]){
		cout<<"Login verified : ";
		isLoggedIn =true;
	}
	else if(index!=-1){
		cout<<"wrong password. ";
		//cout<<password[index];
	}

	logindata.close();

}




void signup() {
    string username, password;
    vector<string>usernames;
	vector<string>passwords;

    cout<<"\nSIGN UP\n ";

    // Clear buffer (important if you used cin >> before)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //repeats loop unitil a name is accepted usernamee is input
	while (true) {
	    cout << "\nEnter Username: ";
	    getline(cin, username);

	    // load existing data
	    getdata(usernames, passwords, "udata.txt");

	    bool taken = false; // track if duplicate exists

	    for (int i = 0; i < usernames.size(); i++) {
	    	string usernames1 =usernames[i];
	        if (username == usernames1) {
	            cout << "Username already taken\n";
	            taken = true;
	            break;
	        }
	    }

	    if (taken) {
	        continue; // go back to ask again
	    }

	    if (usernamechecker(username)) {
	        break; // valid & unique → exit while loop
	    } else {
	        cout << "Invalid username!\n";
	    }
	}





    // repeats loop until an accepted password is input
    while (true) {
        cout << "\nEnter Password: ";
        getline(cin, password);
        if (PasswordChecker(password)) {
            break;
        } else {
            cout << "Try again\n";
        }
    }
    //opens file
    ofstream logindata("udata.txt", ios::app);
    //notify if file cant be open
    if (!logindata.is_open()) {
        cout << "Error: Could not open file!";
        return;
    }
    //writes down accepted userdata into file
    logindata << username << ":" << password << "\n";
    logindata.close();//close file

    cout << "\nSignup successful!\n";
    cout<<"\n now u can login. ";
}


//####################################################################################################################################################################################################################################################################
//####################################################################################################################################################################################################################################################################


//1
void intrduction(){
	cout<<"Welcome to out circuit theory fun little program.\n";
	cout<<"We chose circuit theory because it contains intersting easy mathemetical calculations.\n";
	cout<<"This program contains fun little activities that educates the user on circuit theory.\n";
	cout<<"WE have put great effort in creating this program.\n";
	cout<<"We hope you enjoy it. :)\n";

}

//2
void chapters(){
	cout<<"Here are the chapters in our circuit thoery UGEA124\n3";
	cout << "Chapter 1: Basic Laws & Circuit Analysis\n";
	cout << "1.1 Basic Concepts & Definitions\n";
	cout << "1.2 Circuit Elements\n";
	cout << "1.3 Sources\n";
	cout << "1.4 Circuit Notation\n";
	cout << "1.5 Kirchhoff's Law\n";
	cout << "1.6 Resistors Circuit\n";
	cout << "1.7 Delta-Wye Transformations\n\n";

	cout << "Chapter 2: Methods of Circuits Analysis\n";
	cout << "2.1 Branch-Current Analysis\n";
	cout << "2.2 Mesh Analysis\n";
	cout << "2.3 Nodal Analysis\n";
	cout << "2.4 Mesh with Current Sources\n";
	cout << "2.5 Nodal with Voltage Sources\n";
	cout << "2.6 Bridge Network\n";
	cout << "2.7 Mesh by Inspection\n";
	cout << "2.8 Nodal by Inspection\n\n";

	cout << "Chapter 3: Network Theorems\n";
	cout << "3.1 Superposition Theorem\n";
	cout << "3.2 Thevenin's Theorem\n";
	cout << "3.3 Norton's Theorem\n";
	cout << "3.4 Maximum Power Transfer Theorem\n\n";

	cout << "Chapter 4: Capacitors, Inductors and Mutual Inductance\n";
	cout << "4.1 Capacitors\n";
	cout << "4.2 Inductors\n";
	cout << "Transition from DC to AC\n\n";

	cout << "Chapter 5: Phasors & Sinusoidal Steady-State Analysis\n";
	cout << "5.1 Sinusoids & Phasors\n";
	cout << "5.2 Phasor relationships for R, L & C\n";
	cout << "5.3 Impedance & Admittance\n";
	cout << "5.4 Kirchhoff's Law in AC Circuit\n";
	cout << "5.5 AC Steady-State Analysis\n";
	cout << "5.6 Mutual Inductance and Transformer\n\n";

	cout << "Chapter 6: AC Power Analysis\n";
	cout << "6.1 Instantaneous & Average Power\n";
	cout << "6.2 Effective (rms) Value\n";
	cout << "6.3 Apparent Power & Power Factor\n";
	cout << "6.4 Complex Power & Power Triangular\n";
	cout << "6.5 Power Factor Correction\n";
	cout << "6.6 Balanced Three-Phase System\n";


}


//3
void activitydescription(){
	cout<<"\n\n        	    Activity 1: Interactive Quiz\n";
	cout<<"Develop a simple quiz that give the short but brief concept of Circuit Theory to students \n.In this quiz, there are 20 questions and each of the question are multiple choice question that allow user to select. \nThe topic content including ";
	cout<<"This quiz is designed for users to evaluate their understanding level to the course and boost student’s confidence level by setting a score system at the end of the quiz.\nThe biggest highlight of this program is display some of advices for student so they can have a better performances in Circuit Theory.";


	cout<<"\n\n              Activity 2: Resistor and Capacitor Calculator \n";
	cout<<"Resistors and capacitors are little devices that we use to design circuits\n";
	cout<<"Addition of resistors in parallel and series\n";
	cout<<"Addition of capacitors in parallel and series\n";
	cout<<"How to convert from base(Ohms or farads tp micro, millie,kilo and mega. Basic maths calculations\n";


	cout<<"\n\n              Activity 3: Ohm’s Law Calculator\n";
	cout<<"Develop a simple Ohm’s calculator that allow users to select the physical quantities such as Voltage, Current, and Resistance that they want to calculate. \nThe program should prompt the user’s instruction to input the value of Voltage, Current, and Resistance and showing the formula that is easy and understandable for users. \nAll the operation of the program is guided by the instruction we have display to prevent confusion to users.";


	cout<<"\n\n              Activity 4: Transformer Calculator\n";
	cout<<"Develop a simple Transformer calculator that allow users to select the primary voltage, secondary voltage, number of turns of the primary coils and number of secondary coils that they want to calculate.\n";
	cout<<"The program should prompt the user’s instruction to input the value of primary voltage, secondary voltage, number of turns of the primary coils and number of turns of the secondary coils and showing the formula that is easy and understandable for users.\n";
	cout<<"Other than that, the program will also showing the ratio of primary voltage to secondary voltage, ratio of secondary voltage to primary voltage, ratio of number of turns of the primary coils to number of turns of the secondary coils, and number of turns of the secondary coils to number of turns of the primary coils.\n";
	cout<<"All the operation of the program is guided by the instruction we have display to prevent confusion to users.\n";

}




//4------------------------------------------------------------------------




//store answer to file
void storedata(string a, int b){         

	ofstream logindata("scoresheet.txt", ios::app);
    	if (!logindata.is_open()) {
        	cout << "Error: Could not open file!";
        	return;
    	}

    logindata << a << ":" << b << "\n";
    logindata.close();


}


// load quizz questions and answers
void quizz(const string& filename1, const string& filename2, int &points){
	string choice;
	points =0;

	vector<string>question;
	vector<string>option;
	vector<string>answers;
	vector<string>explanation;

	getdata(question,option,filename1);//question file
	getdata(answers, explanation,filename2);//answer file

	//loop for 10 question
	for(int i=0; i <10;i++){

		cout<<"\n"<<question[i]<<"\n"<<option[i];
		cout<<"\nEnter choice :";
		getline(cin,choice);
		if(!choice.empty()){
			choice[0]= toupper(choice[0]);//capitalise input
		}


		if(choice ==answers[i]){
			cout<<"Correct. ";
			points+=1;
		}
		else{
			cout<<"wrong :";
		}

		cout<<"\ncorrect answer is "<<answers[i]<<", explanation ="<<explanation[i]<<"\n";
		
	}


}

//sums the final score
void sumscore(){

	int mcqscore=0;
	int tfscore=0;
	int sum =0;

	cout<<"\n#####################################";
	cout<<"\n#  WELCOME TO CIRCUIT THEORY QUIZZ  #";
	cout<<"\n#####################################\n";

	cout<<"\n#####################PART 1 MULLTIPLE CHOICE QUESTION #################################";
	quizz("mcqquestion.txt","mcqanswer.txt",mcqscore);//mcq 

	cout<<"\n\n\n";
	cout<<"#######################PART 2 TRUTH OR FALSE #############################################";
	quizz("tfquestions.txt","tfanswers.txt", tfscore);//true or false question

	sum =mcqscore+tfscore;
	cout<<"\nscore = "<<sum;
	string nickname;

    while (true) {
        cout<<"\nEnter nickname to store points";
        getline(cin, nickname);

        if (usernamechecker(nickname)) {
            break;
        } else {
            cout <<"name not accepted!\n";
        }
    }
	

	storedata(nickname,sum);





}

//display result
void showresult(){

	string username, password;
	vector<string>names;
	vector<string>points;

	ifstream scoredata("scoresheet.txt",ios::in);

	string line;
	//this while loop converst every username and passwords into 2 arrays
	while(getline(scoredata,line)){

		size_t pos= line.find(":");//exctract data friom file into array
		if(pos != string::npos){

			string username1= line.substr(0,pos);
			string point= line.substr(pos+1);

			names.push_back(username1);
			points.push_back(point);

		}
	}
	//display previouse results
	for(int i =0; i<names.size(); i++){
		cout<<"\n"<<names[i]<<"score ="<<points[i];
	}

	scoredata.close();

}

//main function that runs activity 2
void activity1(){
	int option;
	do{

		cout<<"\n1. START QUIZZ \n2. VIEW PAST RESULTS \n3. EXIT \nEnter choice:";
		clear();
		cin>>option;

		switch(option){

			case 1:
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//clears input
				sumscore();
				break;
			case 2:
				showresult();
				break;
			case 3:

				cout<<"exit";
				break;
            default:
                cout << "Invalid Input, 1-3 only.\n";

		}
		cout<<"\n";
	}while(option !=3);
}





//5-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void normal(const string &device,const string &symbol,const string &letter){

	vector<double> data;
	float value;
	double sum= 0;
	int amount;


	//loop to get valid amount of device
	while(true){
		cout<<"How many "<<device<<" ? :";
		cin>>amount;
		if(cin.fail()||cin.peek() != '\n' ||amount < 1){
			cout<<"Invalid input! \n";
		    cin.clear(); // reset fail state
        	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
		}
		else{
			break;
		}
	}

	cout<<"Enter values of "<<device<<" in series.7";
	for(int i=0;i<amount;i++){
		cout << "\nEnter amount in "<<symbol<<"\n"<<letter<< i+1 << " = ";//symbol in Farads or Ohms

		cin>>value;
		if (cin.fail()) {
    		cout << "\nInvalid input! Please enter a number.";
    		cin.clear(); // clar cin
    		cin.ignore(numeric_limits<streamsize>::max(), '\n');//reset cin
    		i--;
    	}
    	else{
    		sum += value;
    		data.push_back(value);
    	}
	}

	cout<<"\nCalculations: \n";
	cout<<device<<" total = ";
	for(int i=0;i<amount;i++){
		cout<<data[i];
		if(i+1 < amount){
			cout<<" + ";
		}
	}
	cout<<" = "<<sum;

}



void inverse(const string &device,const string &symbol,const string &letter){

	vector<double> data;
	float value;
	double sum= 0;
	int amount;


	//loop to get valid amount of device
	while(true){
		cout<<"How many "<<device<<" ? :";
		cin>>amount;
		if(cin.fail()||cin.peek() != '\n' ||amount < 1){
			cout<<"Invalid input! \n";
		    cin.clear(); // reset fail state
        	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
		}
		else{
			break;
		}
	}

	cout<<"Enter values of "<<device;
	for(int i=0;i<amount;i++){
		cout << "\nEnter amount in "<<symbol<<"\n"<<letter<< i+1 << " = ";//symbol in Farads or Ohms
		//cout << "\nEnter amount in \n"<<symbol<<letter<< i+1 << " = ";//symbol in Farads or Ohms
		cin>>value;
		if (cin.fail()) {
    		cout << "\nInvalid input! Please enter a number.";
    		cin.clear(); // clar cin
    		cin.ignore(numeric_limits<streamsize>::max(), '\n');//reset cin
    		i--;
    	}
    	else{
    		sum += 1/value;
    		data.push_back(value);
    	}
	}

	cout<<"\nCalculations: \n";
	cout<<device<<" total = 1/";
	for(int i=0;i<amount;i++){
		cout<<data[i];
		if(i+1 < amount){
			cout<<" + 1/";
		}
	}
	double inverse =pow(sum,-1);
	cout<<"\n"<<letter<<" = 1/"<<sum<<" = "<<inverse;

}











void conversioncalc(int choice){
	string type;
	double result, value, inbase;
	int from,to;

	do{
	string Reunits[] = { "Ohms (Ω)", "Milliohms (mΩ)", "Microohms (µΩ)", "Kiloohms (kΩ)", "Megaohms (MΩ)" };//Resistor units
    string capUnits[] = { "Farads(F)", "Millifarads(mF)", "Microfarads(µF)", "Kilofarads(kF)", "Megafarads(MF)" };//Capacitor units
    int powers[] = { 0, -3, -6, 3, 6 }; // conversion powers of 10
    //int power[] = { 0, -3, -6, 3, 6,};
    string *unitNames;

    if(choice ==1){
    	unitNames = Reunits;
    	type ="Resistor";
    }
    if(choice ==2){
    	unitNames=capUnits;
    	type ="Capacitor";
    }
    cout << "\n=== " << type << " Converter ===\n";
    for (int i = 0; i < 5; i++){
        cout << i + 1 << ". " << unitNames[i] << "\n";
    }
    cout << "6. Exit(6-6)\n";

    cout<<"\nFrom(1-5) :";
    cin>>from;
    cout<<"\nTo(1-5) :";
    cin>>to;
    if(from!=6 && to!=6){
	    cout<<"\nEnter value :";
	    cin>>value;    	
    }


    if (cin.fail()) {
		cout << "\nInvalid input! Please enter a number.\n";
		cin.clear(); // clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
		continue; // ask again
	}

    if(from>0 && from <6 && to>0 && to<6){//conversiont calculator
	    inbase = value * pow(10,powers[from-1]);
	    result = inbase / pow(10,powers[to-1]) ;

	    cout << fixed << setprecision(9);

	    cout<<value<<" "<<unitNames[from-1]<<" = "<<result<<" "<<unitNames[to-1];   	
    }
    else if(from==6 || to ==6)cout<<"Bye ";
    else cout<<"out of range. ";


	}while(from!=6 && to!=6);


}












void activity2(){

	string name,symbol,letter;
    int choice,choice2,choice3;
    do {
        cout << "\nActivity 2.\n";

        cout<<"\n1.ADD resistors \n2.ADD capacitors\n3.Convertion calculator \n4.Exit\nEnter choice : ";
        if (cin.fail()) {
    		cout << "\nInvalid input! Please enter a number.\n";
    		cin.clear(); // clear error flag
    		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
    		continue; // ask again
		}
        cin>>choice;

        switch(choice) {
            case 1:
            	cout<<"\n=======================Adding Resistors=====================\n";
            	name = "resistor";
				symbol = "Ω";
				letter = "R";

            	cout<<"\n\n1. parallel addition \n2. for series addition \nEnter choice :";
            	cin>>choice2;

            	if(cin.fail()) {
            		cin.clear();
            		cin.ignore(numeric_limits<streamsize>::max(), '\n');
            		cout << "\nInvalid input.\n";
            		break;
            	}
            	if(choice2 == 1){
            		inverse(name,symbol,letter);
            	}
            	else if(choice2 ==2){
            		normal(name,symbol,letter);
            	}
            	else{
            		cout<<"invalid input";
            	}



                break;

            case 2: 
            	cout<<"\n=======================Adding Capacitors=====================\n";
            	name = "capacitor";
				symbol = "farads";
				letter = "C";
            	cout<<"1. parallel addition \n2. series addition \nEnter choice :";
            	cin>>choice2;
            	if(choice2 == 1){
            		normal(name,symbol,letter);        		
            	}
            	else if(choice2 ==2){
					inverse(name,symbol,letter);
            	}
            	else{
            		cout<<"invalid input";
            	}


                break;



            case 3:
            	cout<<"\n=================CONVERSION CALCULATOR====================\n";
            	cout<<"\n1. Resistor \n2.Capacitor";
            	cin>>choice3;
            	if(choice3 ==1 || choice3==2){
            		conversioncalc(choice3);
            	}
            	if(choice3==3)break;


            	break;
            case 4: // exit
            	//clearLastLine();
                cout << "Exited\n";

                break;

            default:
                cout << "\ninvalid Input, 1-3 only.\n";
        
    	}
	}while (choice != 4);
}




//6-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Activity 3
void ohm(int choice, double &V, double &I, double &R, double &result) {
    switch (choice) {
        case 1:
            cout << "Current (I):" << endl;
            cin >> I;
            cout << "Resistance (R):" << endl;
            cin >> R;
            result = I * R;  
            break;
        
        case 2:
            cout << "Voltage (V):" << endl;
            cin >> V;
            cout << "Resistance (R):" << endl;
            cin >> R;
            result = V / R;  
            break;
        
        case 3:
            cout << "Voltage (V):" << endl;
            cin >> V;
            cout << "Current (I):" << endl;
            cin >> I;
            result = V / I;  
            break;
        
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}

void ohmslawcalc() {
    int choice;
    double V = 0, I = 0, R = 0, result = 0;
    char again;

    do {
        
        cout << "You have selected the Ohm's Law Calculator." << endl;
        cout << "1. Calculate Voltage (V = I * R)" << endl;
        cout << "2. Calculate Current (I = V / R)" << endl;
        cout << "3. Calculate Resistance (R = V / I)" << endl;
        cout << "Please enter your choice(1-3): ";
        
        
        while (true) {
            cin >> choice;
            if (choice >= 1 && choice <= 3) {
                break;
            } else {
            	clear();
                cout << "Invalid choice! Please enter a number between 1 and 3: ";
            }
        }

        
        ohm(choice, V, I, R, result);

        
        switch (choice) {
            case 1:
                cout << "Calculated Voltage (V): " << result << endl;
                break;
            case 2:
                cout << "Calculated Current (I): " << result << endl;
                break;
            case 3:
                cout << "Calculated Resistance (R): " << result << endl;
                break;
        }

    
        cout << "Do you want to perform another calculation? (Y/N): ";
        cin >> again;

        
        while (again != 'Y' && again != 'y' && again != 'N' && again != 'n') {
            cout << "Invalid choice! Please enter 'Y' for Yes or 'N' for No: ";
            clear();
            cin >> again;
        }

    } while (again == 'Y' || again == 'y'); 

    cout << "Thank you for using the Ohm's Law Calculator!" << endl;

}

//7--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Acitity 4
void transformer(int choice, double &Vp, double &Vs, double &Np, double &Ns, double &ratio, double &result) {
    switch (choice) {
        case 1:
            cout << "Secondary voltage(V)=" << endl;
            cin >> Vs;
            cout << "Number of turns of the primary coils=" << endl;
            cin >> Np;
            cout << "Number of turns of the secondary coils=" << endl;
            cin >> Ns;
            result = (Np / Ns) * Vs;
            ratio = (Np / Ns);
            break;
        
        case 2:
            cout << "Primary voltage(V)=" << endl;
            cin >> Vp;
            cout << "Number of turns of the primary coils=" << endl;
            cin >> Np;
            cout << "Number of turns of the secondary coils=" << endl;
            cin >> Ns;
            result = (Ns / Np) * Vp;
            ratio = Ns / Np;
            break;
        
        case 3:
            cout << "Primary voltage(V)=" << endl;
            cin >> Vp;
            cout << "Secondary voltage(V)=" << endl;
            cin >> Vs;
            cout << "Number of turns of the secondary coils=" << endl;
            cin >> Ns;
            result = (Vp / Vs) * Ns;
            ratio = Vp / Vs;
            break;
        
        case 4:
            cout << "Primary voltage(V)=" << endl;
            cin >> Vp;
            cout << "Secondary voltage(V)=" << endl;
            cin >> Vs;
            cout << "Number of turns of the primary coils=" << endl;
            cin >> Np;
            result = (Vs / Vp) * Np;
            ratio = Vs / Vp;
            break;
        
        default:
            cout << "Invalid choice!" << endl;
            clear();
    }
}

void transformercalc() {
    int choice;
    double Vp = 0, Vs = 0, ratio = 0, result = 0, Np = 0, Ns = 0;
    char repeat;
    
    do {
        cout << "You have selected the Transformer Calculator" << endl;
        cout << "1. Calculate Primary voltage, Vp=(Np / Ns) x Vs"<< endl;
        cout << "2. Calculate Secondary voltage, Vs=(Ns / Np) x Vp" << endl;
        cout << "3. Calculate Number of turns of the primary coils, Np= (Vs/Vp) x Np" << endl;
        cout << "4. Calculate Number of turns of the secondary coils, Ns= (Vs/Vp) x Np" << endl;
        cout << "Please enter your choice(1-4):";
        
        
        while (true) {
            cin >> choice;
            if (choice >= 1 && choice <= 4) {
                break;
            } else {
            	clear();
                cout << "Invalid choice! Please enter a number between 1 and 4: ";
            }
        }
        transformer(choice, Vp, Vs, Np, Ns, ratio, result);
        switch (choice) {
            case 1:
                cout << "Calculated primary voltage (V) = " << result << endl;
                cout << "The ratio of primary voltage to secondary voltage = " << ratio << endl;
                break;

            case 2:
                cout << "Calculated secondary voltage (V) = " << result << endl;
                cout << "The ratio of secondary voltage to primary voltage = " << ratio << endl;
                break;

            case 3:
                cout << "Calculated number of turns of the primary coils = " << result << endl;
                cout << "The ratio of number of turns of the primary coils to number of turns of the secondary coils = " << ratio << endl;
                break;

            case 4:
                cout << "Calculated number of turns of the secondary coils = " << result << endl;
                cout << "The ratio of secondary voltage to primary voltage = " << ratio << endl;
                break;
        }

        cout << "Do you want to perform another calculation (Y/N)? ";
        cin >> repeat;

        
        while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n') {
            cout << "Invalid choice! Please enter 'Y' for Yes or 'N' for No: ";
            clear();
            cin >> repeat;          	
        }
    } while (repeat == 'Y' || repeat == 'y');

    cout << "Thank you for using the Transformer Calculator!" << endl;

}















void menu(){
	int option;
	cout<<"\n================================MENU=======================================";
	do{

		cout<<"\n1. Introduction \n2. Topic \n3. Activity Description \n4. Activity 1 Quizz \n5. Activity 2 Resistor and Capacitor Calculator \n6. Activity 3 OHMS Law Calculator  \n7. Activity 4 Transformer Calculator\n8. Exit \nEnter choice:";

		clear();

		cin>>option;

		switch(option){

			case 1:
				cout << "\n-------------------------------------- Introduction --------------------------------------\n";
				intrduction();

				cout<<"\n-----------------------------------------------------------------------------------------------\n";
				break;
			case 2:
				cout << "\n----------------------------------------- chapters------------------------------------------\n";
				chapters();
				cout<<"\n-----------------------------------------------------------------------------------------------\n";
				break;
			case 3:
				cout << "\n---------------------------------- Activity Description -----------------------------------\n";
				activitydescription();
				cout<<"\n-----------------------------------------------------------------------------------------------\n";
				break;
			case 4:
				cout << "\n------------------------------------- Activity 1 Quiz -------------------------------------\n";

				activity1();
				cout<<"\n-----------------------------------------------------------------------------------------------\n";
				break;
			case 5:
				cout << "\n------------------------- Activity 2 Resistor and Capacitor Calculator ---------------------\n";
				activity2();
				cout<<"\n-----------------------------------------------------------------------------------------------\n";
				break;
			case 6:
				cout << "\n--------------------------------- Activity 3 OHMS Law Calculator ---------------------------\n";
				ohmslawcalc();
				cout<<"\n-----------------------------------------------------------------------------------------------\n";
				break;
			case 7:
				cout << "\n-------------------------------- Activity 4 Transformer Calculator -------------------------\n";
				transformercalc();

				cout<<"\n-----------------------------------------------------------------------------------------------\n";
				break;
			case 8:
				cout << "\n----------------------------------------- Exit ---------------------------------------------\n";

				break;
            default:
            	cout << "Invalid Input, 1-7 only.\n";
                

		}
		cout<<"\n";
	}while(option !=8);
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void loginmenu() {
    int choice;
    bool isLoggedIn;
    do {
    	
        cout << "\n====================================LOGIN MENU===================================================\n";
        cout<<"Before entering menu, you must Login or sign up (if you dont have an account)";

        cout<<"\n1. Login\n2. Sign up\n3. Exit\nEnter choice : ";

        
        cin>>choice;

        switch (choice) {
			case 1:
			    login(isLoggedIn);
			    if (isLoggedIn) {
			        menu();
			    }
			    break;


            case 2: // signup
                signup(); // just call it
                break;

            case 3: // exit
            	//clearLastLine();
                cout << "Exited\n";

                break;

            default:
                clear();
                break;
        }
    } while (choice != 3);

}

















//######################################################################################################################################################################################################################################################################################
void title(){
	cout<<"=========================== WELCOME TO CIRCUIT THEORY ================================\n";
	cout << "************************************************************************************\n";
    cout << "*                                                                                  *\n";
    cout << "*   ##     ##  ######   ########    ###       ##    #######  ##         #######    *\n";
    cout << "*   ##     ## ##    ##  ##         ## ##    ####   ##     ## ##    ##  ##     ##   *\n";
    cout << "*   ##     ## ##        ##        ##   ##     ##          ## ##    ##         ##   *\n";
    cout << "*   ##     ## ##   #### ######   ##     ##    ##    #######  ##    ##   #######    *\n";
    cout << "*   ##     ## ##    ##  ##       #########    ##   ##        #########        ##   *\n";
    cout << "*   ##     ## ##    ##  ##       ##     ##    ##   ##              ##  ##     ##   *\n";
    cout << "*    #######   ######   ######## ##     ##  ###### #########       ##   #######    *\n";
    cout << "*                                                                                  *\n";
    cout << "************************************************************************************\n";
    cout<<"================================================================================================\n";

}



void courseintroduction(){
	cout<<"\n===================================COURSE INTRODUCTION=========================================\n";
	cout<<"Circuit Theory UGEA1243 teachers the fundemental basic of electronic circuits .\n";
	cout<<"Circuit Theory studies the relationship between voltage, current, power, and energy by manipulating it with matamatics\n";
	cout<<"Tacher Name :Yeap Kim Ho\n";
	cout<<"CLO 1– Solve DC circuit problem by using circuit analysis techniques.\n";
	cout<<"CLO 2– Solve AC circuit problem by using circuit analysis techniques.\n"; 
	cout<<"CLO 3– Apply circuit theorems on AC power analysis.\n";
	cout<<"CLO 4– Present ethical responsibilities in report writing.\n";
	cout<<"\n===============================================================================================\n";

}



void mainmenu(){


	//cout<<"\n1. Login\n2. Sign up\n3. Exit";
    int choice; //InputIntigerAndRangeChecker(1,3,"1. Course Title\n2. Course Introduction\n3. Exit\nEnter choice : ");
    do{
    	cout<<"\n==============================MAIN MENU======================================================\n";
	    cout<<"\n1. Course Title\n2. Course Introduction\n3. menu \n4. Exit \nEnter choice : ";
	    cin>>choice;
	    switch(choice){
	    case 1://login
	    	title();
	    	break;

	    case 2:
	    	courseintroduction();

	    	break;

	    case 3:
	    	//cout<<"Before entering menu, you must Login or sign up(if you dont have an account).\n";
	    	loginmenu();
	    	break;
	    default:
	    	if(choice!=4 ){
		    	clear();
		    	break;
		    }
		}

	}while(choice!=4);
}














int main(){

	mainmenu();
}

//checking