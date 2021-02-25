#include <bits/stdc++.h>
typedef long unsigned int lui;
using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int atk=((n-1)*2)+std::min(c_q-1,r_q-1)+std::min(c_q-1,n-r_q)+std::min(r_q-1,n-c_q)+std::min(n-c_q,n-r_q);
    int blk=0;
    int unl[]={0,0,0,0,0,0,0,0};
    for(lui i=0;i<obstacles.size();i++){
        vector<int> obj=obstacles[i];
        if(obj[1]==c_q){
            if(obj[0]>r_q){
                blk=(n-obj[0]+1);
                if(blk>unl[3]){
                    unl[3]=blk;
                }
            }else{
                blk=obj[0];
                if(blk>unl[2]){
                    unl[2]=blk;
                }
            }
        }
        else if(obj[0]==r_q){
            if(obj[1]>c_q){
                blk=(n-obj[1]+1);
                if(blk>unl[1]){
                    unl[1]=blk;
                }
            }else{
                blk=obj[1];
                if(blk>unl[0]){
                    unl[0]=blk;
                }
            }
        }else if(std::abs(obj[0]-r_q)==std::abs(obj[1]-c_q)){
            if(obj[0]>r_q && obj[1]>c_q){
                blk=std::min(n-r_q,n-c_q)-std::abs(obj[1]-c_q)+1;
                if(blk>unl[6]){
                    unl[6]=blk;
                }
            }else if(obj[0]>r_q && obj[1]<c_q){
                blk=std::min(n-r_q,c_q-1)-std::abs(obj[1]-c_q)+1;
                if(blk>unl[5]){
                    unl[5]=blk;
                }
            }
            else if(obj[0]<r_q && obj[1]>c_q){
                blk=std::min(r_q-1,n-c_q)-std::abs(obj[1]-c_q)+1;
                if(blk>unl[7]){
                    unl[7]=blk;
                }
            }
            else if(obj[0]<r_q && obj[1]<c_q){
                blk=std::min(r_q-1,c_q-1)-std::abs(obj[1]-c_q)+1;
                if(blk>unl[4]){
                    unl[4]=blk;
                }
            }
        }
    }
    int sum = 0;
    sum = accumulate(unl, unl+8, sum);
    atk=atk-sum;
    return(atk);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
