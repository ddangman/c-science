import java.util.Stack;
public class StackTot {

public static void main(String[] args) {

	System.out.println(is_parentheses_balanced("[(1*2)(3*4)]+[(5+6)(7*8)]")); // system input

}

public static boolean matchingPeer(char open , char close){
	if ( open == '(' && close == ')'){
		return true;
	}
	if ( open == '[' && close == ']'){
		return true;
	}
	// you can add more open and close rule

	else{
	return false;
	}
}

public static boolean is_parentheses_balanced(String equation){ // to check if Parentheses valid.

	char[] c = equation.toCharArray();
	Stack <Character> myStack= new Stack <Character> ();

	for (int i = 0; i < c.length; i++){
		if(c[i]=='(' || c[i] == '[' ){
			myStack.push(c[i]);
		}
		else if (c[i]== ')' || c[i]==']'){
				if(matchingPeer(myStack.peek(),c[i]) == true){
					myStack.pop();

				} else {
					return false;
				}
		}
	}
	if(myStack.isEmpty()){
		return true;
	}
	else {
		return false;
	}

}
