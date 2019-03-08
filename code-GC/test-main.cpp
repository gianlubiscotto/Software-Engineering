#include <fstream>
#include <iostream>
#include "types.h"
#include "functions.h"
#include "DAG.h"
using namespace std;

//funzione leggi intervallo
bool read_interval(IR& I, istream &cin, ostream &cout,ostream &cerr)
{
    R l,u;
    bool ok=true;
    cin>>l>>u;
    if (!cin) ok=false;
    else
    {
        IR I_temp=IR(l,u);
        I=I_temp;
    }
    if(!ok) cerr<<"Check the right sintax for boxes"<<endl;
    return ok;
}

//funzione leggi box
bool read_box(BR& B, N d,istream &cin, ostream &cout,ostream &cerr)
{
    bool ok=true;
    for (N i=0; ok&&i<d; i++)
    {
        IR I;
        if(read_interval(I,cin,cout,cerr))
        {
            B.x[i]=I;
        }
        else ok=false;
    }
    if(!ok) return ok;
    cout <<"Box "<< B<<endl;
    return ok;
}

void test (istream &cin, ostream &cout, ostream &cerr)
{
    bool ok=true;
    char c;
    N d;
    vector<N>vUB;
    cin>>c>>d;
    if (!cin)
        return;
    if (c!='D'||d<1)
    {
        cerr<<"Testfiles must start with D and a digit that stands for the dimension!"<<endl;
        return;
    }
    DAG D(d);
    cout<<c<<" "<<d<<endl;
    cout<<"Dag of dimension "<<d<<" created"<<endl;

    while(ok)
    {
        cin>>c;
        N n=vUB.size();
        cout<<endl;
        if(!cin) return;
        switch(c)
        {

        case 'e':
        {
            cout <<c<<endl;
            cout<<"***Adding empty union of Boxes***"<<endl;
            vUB.push_back(D.empty());
        }
        break;

        case 'a':
        {
            if (n==0) return;
            BR Box(d);
            if(!read_box(Box,d,cin,cout,cerr))
                return;
            cout<<c<<endl;
            cout<<"***Adding Box to union***"<<endl;
            N b=D.make(Box);
            int n=vUB.size();
            cout<<"\tadding "<<b<<" to "<<vUB[n-1];
            vUB[n-1]=D.sum(b,vUB[n-1]);
            cout<<" produce "<<vUB[n-1]<<endl;
        }
        break;

        case 'c':
        {
            if (n==0) return;
            BR Box(d);
            if(!read_box(Box,d,cin,cout,cerr))
                return;
            cout<<c<<endl;
            cout<<"***Checking for coverage...***"<<endl;
            if (D.cover(Box,vUB[n-1]))
                cout<<"Box is covered by last UB"<<endl;//aggiungere il vUB di riferimento
            else
                cout<<"Box is not covered!"<<endl;
        }
        break;

        case 'P':
        {
			if(n==0) return;
            cout<<c<<endl;
			cout<<"vUB's values: ";
			for (N k=0;k<n;k++){
				cout<<vUB[k]<<" ";
			}
            cout<<endl<<"***Printing graph"<<vUB[n-1]<<"***"<<endl;
            D.print_test(cout);
        }
        break;

        case '+':{
			if(n<2) return;
			cout<<c<<endl;
			cout<<"Joining vUB["<<n-2<<"]="<<vUB[n-2]<<" and vUB["<<n-1<<"]="<<vUB[n-1]<<endl;
			N b=D.sum(vUB[n-2],vUB[n-1]);
			cout<<"Result added to vUB="<<b<<endl;
			vUB.push_back(b);
        }break;

        case '<':{
			if(n<2) return;
			cout<<c<<endl;
			cout<<"Comparing vUB["<<n-2<<"]="<<vUB[n-2]<<" and vUB["<<n-1<<"]="<<vUB[n-1]<<endl;
			CMP b=D.cmp(vUB[n-2],vUB[n-1]);
			string result="";
			switch(b){
			case 'e':{
				result="equal to";			
			}break;
			case 'l':{	
				result="strictly minor with respect to";				
			}break;
			case 'g':{
				result="strictly greater than";			
			}break;
			case 'n':{
				result="not comparable to";			
			}break;
			default: return;
			break;
			}
			cout<<"vUB["<<n-2<<"] is "<<result<<" vUB["<<n-1<<"]"<<endl;
        }break;
        
		default:
        {
            cout<<c<<endl;
            cout << "Operator not recognized"<<endl;
            return;
        }
        break;
        }
    }
    return;
}

int main()
{
    cout <<"Welcome to testBox.\nPlease type the input file."<<endl;
    string input, output;
    cin>>input;
    cout<<"Type the output file."<<endl;
    cin>>output;
    ifstream inFile;
    inFile.open(input.c_str());
    if (!inFile)
    {
        cerr << "Unable to open the input file"<<endl;
        return 0;   // call system to stop
    }
    ofstream outFile;
    outFile.open(output.c_str());
    if (!outFile)
    {
        cerr << "Unable to open the output file"<<endl;
        return 0;   // call system to stop
    }
    test(inFile,outFile,cerr);
    inFile.close();
    outFile.close();
    return 0;
}
