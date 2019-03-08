#include <iostream>
#include <cstdlib>//for rand
#include "types.h"
#include "functions.h"
#include "DAG.h"

int main()
{
    cout << endl<<"TEST on union of intervals (UI)"<<endl;
    N d, nUI, nI;
	R max;
    cout << "How many UI do you want? ";
    cin>>nUI;
    cout << "What is the max number (>0) of intervals they can have? ";
    cin>>nI;
    nI++;
    cout << "What is the max number (>0) in an interval? ";
    cin>>max;
    cout << "Give a dimension >0 for boxes ";
    cin>> d;
    if (nI==0||max==0||d==0)
    {
        cout<<"wrong input!"<<endl;
        return 1;
    }
    max++;
    DAG G(d);
    vector<U_IR> vUI(nUI);
    vector<N> vUB(nUI);//links to U_BR in G
    for (int n=0; n<nUI; n++)
    {	
        vUB[n]=G.empty();//empty UBR
        for (int i=0; i<nI; i++)
        {
		vector<R> coordinates_uno(d);
		vector<R> coordinates_due(d);
		cout <<endl<< "Type the coordinates of box's vertices"<<endl;
		for(int k=0;k<2;k++){
			if(k==0) cout<<endl<<"LOWER VERTEX"<<endl;
			else cout<<endl<<"UPPER VERTEX"<<endl;
			for (N j=0; j<d; j++){
				
				R n_uno;
				do{
					cout <<"coordinate #"<<j+1<<endl;
					cin >> n_uno;
					if (n_uno>max) cout<<"coordinate exceeds max value"<<endl;
				}while(n_uno>max);
				if(k==0) coordinates_uno[j]=n_uno;
				else coordinates_due[j]=n_uno;
			}
		}

		cout << endl<<"first point"<<endl;
		cout << "( ";
		for (int k=0;k<coordinates_uno.size();k++){
			cout << coordinates_uno[k]<<" ";		
		}
		cout << ")"<<endl;
		
		cout << "second point"<<endl;
		cout << "( ";
		for (int k=0;k<coordinates_due.size();k++){
			cout << coordinates_due[k]<<" ";		
		}
		cout << ")"<<endl<<endl;
		//Creazione hypro::box da due punti limite. Commentare se non si vuole utilizzare hypro.
		/*hypro::Point<R> vertice_uno=hypro::Point<R>(coordinates_uno);
		hypro::Point<R> vertice_due=hypro::Point<R>(coordinates_due);
		hypro::Box<R> testbox(std::make_pair(vertice_uno,vertice_due));*/
		//Creazione box BR. Commentare se si vuole utilizzare hypro.
		BR testbox(d);
		for(N i=0; i<d;i++){
			IR I=IR(coordinates_uno[i],coordinates_due[i]);
			 testbox.x[i]=I;		
      	}

		if (G.cover(testbox,vUB[n])) cout<<"Box is covered!"<<endl;
		else{
	      		N b=G.make(testbox);
                	cout<<"\tadding "<<b<<" to "<<vUB[n]<<endl;
                	vUB[n]=G.sum(b,vUB[n]);
                	cout<<" produce "<<vUB[n]<<endl;
            	}
	   	cout<<"snapshot "<<endl; G.print();
        }
    }
  /*  cout<<"Comparisons o UI"<<endl;
    for(N i=0; i<nUI; i++)
        for(N j=0; j<nUI; j++)
        {
            CMP c=c_eq;
            cmp_a(vUI[i],vUI[j],c);
            cout<<"cmp of "<<vUI[i]<<" with "<<vUI[j]<<" is ";
            cout<<c<<" and "<<G.cmp(vUB[i],vUB[j])<<endl;
        }
	*/
    cout<<"info on DAG "<<endl;
    G.print();
    return 0;
}
