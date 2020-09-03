
#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;
/**

struct Trie {
    int row,col;
    Trie* child[26];
    int isEnd;
};

struct Trie* makeNode() {
    struct Trie* pnode = new Trie;
    for(int i=0; i<26; i++) {
        pnode->child[i] = NULL;
    }
    pnode->isEnd = 0;

    return pnode;
}

void insert(struct Trie *root, string key, int row, int col) 
{ 
    struct Trie *pCrawl = root; 
    
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->child[index]) 
            pCrawl->child[index] = makeNode(); 
  
        pCrawl = pCrawl->child[index]; 
    } 
    pCrawl->row = row;
    pCrawl->col = col;
    pCrawl->isEnd = 1; 
}


void search(struct Trie *root, string word) {
    struct Trie *pc = root;
    vector<string> s;
    for(int i=0; i<word.length(); i++) {
        int index = word[i] - 'a';
        if(!pc->child[index])
            return;
        pc = pc->child[index];
    }
    if(pc->isEnd) {
        cout<<pc->row<<" "<<pc->col<<endl;
    }
}
**/


vector<string> wordfind(vector<string> s, vector<string> wf) {

    vector<string> index;

    int n = s.size();
    int m = s[0].size();

    for(int wordfind = 0; wordfind < wf.size(); wordfind++) {
        int found = 0;
        string wordsearch = wf[wordfind];
        int length = wordsearch.size();
        
        string sk;
        int row,col;
        for(row = 0; row<n; row++) {
            for(col = 0; col<m; col++) {
                string word;
                //to right
                if(col+length-1<m) word = s[row].substr(col, length);
                if(wordsearch == word) {
                    found = 1;
                }

                ///to down
                if(row+length-1 < n)
                 {
                     string ss;
                     for(int ii = row; ii<row + length; ii++) {
                         ss += s[ii][col];
                     }
                     if(wordsearch == ss) {
                         found = 1;
                     }
                 }

                 //to down-right               
                if(row+length-1<n && col+length-1<m) {
                    string ss;  
                    for(int ii = row, jj = col; ii<row + length; ii++, jj++) ss+= s[ii][jj];
                    if(wordsearch == ss) {
                        found = 1;
                    }
                }
                
                if(found) {
                    sk += to_string(row);
                    sk += " ";
                    sk += to_string(col);
                    row = n;
                    col = m;
                }
            }
            
        }
        index.push_back(sk);
    }
        return index;
}

int32_t main()
{
    int t = 1;
    //cin>>t;
    while(t--) {
        //down -> right -> d-r
        

        vector<string> s = 	
{"EASYTOFINDEAGSRVHOTCJYG",
 "FLVENKDHCESOXXXXFAGJKEO",
 "YHEDYNAIRQGIZECGXQLKDBI",
 "DEIJFKABAQSIHSNDLOMYJIN",
 "CKXINIMMNGRNSNRGIWQLWOG",
 "VOFQDROQGCWDKOUYRAFUCDO",
 "PFLXWTYKOITSURQJGEGSPGG"};

        vector<string> wf = {"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"};

        vector<string> sk = wordfind(s, wf);

        for(int i=0; i<sk.size(); i++) {
            cout<<wf[i]<<" "<<sk[i]<<endl;
        }




        // grid = [boat
        //         coat
        //         loat]

        // wordList = [boat, coat]

        // n = grid.size()   --> rows
        // m = grid[0].size() --> cols

        //find oa  --> ((0, 1), (1,1), (1,1), (2,1))  and anser is 0,1


    }
    

    return 0;
}
