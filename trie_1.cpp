#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
	node* link[26];
	bool flag;
}Node;


class trie
{
	private: Node* root;
	public:
		trie()
		{
			root=new Node();
			for(int i=0;i<26;i++)
			{
				root->link[i]=NULL;
			}
			root->flag=false;
		}
		void insert(string word) /*In case if a particular character is null and is present in the word we look, then only we will
					   Insert it. Then when we come to end of the string the reference of final node kept true.
					   Always we first insert and then create the reference and move there. */
		{
			Node* ptr=root;
			for(int i=0;i<word.size();i++)
			{
				if(ptr->link[word[i]-'a']==NULL)
				{
					ptr->link[word[i]-'a']=new Node();
				}
				ptr=ptr->link[word[i]-'a'];
			}
			ptr->flag=true;
		}
	
		bool search(string word)
		{
			Node* ptr=root;
			for(int i=0;i<word.size();i++)
			{
				if(ptr->link[word[i]-'a']==NULL)
				{
					return false;
				}
				else
				{
					ptr=ptr->link[word[i]-'a'];
				}
			}
			if(ptr->flag==true)// Here after coming till end of trie the flag should be true or string should be present for a hit
				return true;
			else
				return false;
		}
		
		bool startswith(string word)
		{
			Node* ptr=root;
			for(int i=0;i<word.size();i++)
			{
				if(ptr->link[word[i]-'a']==NULL)
				{
					return false;
				}
				else
				{
					ptr=ptr->link[word[i]-'a'];
				}
				if(ptr!=NULL)/*Here as for ex ab and trie is abab then after a and b if the reference of b even exists then
						 we are done.*/
					return true;
			}
		}
};

int main()
{
	trie t;
	int n;
	cout<<"Enter no of queries\n";
	cin>>n;
	int query[n];
	string word;
	for(int i=0;i<n;i++)
	{
		cin>>query[i];
		cin>>word;
		if(query[i]==1)
		{
			t.insert(word);
		}
		else if(query[i]==2)
		{
			if(t.search(word))
			{
				cout<<"Word found\n";
			}
			else
			{
				cout<<"Sorry word not found in given trie\n";
			}
		}
		else if(query[i]==3)
		{
			if(t.startswith(word))
			{
				cout<<"Found word starting with "<<word<<"\n";
			}
			else
			{
				cout<<"Sorry! no word found staring with"<<word<<"\n";
			}
		}
		else
		{
			cout<<"Invalid query!";
		}
	}
}
