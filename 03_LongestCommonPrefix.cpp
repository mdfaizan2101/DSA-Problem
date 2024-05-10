#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";

    //for traversing all characters of first string 
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];

        bool match = true;

        //for comparing ch with rest of the string 
        for (int j = 1; j < n; j++)
        {
            //not match
            if(arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()
{
    vector<string> arr = {"night", "ninja", "nightmare", "nil"};
    int n = 4;

    string ans = longestCommonPrefix(arr, n);

    cout << "Longest Common Prefix: " << ans << endl;
    
    return 0;
}








// #include<bits/stdc++.h>
// using namespace std;

// class TrieNode
// {
//     public:
//         char data;
//         TrieNode* children[26];
//         int childcount;
//         bool isTerminal;

//         TrieNode(char ch)
//         {
//             data = ch;
//             for (int i = 0; i < 26; i++)
//             {
//                 children[i] = NULL;
//             }
//             childcount = 0;
//             isTerminal = false;
//         }
// };

// class Trie 
// {
//     public:
//     TrieNode* root;

//     Trie()
//     {
//         root = new TrieNode('\0');
//     }

//     void insertUtil(TrieNode*root, string word)
//     {
//         //base case
//         if (word.length() == 0)
//         {
//             root -> isTerminal = true;
//             return;
//         }
        
//         // assumption ,word will be in lowercase
//         int index = word[0] - 'a';
//         TrieNode* child;

//         // present
//         if (root -> children[index] != NULL)
//         {
//             child = root -> children[index];
//         }
//         else // absent
//         {
//             child = new TrieNode(word[0]);
//             root -> childcount++;
//             root -> children[index] = child;
//         }
//         //RECURSION
//         insertUtil(child, word.substr(1));
//     }

//     void insertWord(string word)
//     {
//         insertUtil(root, word);
//     }

//     void lcp(string str, string &ans)
//     {
//         for (int i = 0; i < str.length(); i++)
//         {
//             char ch = str[i];

//             if (root -> childcount == 1)
//             {
//                 ans.push_back(ch);
//                 int index = ch - 'a';
//                 root = root -> children[index];
//             }
//             else
//             {
//                 break;
//             }
//             if (root -> isTerminal)
//             {
//                 break;
//             }
//         }
//     }
// };


// string longestCommonPrefix(vector<string> &arr, int n)
// {
//     Trie *t = new Trie();

//     for (int i = 0; i < n; i++)
//     {
//         t -> insertWord(arr[i]);
//     }
    
//     string first = arr[0];
//     string ans = "";

//     t -> lcp(first, ans);

//     return ans;
// }

// int main()
// {
//     vector<string> arr = {"faiz", "faiz", "faiz", "faiz"};
//     int n = 4;

//     string ans = longestCommonPrefix(arr, n);

//     cout << "Longest Common Prefix: " << ans << endl;
    
//     return 0;
// }