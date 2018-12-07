#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <math.h>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

class Mainthing
{
    map<int,vector<vector<bool> > > MT; ///nem jó kivételre, és kell, hogy mennyi van belõle?
    vector<vector<unsigned short int> > CT;
    bool rotable;
    unsigned short int R,G,B;

public:
    void Mainthing()
    {
        unsigned short int amount;
        bool TB;
        vector<bool> TBV(4,0);
        vector<vector<bool> > TBM(3,TBV);
        fstream f(input.txt);
        if(f.fail()) {cout<<"Unsuccesful input loading: File missing"<<endl;
        return;}
        f>>rotable;
        f>>R;
        f>>G;
        f>>B;
        unsigned short int step=0;
        unsigned long long TileAn;
        while(!f.eof())
        {
            step++;
           f>>amount;
           for(int i=0; i<=3; i++)
           {
               TileAn= TileAn + i*10;
               for(int j=0; j<4; j++)
               {
                f>>TB;
                if(TB==1){TileAn++;
                TBV[j]=TB;}
               }
               if(TileAn%2!=0){cout<<"Unsuccesful input loading: Reading Tile "<<step<<" was unsuccesful. To many or not enough sides for color "<< i<< " ."<<endl;
               return;};
               if(TileAn%10!=0){TileAn=TileAn-i*10;}else {TileAn=TileAn-2;};
               TBM[i]=TBV;
           }
           ///Szám elemzés mostanra kellene (1,2,3) _,_ _ _(mennyiség),_ _ _(lépés) ez a map indexe

           ///lehetne még tulajdonság:
           ///      Melyik színre milyen: _ _ _-> R G B 1->6 lehet.
           ///      Típus:
           ///       1-> egy szín egyenes
           ///       2-> egyszín kanyar
           ///       3-> két szín függtelen
           ///       4-> két szín egy azonos vég
           ///       5-> két szín két azonos vég
           ///       6-> három szín egy függtelen a többitõl
           ///       7-> három szín egy közös vég
           ///       8-> három szín két vég kevert, de nem azonos színekkel   (lehet jobb lenne a 7-es helyén)
           ///       9-> fehér

           /// a mapban a függetleneken meg át elõször, amjd a két színeseken, és így tovább.

           /*for(int i=1; i<=amount; i++)
           {
               if(TileAn%30==0)
               {
                   MT[(TileAn/1000000000)+3000]=TBM;
                   TileAn=TileAn+1000000000;
               };
                if(TileAn%20==0)
               {
                   MT[((TileAn/1000000)-(TileAn/1000000000)*1000)+2000]=TBM;
                   TileAn=TileAn+1000000;
               };
                if(TileAn%10==0)
               {
                   MT[((TileAn/1000)-(TileAn/1000000)*1000)+1000]=TBM;
                   TileAn=TileAn+1000;
               };
           }*/

        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
