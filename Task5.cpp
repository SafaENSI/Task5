// ********working day - Task 5*********** //
#include <iostream>
#include <vector>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

int decodeSeat(string str,int nbr,char identifier[])
{
    int lo_range =0;
    int hi_range =nbr;
    for (int i=0; i<str.size(); i++)
    {
        if (str[i]==identifier[0])
        {
            lo_range =lo_range;
            hi_range= (lo_range+hi_range)/2;
        }
        else if (str[i]==identifier[1])
        {
            lo_range =(lo_range+hi_range+1)/2;
            hi_range= hi_range;
        }

    }
    return hi_range;
}
int CheckSeatID(string str,int nbr_row,int nbr_column, char row_identifiers[],char col_identifiers[])
{
    int lo_column =0;
    int hi_column =nbr_column;
    string str_row=  str.substr(0,7) ;
    string str_column=  str.substr(7,3) ;

    int row_nbr= decodeSeat(str_row,nbr_row,row_identifiers);
    int column_nbr= decodeSeat(str_column,nbr_column,col_identifiers);


    int result = row_nbr * 8 +column_nbr;
    return result;

}


int main()
{
    ifstream File;
    File.open("data.txt");
    std::vector<string> vect;
    string line;

    if(!File) //Always test the file open.
    {
        std::cout<<"Error opening output file"<<std::endl;
        system("pause");
        return -1;
    }

    while (std::getline(File, line))
    {
        vect.push_back(line);

    }
    File.close();

    int VectSize= vect.size();
    std::vector<int> vect_result;
    int nrows = 127;
    int ncols = 7;
    char row_identifiers[2] = {'F', 'B'}; // F: lower half B: upper half
    char col_identifiers[2] = {'L', 'R'}; //F: lower half B: upper half
    for (int j=0; j<VectSize; j++)
    {
        int result =CheckSeatID(vect[j],nrows,ncols,row_identifiers,col_identifiers);
        vect_result.push_back(result);
    }

    /* checking the max ID seat */
    int IdMax=vect_result[0];
    for (unsigned int i = 0; i < vect_result.size(); i++)
        if (vect_result[i] > IdMax)
            IdMax =vect_result[i];

    cout << " ******END: ******* The Highest seat ID was "<< IdMax << endl;
    std::vector<int>::iterator it;
    int lastElement=0;

    for (int row_nbr=0; row_nbr<128; row_nbr++)
    {
        for (int column_nbr=0; column_nbr<8; column_nbr++)
        {
            int ser= row_nbr * 8 +column_nbr;
            it = std::find (vect_result.begin(), vect_result.end(), ser);
            if (it != vect_result.end())
            {
                if (abs(ser-lastElement)==2)
                    std::cout << "Your Seat ID is " << ser-1 <<endl;
                lastElement= ser;
            }
            else
            {

            }

        }
    }


    return 0;
}
