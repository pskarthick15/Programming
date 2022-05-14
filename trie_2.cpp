#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
	node* links[26];
	int ew,cp;
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
				root->links[i]=NULL;
			}
			root->ew=0;
			root->cp=0;
		}
		
		void insert(string word)
		{
			Node* ptr=root;
			for(int i=0;i<word.size();i++)
			{
				if(ptr->links[word[i]-'a']==NULL)
				{
					ptr->links[word[i]-'a']=new Node();
					ptr=ptr->links[word[i]-'a'];
					ptr->cp++;
				}
				else
				{
					ptr=ptr->links[word[i]-'a'];
					ptr->cp++;
				}
			}
			ptr->ew++;
		}
		
		int count_word(string word)
		{
			Node* ptr=root;
			for(int i=0;i<word.size();i++)
			{
				if(ptr->links[word[i]-'a']==NULL)
				{
					return 0;
				}
				else
				{
					ptr=ptr->links[word[i]-'a'];
				}
			}
			return ptr->ew;
		}
		
		int starts_with(string word)
		{
			Node* ptr=root;
			for(int i=0;i<word.size();i++)
			{
				if(ptr->links[word[i]-'a']!=NULL)
				{
					ptr=ptr->links[word[i]-'a'];
				}
			}
			return ptr->cp;
		}
		
		void erase(string word)
		{
			Node* ptr=root;
			for(int i=0;i<word.size();i++)
			{
				if(ptr->links[word[i]-'a']!=NULL)
				{
					ptr=ptr->links[word[i]-'a'];
					ptr->cp--;
				}
			}
			if(ptr->ew > 0)
			{
				ptr->ew--;
			}
		}
};


int main()
{
	int n;
	cin>>n;
	trie t;
	string q,word;
	for(int i=0;i<n;i++)
	{
		cin>>q>>word;
		if(q=="insert")
		{
			t.insert(word);
		}
		else if(q=="countword")
		{
			cout<<t.count_word(word)<<endl;
		}
		else if(q=="startswith")
		{
			cout<<t.starts_with(word)<<endl;
		}
		else if(q=="erase")
		{
			t.erase(word);
		}
		else
		{
			cout<<"Sorry!Invalid query\n";
		}		
	}
}
	
					
			
