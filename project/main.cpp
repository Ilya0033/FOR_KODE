#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>
using namespace std;


class m
{
public:
    string name , type;
    long double x , y;
    string time;
};


bool cmp(m fir , m sec)
{
    return (  fir.x*fir.x + fir.y*fir.y < sec.x*sec.x + sec.y*sec.y  );
}

bool cmp1(m fir , m sec)
{
    int day1 = (fir.time[0]-48)*10+ (fir.time[1]-48) ;
    int mon1 = (fir.time[3]-48)*10 + (fir.time[4]-48);
    int year1 = (fir.time[6]-48)*1000 + (fir.time[7]-48)*100 + (fir.time[8]-48)*10 + (fir.time[9]-48);

    int day2 = (sec.time[0]-48)*10+ (sec.time[1]-48) ;
    int mon2 = (sec.time[3]-48)*10 + (sec.time[4]-48);
    int year2 = (sec.time[6]-48)*1000 + (sec.time[7]-48)*100 + (sec.time[8]-48)*10 + (sec.time[9]-48);

    long long a = (14-mon1)/12;
    long long y = year1 + 4800 - a;
    long long m = mon1+ 12*a - 3;
    long long j1 = day1 + ( (153*m+2)/5 ) + 365*y + y/4 -y/100 + y/400-32045;

    a = (14-mon2)/12;
    y = year2 + 4800 - a;
    m = mon2+ 12*a - 3;
    long long j2 = day2 + ( (153*m+2)/5 ) + 365*y + y/4 -y/100 + y/400-32045;

    return j1 > j2;
}


int j (m ob)
{

    int day1 = (ob.time[0]-48)*10+ (ob.time[1]-48) ;
    int mon1 = (ob.time[3]-48)*10 + (ob.time[4]-48);
    int year1 = (ob.time[6]-48)*1000 + (ob.time[7]-48)*100 + (ob.time[8]-48)*10 + (ob.time[9]-48);

    long long a = (14-mon1)/12;
    long long y = year1 + 4800 - a;
    long long m = mon1+ 12*a - 3;
    long long j1 = day1 + ( (153*m+2)/5 ) + 365*y + y/4 -y/100 + y/400-32045;

    return j1;
}

bool cmp2(m fir, m sec)
{
    return fir.name < sec.name;
}

bool cmp3(m fir, m sec)
{
    if (fir.type != sec.type) return fir.type < sec.type;
    else return fir.name < sec.name;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL , "ru");


    string path = "myfile.txt";


///������ ���������� ��� ����������� ���������� ����� � �����
    ifstream fin;
    fin.open(path);
int k = 0;
    if (!fin.is_open())
    {
        cout << "error";
    }
    else {

        while(!fin.eof())
        {
            string name = "", type = "" , time = "";
            long double x = 0, y = 0;

            fin >> name >> x >> y >> type >> time;
            if (name == "") {break;}
            //cout << name << x << y << type << time << "\n";
            k++;
        }
        //cout << k << "\n";
    }
    fin.close();///����� ���������� ��� ����������� ���������� ����� � �����


    cout << "��� ��� ����, � ������ ������� �������� ����� ������ �������� ��������� ������:\n-��� �������\n-���������� X (����� ���� ������������ ����� �� ������ �� ������������� 999999)\n-���������� Y (����� ���� ������������ ����� �� ������ �� ������������� 999999)\n-��� ������� (�������, ������, ������, ������ � �.�.)\n-���� �������� �������( � ������� ��.��.���� )\n����� �� ������� �������� ��������� ����� � ������� ��������, �� �������� �� ������ ������������� ��� ������\n\n������ �� ������ �������� ��������� ���������� ����� �� ������ �� �����, ������� ������ ����\n";

    int n,i=0;
    cout << "������� ����� �����, ������� �� ������ ��������: ";
    cin >> n; cout << "\n";
    m tabl[k+n+5];

    ///���� n ����� �������������
    for (i = 0; i < n; i++)
    {
        string na , t,timee;
        long double x1 , y1;

        cout << "������� ��� "  << i+1 <<"�� ������� (��� �������� � ������� �����!): "; cin >> na;
        cout << "������� ���������� X "  << i+1 <<"�� �������: "; cin >> x1;
        cout << "������� ���������� Y "  << i+1 <<"�� �������: "; cin >> y1;
        cout << "������� ��� "  << i+1 <<"�� �������: "; cin >> t;
        cout << "������� ���� ��������(�� ������� ����������� ����) "  << i+1 <<"�� �������(� ������� ��.��.����): "; cin >> timee;
        cout << "\n";
        tabl[i].name = na;
        tabl[i].x = x1;
        tabl[i].y = y1;
        tabl[i].type = t;
        tabl[i].time = timee;

    }///����� ����� �����



    ///������ ���������� ����� � ������ ��� � ����� �������
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "error";
    }
    else {

        while(!fin.eof())
        {
            string name = "", type = "", time="";
            long double x = 0, y = 0;

            fin >> name >> x >> y >> type >> time;
            if (name == "") break;
            tabl[i].name = name;
            tabl[i].x = x;
            tabl[i].y = y;
            tabl[i].type = type;
            tabl[i].time = time;
            //cout << name << " " << x << " " << y << " " <<  type << " " << time << "\n";
            i++;
        }

    }
    fin.close();
    ///����� ���������� ����� � ������ ��� � ����� �������

    cout << "�������� ���� �� ����������, �� �������� ����� ����������� �����������\n1) ����������� �� ���������� �� ������ ���������\n2) ����������� �� �����\n3) ����������� �� ����\n4) ����������� �� ������� ��������\n��� ������ ��������� ������� �����, ��������������� ���������� ���������: ";
    string q;

    cin >> q;
    while (q[0] != '1' && q[0] != '2' && q[0] != '3' && q[0] != '4' || q.size() != 1)
    {
        cout << "����� ������� �������, ��������� �������: "; cin >> q;
    }

    cout << "\n";




    if(q[0] == '1') ///����������� �� ����������
    {
        string un10 = "������ � ����������� �� 10 ������:\n";
        string un100 = "������ � ����������� �� 10 �� 100 ������:\n";
        string un1000 = "������ � ����������� �� 100 �� 1000 ������:\n";
        string m1000 = "������ � ����������� �� 1000 ������:\n";

        sort (tabl , tabl+(n+k), cmp);

        bool b1 =false , b2=false, b3=false , b4=false;
        for (int i = 0; i < n+k; i++)
        {
            if (tabl[i].name == "" && tabl[i].x == 0 && tabl[i].y == 0 && tabl[i].type == "" && tabl[i].time == "") continue;
            if ( sqrt ( tabl[i].x*tabl[i].x + tabl[i].y*tabl[i].y) < 10.0) {b1=true; un10+=tabl[i].name; un10 += " "; un10 += to_string(tabl[i].x); un10 += " "; un10 += to_string(tabl[i].y) ; un10 += " "; un10 += tabl[i].type; un10 += " ";un10+= tabl[i].time; un10 += "\n"; }
            if ( sqrt ( tabl[i].x*tabl[i].x + tabl[i].y*tabl[i].y) < 100.0 && sqrt ( tabl[i].x*tabl[i].x + tabl[i].y*tabl[i].y) >=10.0 ) {b2=true; un100+=tabl[i].name; un100 += " "; un100 += to_string(tabl[i].x); un100 += " "; un100 += to_string(tabl[i].y) ; un100 += " "; un100 += tabl[i].type; un100 += " ";un100+= tabl[i].time; un100 += "\n"; }
            if ( sqrt ( tabl[i].x*tabl[i].x + tabl[i].y*tabl[i].y) < 1000.0 && sqrt ( tabl[i].x*tabl[i].x + tabl[i].y*tabl[i].y) >=100.0 ) {b3=true; un1000+=tabl[i].name; un1000 += " "; un1000 += to_string(tabl[i].x); un1000 += " "; un1000 += to_string(tabl[i].y) ; un1000 += " "; un1000 += tabl[i].type; un1000 += " ";un1000+= tabl[i].time; un1000 += "\n"; }
            if ( sqrt ( tabl[i].x*tabl[i].x + tabl[i].y*tabl[i].y) >= 1000.0) {b4=true; m1000+=tabl[i].name; m1000 += " "; m1000 += to_string(tabl[i].x); m1000 += " "; m1000 += to_string(tabl[i].y) ; m1000 += " "; m1000 += tabl[i].type; m1000 += " ";m1000+= tabl[i].time; m1000 += "\n"; }
        }
        if (b1 == false) { un10 += "��� ��������\n"; }
        if (b2 == false) { un100 += "��� ��������\n"; }
        if (b3 == false) { un1000 += "��� ��������\n"; }
        if (b4 == false) { m1000 += "��� ��������\n"; }

    ///������ � ����
    ofstream fout;
    fout.open(path,ofstream::app);
    if (!fout.is_open())
    {
        cout << "error";
    } else
    {
        fout << "\n" << un10 << "\n" << un100 << "\n" << un1000 << "\n" << m1000;
    }fout.close(); ///����� ������ � ����

    cout << "������� ���� �������������, � ������ ������ ������ ������������� �� ���������� � ������� �������� � ����\n\n";


    cout << "���� ������ ������� ��������� ����������� ������, ������� '1'. � ��������� ������ ������� ����� ������\n\n";
    string s1 = ""; cin >> s1;
    if (s1 == "1")
    {
        cout << un10 << "\n";
        cout << un100 << "\n";
        cout << un1000 << "\n";
        cout << m1000 << "\n";
    }

    }///




    if(q[0] == '2') ///����������� �� �����
    {
        sort(tabl , tabl+(n+k) , cmp2);
        string add = "";
        int c = 0;

        for (int i = 0; i < n+k; i++)
        {
            if (tabl[i].name == "" && tabl[i].x == 0 && tabl[i].y == 0 && tabl[i].type == "" && tabl[i].time == "") continue;
            if (int(tabl[i].name[0]) >= -64 && int(tabl[i].name[0]) <= -33)
            {
                if (i==0 || tabl[i].name[0]!= tabl[i-1].name[0]) {add += "������ '"; add+= tabl[i].name[0]; add+= "':\n"; add+=tabl[i].name; add+=" "; add+= to_string (tabl[i].x); add+=" "; add+=to_string (tabl[i].y); add+=" "; add+=tabl[i].type; add+=" "; add+=tabl[i].time;   add+="\n"; }
                else {
                    add+=tabl[i].name; add+=" "; add+=to_string (tabl[i].x); add+=" "; add+=to_string (tabl[i].y); add+=" "; add+=tabl[i].type; add+=" "; add+=tabl[i].time;   add+="\n";
                }
            }
            else {
                if (c == 0) {add += "������ '#':\n";c=1;}
                add+=tabl[i].name; add+=" "; add+=to_string (tabl[i].x); add+=" "; add+=to_string (tabl[i].y); add+=" "; add+=tabl[i].type; add+=" "; add+=tabl[i].time;   add+="\n";
            }
        }

         ///������ � ����
    ofstream fout;
    fout.open(path,ofstream::app);
    if (!fout.is_open())
    {
        cout << "error";
    } else
    {
        fout << "\n" << add;
    }fout.close(); ///����� ������ � ����
    cout << "������� ���� �������������, � ������ ������ ������ ������������� �� ����� � ������� �������� � ����\n\n";

    cout << "���� ������ ������� ��������� ����������� ������, ������� '1'. � ��������� ������ ������� ����� ������\n\n";
    string s1 = ""; cin >> s1;
    if (s1 == "1")
    {
         cout << add << "\n";
    }

    }///




    if (q[0] == '3') ///����������� �� ����
    {
        sort(tabl,tabl+(n+k) , cmp3);

        cout << "P.S. ������ ����� �������, ���� ���� 2 � ����� ������� ������������ ����. ����� ����� ������� ���������� � ������ '������'.\n\n";
        string raznoe = "������ '������':\n";
        string d = "";

        int c = 1, pr = 0;
        for (int i = 0;i < n+k; i++)
        {
            if (tabl[i].name == "" && tabl[i].x == 0 && tabl[i].y == 0 && tabl[i].type == "" && tabl[i].time == "") continue;
            if (tabl[i].type == tabl[i+1].type) {c++; }
            else
            {
                if (c > 1)
                {
                    d+= "������ '"; d+= tabl[i].type; d+="':\n";
                    for (int j = i-c+1; j <= i; j++)
                    {
                        d+=tabl[j].name; d+=" "; d+=to_string (tabl[j].x); d+=" "; d+=to_string (tabl[j].y); d+=" "; d+=tabl[j].type; d+=" "; d+=tabl[j].time;   d+="\n";
                    }
                }
                else if (c == 1)
                {
                    raznoe+=tabl[i].name; raznoe+=" "; raznoe+=to_string (tabl[i].x); raznoe+=" "; raznoe+=to_string (tabl[i].y); raznoe+=" "; raznoe+=tabl[i].type; raznoe+=" "; raznoe+=tabl[i].time;   raznoe+="\n";
                    pr=1;
                }
                c=1;
            }
        }
        if (pr==0) { raznoe+= "��� ��������\n" ;}


    ///������ � ����
    ofstream fout;
    fout.open(path,ofstream::app);
    if (!fout.is_open())
    {
        cout << "error";
    } else
    {
        fout << "\n" << d << raznoe;
    }fout.close(); ///����� ������ � ����
    cout << "������� ���� ��������������, � ������ ������ ������ ������������� �� ����� � ������� �������� � ����\n\n";

    cout << "���� ������ ������� ��������� ����������� ������, ������� '1'. � ��������� ������ ������� ����� ������\n\n";
    string s1 = ""; cin >> s1;
    if (s1 == "1")
    {
         cout << d << raznoe << "\n";
    }


    }///






    if (q[0] == '4') ///����������� �� �������
    {
        string d;
        cout << "������� ����������� ���� � ������� ��.��.����: "; cin >> d;
        int day = (d[0]-48)*10 + (d[1]-48);
        int mon = (d[3]-48)*10 + (d[4]-48);
        int year = (d[6]-48)*1000 + (d[7]-48)*100 + (d[8]-48)*10 + (d[9]-48);

        long long a = (14-mon)/12;
        long long y = year + 4800 - a;
        long long m = mon+ 12*a - 3;
        int an = day + ( (153*m+2)/5 ) + 365*y + y/4 -y/100 + y/400-32045;

        string today = "�������:\n", yest = "�����:\n", on_this_week = "�� ���� ������:\n" , on_this_mon = "� ���� ������:\n", this_year = "� ���� ����:\n" , ranee = "�����:\n";
        long long raz = an - j(tabl[i]);
        bool b1 = false , b2 = false, b3 = false, b4 = false, b5 = false , b6 = false ;

        sort (tabl , tabl+(n+k) , cmp1);

        for (int i = 0; i < n+k; i++)
        {
            if (tabl[i].name == "" && tabl[i].x == 0 && tabl[i].y == 0 && tabl[i].type == "" && tabl[i].time == "") continue;

            int tab_m = (tabl[i].time[3]-48)*10 + (tabl[i].time[4]-48);
            int tab_y = (tabl[i].time[6]-48)*1000 + (tabl[i].time[7]-48)*100 + (tabl[i].time[8]-48)*10 + (tabl[i].time[9]-48);

            if ((an - j(tabl[i])) == 0) {b1=true; today+=tabl[i].name; today += " "; today += to_string(tabl[i].x); today += " "; today += to_string(tabl[i].y) ; today += " "; today += tabl[i].type; today += " ";today+= tabl[i].time; today += "\n"; continue; }
            if ((an - j(tabl[i])) == 1) {b2=true; yest+=tabl[i].name; yest += " "; yest += to_string(tabl[i].x); yest += " "; yest += to_string(tabl[i].y) ; yest += " "; yest += tabl[i].type; yest += " ";yest+= tabl[i].time; yest += "\n"; continue;  }
            if ((an - j(tabl[i])) < 8 && (an - j(tabl[i]))>1) {b3=true; on_this_week+=tabl[i].name; on_this_week += " "; on_this_week += to_string(tabl[i].x); on_this_week += " "; on_this_week += to_string(tabl[i].y) ; on_this_week += " "; on_this_week += tabl[i].type; on_this_week += " ";on_this_week+= tabl[i].time; on_this_week += "\n"; continue; }
            if (mon == tab_m && year == tab_y) { b4=true; on_this_mon+=tabl[i].name; on_this_mon += " "; on_this_mon += to_string(tabl[i].x); on_this_mon += " "; on_this_mon += to_string(tabl[i].y) ; on_this_mon += " "; on_this_mon += tabl[i].type; on_this_mon += " ";on_this_mon+= tabl[i].time; on_this_mon += "\n";  continue; }
            if (year == tab_y) {b5 = true; this_year+=tabl[i].name; this_year += " "; this_year += to_string(tabl[i].x); this_year += " "; this_year += to_string(tabl[i].y) ; this_year += " "; this_year += tabl[i].type; this_year += " ";this_year+= tabl[i].time; this_year += "\n"; continue;  }

            b6=true; ranee+=tabl[i].name; ranee += " "; ranee += to_string(tabl[i].x); ranee += " "; ranee += to_string(tabl[i].y) ; ranee += " "; ranee += tabl[i].type; ranee += " ";ranee+= tabl[i].time; ranee += "\n";

        }
        if (b1==false) { today +="��� ��������\n";}
        if (b2==false) {yest+="��� ��������\n";}
        if (b3==false) {on_this_week+="��� ��������\n";}
        if (b4==false) {on_this_mon+="��� ��������\n";}
        if (b5==false) {this_year+="��� ��������\n";}
        if (b6==false) {ranee+="��� ��������\n";}

        ///������ � ����
    ofstream fout;
    fout.open(path,ofstream::app);
    if (!fout.is_open())
    {
        cout << "error";
    } else
    {
        fout << "\n" << today << "\n" << yest<< "\n" << on_this_week << "\n" << on_this_mon << "\n" << this_year << "\n" << ranee;
    }fout.close(); ///����� ������ � ����
    cout << "������� ���� ��������������, � ������ ������ ������ ������������� �� ������� � ������� �������� � ����\n\n";


    cout << "���� ������ ������� ��������� ����������� ������, ������� '1'. � ��������� ������ ������� ����� ������\n\n";
    string s1 = ""; cin >> s1;
    if (s1 == "1")
    {
        cout << today << "\n";
        cout << yest << "\n";
        cout << on_this_week << "\n";
        cout << on_this_mon << "\n";
        cout << this_year << "\n";
        cout << ranee << "\n";
    }


    }///





    ///����� ���� �����

/*
        for (int i = 0; i < n+k; i++)
        {
            if (tabl[i].name == "" && tabl[i].x == 0 && tabl[i].y == 0 && tabl[i].type == "" && tabl[i].time == "") continue;
            cout << tabl[i].name << " " << tabl[i].x << " " << tabl[i].y << " " << tabl[i].type << " " << tabl[i].time << "\n";
        }
*////




    return 0;
}
