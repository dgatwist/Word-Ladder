#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void wordladder(string word1, string word2){
    
    // queue of stacks
    queue<stack<string> > ladderqueue;
    
    //stack that will hold a final word ladder
    stack<string> wordladder;
    
    // stack containing word1 and add it to the queue
    stack<string> ladderstack;
    ladderstack.push(word1);
    ladderqueue.push(ladderstack);
    
    // 2 sets: dictionary and tested words
    string token;
    ifstream file("EnglishWordsFile.txt");
    set<string> dict;
    set<string> testword;
    
    if(file.is_open()) {
      
	      while (file >> token) {
	    	dict.insert(token);
	      }
	      
	      
	      while (!(ladderqueue.empty())) {
	        
	        // dequeue the partial-ladder stack from the front of the queue.
			stack<string> ladder = ladderqueue.front();
			ladderqueue.pop();
			string word = ladder.top();
		        
			// if the word on top of the stack is the destination word:
			if (word == word2) {
			
			  // Output elements of the stack
			  cout << "The path from " << word1 << " to " << word2 << " is \n";
			 
			  //Copy the ladder stack to worldladder to take it in the order.
			  while(!ladder.empty()){
			  	wordladder.push(ladder.top());
			  	ladder.pop();
			  }
			 
			  
			  while(!wordladder.empty()){
			  	cout<<wordladder.top()<<" > ";
			  	wordladder.pop();
			  }
		} 
		else{
			  // valid english neighbor word on top of the stack:
			  string test;
			  for (int i = 0; i < word.size(); i++) {
			    for (char j = 'a'; j <= 'z'; j++) {
			    test = word.substr(0, i) + j + word.substr(i + 1);
		            
			    // if that word is an english word
			    if (dict.count(test)) {
			      
			      // if that neighbor word has not already been used in a ladder before:
			      if (!testword.count(test)) {
				
						// create a copy of the current ladder stack.
						stack<string> copy = ladder;
				                
						// put the neighbor word on top of the copy stack.
						copy.push(test);
				                
						// add the copy stack to the end of the queue.
						ladderqueue.push(copy);
			      }
			    }
		            
			    // Add test to tested words because it is already used.
			    testword.insert(test);
			}
		}
	      }
	       
	    }
    } else {
      cout << "Dictionnary not found\n";
    }
    
    
}
int main() {
    
  string word1, word2;
 
  	
  ifstream file("EnglishWordsFile.txt");
    string line;
    bool tag=false;
  
  cout << "Input the first word: ";
    cin>>word1;
    
    
    
    	if(file)
    {
        while(getline(file, line))
        {
            if(line == word1)
            
            {
            	tag=true;
            	break;
        }
      
    }
    if(tag==false)
    cout<<word1<<" is not in the dictionary\n";
}

            	 if(tag==true)
            	{
            		cout << "Input a second word of the same size: ";
    				cin>>word2;
    				if (word1.length() != word2.length()) {
      					
    					
    cout << "The words inputted are not of the same size" << endl;
			}
			
			
			
    				
			if(file)
    {
    
        while(getline(file, line))
        {
            if(line == word2)
            
            {
            	tag=true;
            	break;
        }
      
    }
    if(tag==false)
    cout<<word2<<" is not in the dictionary\n";
}
                
            }
            
            


  wordladder(word1, word2);
    
  return 0;
}


