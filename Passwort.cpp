#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <cstdlib>

using namespace std;

string Daten,decrypt,wahl,close,kPasswort;
int eingabe,loop,i,falsch = 0,versuche = 5;
ofstream File;
ifstream txt,psw; 






	int main()

{
	 string Passwort,rPasswort = "";







	//feststellen ob Passwort festgelegt wurde
	
		txt.open("Programm.txt",ios::out | ios::app | ios::in);
		if (txt.is_open())
	 	
		 {
		  	getline(txt,rPasswort);
		  	
		  		
		  		for(size_t i = 0; i < rPasswort.size(); ++i)

					{
	
  						rPasswort[i] -= 300;
  
					}
				  		
			
		 }
	
		//Passwort festlegen
	if (rPasswort == "")
	{
		cout << " Bitte gib ein Passwort für das Programm ein (Nur ASCII erlaubt) \n Passwort: ";	
		cin >> rPasswort;
		
		for(size_t i = 0; i < rPasswort.size(); ++i)

	{
	
  		rPasswort[i] += 300;
  
	}
		File.open("Programm.txt",ios::out | ios::app | ios::in);
		File << rPasswort;
		cout << " Passwort gespeichert das Programm wird neugestartet";
		system("start Passwort.exe");
		exit(1);
	}
	

	

	
		while (true)
       {
	   kPasswort = rPasswort;
	   HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
 	   DWORD mode = 0;                                                                    //Macht Eingabe unsichtbar
       GetConsoleMode(hStdin, &mode);
       SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	      	   
       cout << " \nBitte gib das Passwort ein "<< endl;
	   cin >> Passwort;
	   
	   SetConsoleMode(hStdin, mode); 
	    
	    
	    
		 
		if (Passwort == kPasswort)
	{
		 
     	cout << " M\224chtes du ein Passwort eingeben (1) oder die Passw\224rter anzeigen lassen (2) ? " << endl;
     	cin.sync();
     	cin >> eingabe; 
     	cin.sync();
     
     	if (eingabe == 1)
     
	 {
	 
	 	cout << " Wie viele Eingaben möchtest du machen? ";
	 	cin >> eingabe;
	 
	 	while (loop != eingabe)
	
	 {
	 
	 	//Konto eingabe	
	 
    	 cin.sync();
	 	cout << " Konto Informationen: "	;
	 	getline(cin,Daten);
	 	cout << " Dein Konto: 	" << Daten << endl;
         
    	 // ; mit Zeilenumbruch ersetzen
     
    	replace(Daten.begin(), Daten.end(), ';','\n');
	 
		 //Textdatei encrypten 
	 
	 
     	for(size_t i = 0; i < Daten.size(); ++i)

	{
	
  		Daten[i] += 300;
  
	}
	 
		//Daten in Textdatei schreiben
	 
		File.open("Passwort.txt",ios::out | ios::app | ios::in);
		File << Daten;
	 
		File.close(); 


	 	loop++;	
    
	 } //ende der while schleife
	 
	 	 	
	 } //ende von if
	 
	 
	 	else if (eingabe == 2)
	 {		
	 		//Text einlesen
	 		psw.open("Passwort.txt");
	 		if (psw.is_open())
	 	
		 {
		  	while (getline(psw,Daten))
		  	{
		  		//Text decrypten
		  		for(size_t i = 0; i < Daten.size(); ++i)

					{
	
  						Daten[i] -= 300;
  
					}
				  		cout <<Daten << endl;
			}
		 }
	 }
	 
    
	}//Ende von Passwort if
	
		 if (Passwort != rPasswort)
		
			falsch++;
	


    		cout << "Falsches Passwort \n Weitere Versuche: " << versuche - falsch << endl;
		    cout << "Programm beenden (y) oder Passwort neu eingeben (n) ?";
		    cin >> wahl;
		    
							if(wahl == "y" || wahl == "Y"||falsch>4)
						{
					 		break;
 						}
 								else if(wahl =="n" || wahl =="N")
 							{
						 		
                        		continue; 
							} 
							                                                                              
                        			else if(wahl !="y" || wahl !="Y"|| wahl !="n"|| wahl !="N" )  
							
								{
																													                                                                                           
                        			cout <<" Falsche Eingabe "<<endl;                                                                                                             
 									break;
  								} 
    
 
    
   
   
              
	
	
	
	
	
	
	
	
	
	
	
	
	
}
	
	

}
