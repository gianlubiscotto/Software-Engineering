#include <iostream>
#include "types.h"
#include "functions.h"
#include "DAG-hypro.h"

//type working with hypro::Box<R>
typedef mpq_class R; 

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

    DAG_hypro<R> G(d);
    vector<N> vUB(nUI);//links to U_BR in G
    for (N n=0; n<nUI; n++)
    {
        vUB[n]=G.empty();//empty UBR
        for (N i=0; i<nI; i++)
        {
            vector<R> coordinates_first(d);
            vector<R> coordinates_second(d);
            cout <<endl<< "Type the coordinates of box's vertices"<<endl;
            for(N k=0; k<2; k++)
            {
                if(k==0) cout<<endl<<"LOWER VERTEX"<<endl;
                else cout<<endl<<"UPPER VERTEX"<<endl;
                for (N j=0; j<d; j++)
                {

                    R n_;
                    do
                    {
                        cout <<"coordinate #"<<j+1<<endl;
                        cin >> n_;
                        if (n_>max) cout<<"coordinate exceeds max value"<<endl;
                    }
                    while(n_>max);
                    if(k==0) coordinates_first[j]=n_;
                    else coordinates_second[j]=n_;
                }
            }

            cout << endl<<"first point"<<endl;
            cout << "( ";
            for (N k=0; k<coordinates_first.size(); k++)
            {
                cout << coordinates_first[k]<<" ";
            }
            cout << ")"<<endl;

            cout << "second point"<<endl;
            cout << "( ";
            for (N k=0; k<coordinates_second.size(); k++)
            {
                cout << coordinates_second[k]<<" ";
            }
            cout << ")"<<endl<<endl;

            //Creation of hypro::box from two limit points.
            hypro::Point<R> first_vertex=hypro::Point<R>(coordinates_first);
            hypro::Point<R> second_vertex=hypro::Point<R>(coordinates_second);
            hypro::Box<R> testbox(std::make_pair(first_vertex,second_vertex));

            if (G.cover(testbox,vUB[n])) cout<<"Box is covered!"<<endl;
            else
            {
                N b=G.make(testbox); //generate a link to UB
                cout<<"\tadding "<<b<<" to "<<vUB[n]<<endl; 
                vUB[n]=G.sum(b,vUB[n]); //merging two UBs
                cout<<" produce "<<vUB[n]<<endl;
            }
            cout<<"snapshot "<<endl;
            G.print_test(cout);
        }
    }

    cout<<"info on DAG "<<endl;
    G.print_test(cout);
    return 0;
}

