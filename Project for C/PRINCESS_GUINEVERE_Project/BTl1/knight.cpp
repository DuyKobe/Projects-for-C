#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout<< "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
int Fibonacci(int n)
{
    if (n < 0) {
        return -1;
    }
    else if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int Fibonacci_MushFibo(int HP){
    int i = 1;
    while(Fibonacci(i)<=HP){
        i++;
    }
   return HP = Fibonacci(i-1);
}
bool is_nguyento(int n){
        if (n < 2)    
        return 0;

    for (int i = 2; i <= sqrt((float)n); i ++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}
void getdata(string file_input, string & str1,string & str2,string & str3,string & str3_1,string & str3_2,string & str3_3){
     fstream new_file;
    new_file.open(file_input,ios::in);
    if(new_file.is_open())
    {
        getline(new_file,str1);
        getline(new_file,str2);
        getline(new_file,str3);
    }
        str3_1 = str3.substr(0,str3.find(","));
	    str3_2 = str3.substr(str3.find(",")+1,str3.find(",",str3.find(",")+1)-(str3.find(",")+1));
	    str3_3 = str3.substr(str3.find(",",str3.find(",")+1)+1,str3.size()-str3.find(",",str3.find(",")+1));
    }
void str2char(int* mang, string str){
    int s1=0,i,n=0;
    bool is_am = false;
    for(i = 0;i<str.size();i++){
        if(str[i]=='-'){
            is_am = true;
        }
        if(str[i]<='9'&&str[i]>='0'){
            s1 = s1*10 + str[i]-48;
        }
        if(str[i]==','||str[i]==' '){
            if(is_am==true){
                mang[n++] = 0-s1;
                is_am=false;
            }else{
                mang[n++] = s1;
            }
            
            s1=0;
        }
    }
    mang[n] = s1;
}
int Loai1(int* n2,int n2_num){
    int i;
    int min_vitri=0,max_vitri=0;
    int min = n2[0],max=n2[0];
    for(i=1;i<n2_num;i++){
        if(n2[i]<min){
            min = n2[i];
            min_vitri = i;
        }
        if(n2[i]>max){
            max = n2[i];
            max_vitri=i;
        }
    }
    return max_vitri+min_vitri;
}
int Loai2(int* n2,int n2_num){
    bool is_nui = true;
    int i;
    int max_vitri=0,max=n2[0];
    for(i=0;i<n2_num;i++){
        if(n2[i]>=max){
            max = n2[i];
            max_vitri = i;
        }
    }
    for(i=max_vitri;i>0;i--){
        if(n2[i]-n2[i-1]<=0){
            is_nui = false;
        }
    }
    for(i=max_vitri;i<n2_num-1;i++){
        if(-n2[i]+n2[i+1]>=0){
            is_nui = false;
        }
    }
        if(is_nui==true){
            return max+max_vitri;
        }else{
            return -5;
        }
    
}
int Loai3(int* n2,int n2_num){
    int a[n2_num],i;
    for(i=0;i<n2_num;i++){
        if(n2[i]<0){
            a[i] = (17 * (0-n2[i]) + 9)%257;
        }else{
            a[i] = (17 * n2[i] + 9)%257;
        }
    }
    return Loai1(a,n2_num);

}
int Loai4(int* n2,int n2_num){
    int a[n2_num],i;
    for(i=0;i<n2_num;i++){
        if(n2[i]<0){
            a[i] = (17 * (0-n2[i]) + 9)%257;
        }else{
            a[i] = (17 * n2[i] + 9)%257;
        }
    }
    int max=a[0],maxi=0;
    for(i=1;i<3;i++){
        if(a[i]>max){
            max=a[i];
            maxi=i;
        }
    }
    int max2=0,max2i=0;
    for(i=0;i<3;i++){
        if(a[i]<max&&a[i]>max2){
            max2 = a[i];
            max2i = i;
        }
    }
    if(max2==0){
        return -12;
    }else{
        return max2+max2i;
    }
}
void MushGhost(string str3_1,int mission,int & HP,int & phoenixdown, int MaxHP){
    string str1,str2;
    fstream new_file;
    new_file.open(str3_1+".txt",ios::in);
    if(new_file.is_open())
    {
        getline(new_file,str1);
        getline(new_file,str2);
    }
    //xu ly file
    int i,n2_num=0;
    for(i=0;i<str1.size();i++){
        n2_num = n2_num*10 + (str1[i]-48);
    }
    int n2[n2_num];
    //xulystr2
    str2char(n2,str2);
    
    int mission_num=0;
    int mission_t=mission;
	while(mission_t>0){
		mission_t = mission_t/10;
		mission_num++;
	}
	mission_num=mission_num-2;
	mission = mission - 13*pow(10,mission_num);
	char mission_str[mission_num];
	sprintf(mission_str, "%d\n", mission);
    
    
    //xuly
    for(int i=0;i<mission_num;i++){
        if(mission_str[i]=='1'){
            HP = HP - Loai1(n2,n2_num);
        }
        if(mission_str[i]=='2'){
            HP = HP - Loai2(n2,n2_num);
        }
        if(mission_str[i]=='3'){
            HP = HP - Loai3(n2,n2_num);
        }
        if(mission_str[i]=='4'){
            HP = HP - Loai4(n2,n2_num);
        }
        if(HP<0){
            if(phoenixdown>0){
                HP = MaxHP;
                phoenixdown--;
            }else{
                break;
            }
        }
        if(HP>MaxHP){
            HP = MaxHP;
        }

    }

}
int MushMario(int level,int phoenixdown,int HP){
    int n1 = ((level + phoenixdown)%5 + 1) * 3;
    int s1 = 0,i;
    for(i=99;i>0;i=i-2){
        if(n1==0){
            break;
        }
        s1 = s1 + i;
        n1--;
    }
    HP = HP + (s1%100);
    while(is_nguyento(HP)!=true){
        HP++;
    }
    return HP;
}
void AAsclepius(string str3_2,int & remedy,int & maidenkiss,int & phoenixdown){
    string str1,str2,str;
    int r1_num,c1_num;
    fstream new_file;
    new_file.open(str3_2+".txt",ios::in);
    if(new_file.is_open())
    {
        getline(new_file,str1);
        getline(new_file,str2);
        int i,s=0;
    for(i=0;i<str1.size();i++){
        s = s*10 + str1[i]-48;
    }
    r1_num = s;s=0;
    for(i=0;i<str2.size();i++){
        s = s*10 + str2[i]-48;
    }
    c1_num = s;s=0;
    int luot=3;
    int j;
    int pack[c1_num];
    for(j=0;j<r1_num;j++){
        getline(new_file,str);
        str2char(pack,str);
        for(i=0;i<c1_num;i++){
            if(luot == 0){
                luot=3;
                break;
            }else{
                switch (pack[i])
                {
                case 16:
                    remedy++;
                    if(remedy>99){
                        remedy=99;
                    }
                    luot--;
                    break;
                case 17:
                    maidenkiss++;
                    if(maidenkiss>99){
                        maidenkiss=99;
                    }
                    luot--;
                    break;
                case 18:
                    phoenixdown++;
                    if(phoenixdown>99){
                        phoenixdown=99;
                    }
                    luot--;
                    break;
                }
            }
        }
    }
    }

}
void MMerlin(string str3_3,int & HP,int MaxHP){
    string str1;
    fstream new_file;
    new_file.open(str3_3+".txt",ios::in);
    if(new_file.is_open())
    {
        getline(new_file,str1);
        int i,s=0;
    for(i=0;i<str1.size();i++){
        s = s*10 + str1[i]-48;
    }
    int n9 = s;s=0;
    string str;
    for(i=0;i<n9;i++){
        getline(new_file,str);
        if((str.find('m')<str.size()||str.find('M')<str.size())&&(str.find('e')<str.size()||str.find('E')<str.size())&&(str.find('r')<str.size()||str.find('R')<str.size())&&(str.find('l')<str.size()||str.find('L')<str.size())&&(str.find('i')<str.size()||str.find('I')<str.size())&&(str.find('n')<str.size()||str.find('N')<str.size())){
            if(str.find("Merlin")<str.size()||str.find("merlin")<str.size()){
                HP = HP + 3;
            }else{
                HP = HP + 2;
            }
            if(HP > MaxHP){
                HP = MaxHP;
            }
        }
    }
    }
}
void chiso(string str1,int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue ){
int s=0,i=0,solan=0;
    for(i=0;i<str1.size();i++){
        if(str1[i]==' '){
            if(solan==0){
                HP = s;
            }
            if(solan==1){
                level = s;
            }
            if(solan==2){
                remedy = s;
            }
            if(solan==3){
                maidenkiss = s;
            }
            s=0;
            solan++;
        }else{
        s = s*10 + (str1[i]-48);
        if(i==str1.size()-1){
            phoenixdown = s;
        }
        }
    }
    
    rescue = -1;
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    string str1,str2,str3,str3_1,str3_2,str3_3;
    getdata(file_input,str1,str2,str3,str3_1,str3_2,str3_3);
    chiso(str1,HP,level,remedy,maidenkiss,phoenixdown,rescue);
      int mission_number=0,i;
    for(i=0;i<str2.size();i++){
        if(str2[i]==' '||str2[i]=='\0'){
            mission_number++;
        }
    }
        mission_number++;
        int mission[mission_number];
        str2char(mission,str2);
        int levelO = 0,MaxHP=HP;
        bool Arthur = false,Lancelot = false;
        if(HP ==999){
            Arthur = true;
        }
        if(is_nguyento(HP)==true){
            Lancelot = true;
        }
        double basedamage,damage;
        bool Tihon = false, Frog  = false,Asclepius = false,Merlin = false;
        int tihon_num = 4,Frog_num = 4;
        int level_curent;
        for(i=0;i<mission_number;i++){
            //display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            //Merlin
            if(mission[i]==18){
                if(Merlin == false){
                    MMerlin(str3_3,HP,MaxHP);
                    Merlin = true;
                }
            }
            //Asclepius
            if(mission[i]==19){
                if(Asclepius == false){
                AAsclepius(str3_2,remedy,maidenkiss,phoenixdown);
                Asclepius = true;
                }
            }
            // hieu ung 
            if(Tihon == true && tihon_num > 0){
                tihon_num--;
                if(remedy>0){
                    tihon_num = 0;
                    remedy--;
                }
            }
            if(Frog  == true && Frog_num  > 0){
                Frog_num--;
                if(maidenkiss>0){
                    Frog_num = 0;
                    maidenkiss--;
                }
            }
            if(Frog  == true && Frog_num == 0){
                Frog  = false;
                level = level_curent;
                Frog_num = 4;
            }
            if(Tihon == true && tihon_num== 0){
                Tihon =false;
                HP = HP*5;
                if(HP>=MaxHP){
                HP = MaxHP;
                }
                tihon_num = 4;
            }
            ///////nhat do
            if(mission[i]==15){
                remedy++;
                if(remedy>=99){
                    remedy=99;
                }
                continue;
            }
            if(mission[i]==16){
                maidenkiss++;
                if(maidenkiss>=99){
                    maidenkiss=99;
                }
                continue;
            }
            if(mission[i]==17){
                phoenixdown++;
                if(phoenixdown>=99){
                    phoenixdown=99;
                }
                continue;
            }
            if(mission[i]==12){
                if(HP!=1){
                    HP = Fibonacci_MushFibo(HP);
                }
                continue;
            }
            if(mission[i]==11){
                HP = MushMario(level,phoenixdown,HP);
                if(HP >= MaxHP){
                    HP = MaxHP;
                }
                continue;
            }
            if(mission[i]>100){ // mission 13
                MushGhost(str3_1,mission[i],HP,phoenixdown,MaxHP);
            }
            // phan loai
            if(mission[i]==0){
                rescue = 1;
            }
            if((Tihon == true )&&(mission[i]==6||mission[i]==7)){
                continue;
            }
            if((Frog  == true )&&(mission[i]==6||mission[i]==7)){
                continue;
            }
            if(mission[i]== 99){
                if(Arthur==true||(Lancelot==true && level>=8)||level == 10){
                    level = 10;
                }else{
                    rescue = 0;
                }
            }
            if(mission[i]<=5&&mission[i]>=1){
                switch(mission[i]){
                    case 1:
                        basedamage = 1;break;
                    case 2:
                        basedamage = 1.5;break;
                    case 3:
                        basedamage = 4.5;break;
                    case 4:
                        basedamage = 7.5;break;
                    case 5:
                        basedamage = 9.5;break;
                        
                }
            }
            if(mission[i]>=1&&mission[i]<=7){
            levelO =  (i+1) > 6?(((i+1) % 10) > 5?((i+1) % 10): 5) : ((i+1) % 10);
                if(level>levelO ||Arthur == true||Lancelot == true){
                    if(mission[i]==6||mission[i]==7){
                    level = level + 2;
                    }else{
                        level++;
                    }
                    if(level>=10){
                        level=10;
                    }
                }
                if(level<levelO && (Arthur==false||Lancelot==false)){
                    if(mission[i]==6){
                        if(remedy<=0){
                        Tihon = true;
                        if(HP<5){
                            HP = 1;
                        }else{
                            HP = HP/5;
                        }
                        }else{
                            remedy--;
                        }
                    }else if(mission[i]==7){
                        if(maidenkiss<=0){
                        Frog = true;
                        level_curent = level;
                        level = 1;
                        }else{
                            maidenkiss--;
                        }
                        }else{
                    damage = basedamage*levelO*10;
                    HP=HP-damage;
                    }
                }
        }
            if(HP<=0){
                    if(phoenixdown>=1){
                        HP = MaxHP;
                        Tihon = false;
                        phoenixdown--;
                    }else{
                        rescue = 0;
                    }
                }
            if(rescue!=-1){
                break;
            }
            if(i<mission_number-1){
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
       }
       if(HP>0 && rescue==-1){
        rescue = 1;
       }
       if(Frog  == true ){
                Frog  = false;
                level = level_curent;
                Frog_num = 4;
            }
            if(Tihon == true ){
                Tihon =false;
                HP = HP*5;
                if(HP>=MaxHP){
                HP = MaxHP;
                }
                tihon_num = 4;
            }
    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    
    
}

