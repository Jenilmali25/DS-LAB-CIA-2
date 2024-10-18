#include<iostream>
#include<stack>
using namespace std;

int prec(char c){
	if(c=='^')
		return 3;
	else if(c=='/' || c=='*')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else 	
		return -1;
}

void postfix(string s){
	stack<char> st;
	string result;
	
	for(int i=0; i<s.length(); i++){
		char c = s[i];
			
	//if scanned is a alphanum??
	if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
			result+=c;
    
    else if(c=='(')
      st.push('(');
				
	else if(c==')'){
		  while(!st.empty() && st.top()!='('){
		    result+=st.top();
		    st.pop();
		  }
		  st.pop();
		}
		
	else{
        while(!st.empty() && prec(s[i]) <= prec(st.top())){
         result+=st.top();
	    st.pop();
	} 
		 st.push(c);
		}
		
		
		
		
	}
	while(!st.empty()){
		  result+=st.top();
		  st.pop();
		}
	cout<<"Postfix Expression: "<<result<<endl;
}

int main(){
	string infix;
	cout<<"Enter Infix: ";
	cin>>infix;
	postfix(infix);
	
	return 0;
}
