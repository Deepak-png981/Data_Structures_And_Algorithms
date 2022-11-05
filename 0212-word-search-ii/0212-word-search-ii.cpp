class Solution
{ 
    struct TrieNode
        {
            bool isEnd;
            string word;
            TrieNode *child[26];
            TrieNode()
            {
                isEnd = false;
                word = "";
                for (int i = 0; i < 26; i++)
                    child[i] = NULL;
            }
        };
    private:
    //global result vector to store all strings which are present in board
    vector<string> res;
   	//direction array to move
    vector<int> dx = { -1,
        0,
        1,
        0
    };
    vector<int> dy = { 0,
        1,
        0,
        -1
    };

    public:
       
   	//declaring the global root for the trienode
    TrieNode *root = new TrieNode();
    
   	//function to insert in the TRIE;
    void insert(string & word)
    {
       	//size of the string
        int n = word.length();
       	//creating a new node
        TrieNode *curr = root;
       	//traversing through the word
        for (int i = 0; i < n; i++)
        {
            int indx = word[i] - 'a';
           	//if no child or similar subtrie is present then insert it
            if (curr->child[indx] == NULL)
            {
                curr->child[indx] = new TrieNode();
            }
            curr = curr->child[indx];
        }
        curr->isEnd = true;
        curr->word = word;
    }

  
   	// dfs
    void dfs(vector<vector < char>> &grid, int i, int j, int n, int m, TrieNode *curr)
    {
       	//base case
        if (i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == '#')
            return;

        int inx = grid[i][j] - 'a';
       	// if there is no word starting with current character then return
        if (curr->child[inx] == NULL)
        {
            return;
        }
       	//if exist then move curr
        curr = curr->child[inx];
       	//if a word is found
        if (curr->isEnd)
        {
            res.push_back(curr->word);
           	//now mark its isEnd as false
            curr->isEnd = false;
        }
       	//storing the character to use it further after coming back from the recursion
        char tmpval = grid[i][j];
        grid[i][j] = '#';
        for (int k = 0; k < 4; k++)
        {
            int newi = i + dx[k];
            int newj = j + dy[k];
           	//now calling dfs for different different directions
            dfs(grid, newi, newj, n, m, curr);
        }
       	//after coming back from recursion we are backtracking
        grid[i][j] = tmpval;
    }
    vector<string> findWords(vector<vector < char>> &grid, vector< string > &words)
    {
        int n = grid.size();
        int m = grid[0].size();
       	//inserting words into the trie
        for (auto it: words)
        {
            insert(it);
        }
         for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dfs(grid, i, j, n, m, root);
            }
        }

        return res;
    }
};