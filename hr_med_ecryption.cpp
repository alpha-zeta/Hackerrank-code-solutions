#include <bits/stdc++.h>

using namespace std;
#include <cmath>
// Complete the encryption function below.
string encryption(string s) {
    vector<char> v;
    for(long unsigned int i=0;i<s.length();i++){
        if(s[i]!=' '){
            v.push_back(s[i]);
        }
    }
    int flr=(int)(sqrt(v.size()));
    int ceil=0;
    float inv=v.size()/(float)(flr);
    if(inv==(float)(flr)){
        ceil=flr;
    }else{
        ceil=flr+1;
    }
    // cout<<v.size()<<","<<ceil<<","<<flr;
    long unsigned int idx=0;
    vector<vector<char>> tmp;
    vector<char> plc;
    while(v.size()>0){
        plc.push_back(v[0]);
        if((idx+1)%ceil==0 || v.size()==1){
            tmp.push_back(plc);
            plc.clear();
        }
        idx=idx+1;
        v.erase(v.begin());
    }
    string res="";
    idx=0;
    long unsigned int num=0;
    while(num<tmp.size()){
        for(long unsigned int i=0;i<tmp.size();i++){
            if(tmp[i].size()!=0){
                res=res+tmp[i][0];
                tmp[i].erase(tmp[i].begin());
            }else{
                num=num+1;
            }
        }
        res=res+" ";
    }
    return(res);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
