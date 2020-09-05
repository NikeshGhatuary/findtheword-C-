#include <bits/stdc++.h>

using namespace std;
struct Trie {
   struct Trie *child[26];
   bool endofstring;
};
struct Trie *createNode(void)
{
   struct Trie *tNode = new Trie;
   tNode->endofstring = false;
   for (int i = 0; i < 26; i++)
      tNode->child[i] = NULL;
   return tNode;
}
void insert(struct Trie *root, string key) {
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++) {
      int index = key[i] - 'a';
      if (!curr->child[index])
      {
         curr->child[index] = createNode();
      }
      curr = curr->child[index];
   }
   curr->endofstring= true; //last node as leaf
}
bool search(struct Trie *root, string key) { //check if key is present in trie. If present returns true
   struct Trie *curr = root;
   for (int i = 0; i < key.length(); i++)
        {
      int index = key[i] - 'a';
      if (!curr->child[index])
         return false;
      curr = curr->child[index];
   }
   return (curr != NULL && curr->endofstring);


}

int main()
{
   map<string, int> mp;
   map<string, int>::iterator i;
   struct Trie *root = createNode();
   ifstream file;
   string input,word;
   int number;


    // opening file
    file.open("EnglishDictionary.csv", ios::binary );
    if( file.is_open() )
	{
	    while ( getline (file,input) )
        {
          getline( file, input, ',' );
         //get the text line
         string x=input;
          getline( file, input );	//get the integer
          stringstream ss( input );
         //create a stringstream with the input variable

         insert(root,x);
         if(ss>>number)
            mp[x]=number;
        }

	}
	string s;
	getline(cin,s);
    if(search(root,s))
    {
        i=mp.find(s);
        cout<<"YES, "<<i->second;
    }
    else
        cout<<"NO";
    file.close();
    return 0;
}
