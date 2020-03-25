//https://www.hackerrank.com/challenges/queens-attack-2/problem
#include <bits/stdc++.h>
#define row(i) os[i][0]
#define col(i) os[i][1]

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> os) {

    int moves = 0;
    //top
    int maxO = 0, minO = n + 1;
    for(int i = 0; i < k ; i++)
    {
        if(col(i) == c_q)
        {
            cout<<"top : "<<row(i)<<" "<<col(i)<<endl;
            if(r_q > row(i))
            {
                if(maxO < row(i))
                    maxO = row(i);
            }
            if(r_q < row(i))
            {
                if(minO > row(i))
                    minO = row(i);
            }
        }
    }
    moves += (minO - maxO) - 2;

    //left
    maxO = 0, minO = n + 1;
    for(int i = 0; i < k ; i++)
    {
        if(row(i) == r_q)
        {
            cout<<"col : "<<row(i)<<" "<<col(i)<<endl;
            if(c_q > col(i))
            {
                if(maxO < col(i))
                    maxO = col(i);
            }
            if(c_q < col(i))
            {
                if(minO > col(i))
                    minO = col(i);
            }
        }
    }
    moves += (minO - maxO) - 2;

    //top-right
    int tr = n+1, tl = 0, br = n + 1, bl = 0; //columns

    for(int i = 0; i < k; i++)
    {
        if( ( (r_q - row(i)) == (col(i) - c_q)) && ((col(i) - c_q) > 0))
        {
            cout<<"br : "<<row(i)<<" "<<col(i)<<endl;
            //br stores max column possible;
            if(br > col(i))
            {
                br = col(i);
            }
        }

        if( ( (row(i) - r_q) == (col(i) - c_q)) && ((col(i) - c_q) > 0) )
        {
            cout<<"tr : "<<row(i)<<" "<<col(i)<<endl;
            //tr;
            if(tr > col(i))
            {
                tr = col(i);
            }
        }

        if( ( (row(i) - r_q) == (c_q - col(i)) ) && ( (c_q - col(i)) > 0) )
        {
            //tl stores column of max possible;
            cout<<"tl : "<<row(i)<<" "<<col(i)<<endl;
            if(tl < col(i))
            {
                tl = col(i);
            }
        }

        if( ( (r_q - row(i)) == (c_q - col(i))) && ((c_q - col(i)) > 0))
        {
            //bl;
            cout<<"bl : "<<row(i)<<" "<<col(i)<<endl;
            if(bl < col(i))
            {
                bl = col(i);
            }
        }
    }

    if(br != (n+1))
        moves += (br - c_q) - 1;
    else
        moves += min(r_q - 1, n - c_q);
    if(tr != (n+1))
        moves += (tr - c_q) - 1;
    else
        moves += min(n - r_q, n - c_q);
    if(tl != 0)
        moves += (c_q - tl) - 1;
    else
        moves += min(n - r_q, c_q - 1);
    if(bl != 0)
        moves += (c_q - bl) - 1;
    else
        moves += min(r_q - 1, c_q - 1);
    
    return moves;
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

    cout << result << "\n";

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
