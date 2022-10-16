#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
void displayAccount(vector <int> &accNum, vector <string> &fName, vector <string> &lName, vector <double> &actBal, vector <string>
&dateV, vector <string> &timeV, vector <string> &validV, vector <string> &acTV, vector <bool> &kept) // You must use the above vectors
// to store the sorted accounts. kept is a bool vector which indicates whether an account is merged and not included in the merged file.
{
ifstream inFile("mergedAcount.txt", ios::in);
if(!inFile){
cout << "Error: File does not exit. " << endl;
exit(1);
}
else inFile.close();
int numActualAct=0;
for(int i=0; i<accNum.size(); i++)
if(kept[i]==true)
{
    cout<<setw(8) << setfill('0') <<accNum[i]<< setfill(' ')<<setw(10)<<fName[i]<<setw(10)<<lName[i]<<" "<<setw(8)<<actBal[i]<<" "<<setw(10) << acTV[i]<<" "<<dateV[i]<<" " <<timeV[i]<<" "<<setw(8)<<validV[i]<<endl;
    numActualAct++;
}
cout << "Number of accounts: " << numActualAct << endl;
}
int main(int argc, char **argv)
{
    if ( argc < 2 )
    {
        cerr << "Wrong" ;
        exit (1) ;
    }
    ifstream inFile ;
    inFile.open(argv[1]) ;
    ifstream inFile2 ;
    inFile2.open(argv[2]) ;
    vector<int>accountnum ;
    int a ;
    vector<string>firstname ;
    string b ;
    vector<string>lastname ;
    string c ;
    vector<double>balance ;
    double d ;
    vector<string>type ;
    string e ;
    vector<string>date ;
    string f ;
    vector<string>time ;
    string g ;
    vector<string>val ;
    string h ;
    vector<bool>keptc ;
    bool kept ;
    while ( inFile >> a >> b >> c >> d >> e >> f >> g >> h )
    {
        accountnum.push_back(a);
        firstname.push_back(b);
        lastname.push_back(c);
        balance.push_back(d);
        type.push_back(e);
        date.push_back(f);
        time.push_back(g);
        val.push_back(h);
    }
    while ( inFile2 >> a >> b >> c >> d >> e >> f >> g >> h )
    {
        accountnum.push_back(a);
        firstname.push_back(b);
        lastname.push_back(c);
        balance.push_back(d);
        type.push_back(e);
        date.push_back(f);
        time.push_back(g);
        val.push_back(h);
    }
    for ( int n = 0 ; n < accountnum.size() ; n++ )
    {
        for ( int n = 0 ; n < accountnum.size() - 1 ; n++ )
        {
            if ( accountnum[n] > accountnum[n+1] )
            {
                swap (accountnum[n], accountnum[n+1]) ;
                swap (firstname[n], firstname[n+1]) ;
                swap (lastname[n], lastname[n+1]) ;
                swap (balance[n], balance[n+1]) ;
                swap (type[n], type[n+1]) ;
                swap (date[n], date[n+1]) ;
                swap (time[n], time[n+1]) ;
                swap (val[n], val[n+1]) ;
            } 
        }
    }
    for ( int n = 0 ; n < accountnum.size() ; n++ )
    {
        if( accountnum[n] == accountnum[n+1] )
        {
            if ( type[n] != type[n+1] || val[n] == "false" || val[n+1] == "false" )
            {
                cout << "Inconsist information found for account number: " << accountnum[n] << endl ;
            }
        }
    }
    for (int n = 0 ; n < accountnum.size() ; n++ )
    {

        if ( accountnum[n] == accountnum[n+1] && firstname[n] == firstname[n+1] && val[n] == "true" && val[n+1] == "true" && type[n] == type[n+1] )
        {
            if ( time[n] < time [n+1] )
            {
                time[n] = time[n+1] ;
            }
            else if ( time[n] > time [n+1] )
            {
                time[n+1] = time[n] ;
                balance[n+1] = balance[n] + balance[n+1] ;
                keptc.push_back(false);
                continue ;
            }
            balance[n+1] = balance[n] + balance[n+1] ;
            keptc.push_back(false) ;
            
        }
        else
        {
            keptc.push_back(true) ;
        }
        
    }
    displayAccount(accountnum,firstname,lastname,balance,date,time,val,type,keptc) ;
    return 0 ;
}


