#include<iostream>
#include<stack>
#include<string>
#include<vector>

void Return(std::vector<std::string>& vec) {
	std::stack<std::string>st;
	for (auto ve : vec) {
		if (ve != "*" && ve != "/" && ve != "+" && ve != "-" && ve != "(" && ve != ")") {
			std::cout << ve << "  ";
		}
		else {
			/*
			—π»Î‘ÀÀ„∑˚ < ’ª∂• ≥ˆ’ª
			—π»Î‘ÀÀ„∑˚ > ’ª∂• »Î’ª
			*/
			if (st.empty()) {
				st.push(ve);
			}
			else if (st.top() == "(") {
				st.push(ve);
			}
			else if ((ve == "-" || ve == "+") && (st.top() == "*" || st.top() == "/" || st.top() == "-" || st.top() == "+")) {
				while (!st.empty() && (st.top() == "*" || st.top() == "/" || st.top() == "-" || st.top() == "+")) {
					std::cout << st.top() << "  ";
					st.pop();
				}
				st.push(ve);
			}
			else if ((ve == "*" || ve == "/") && (st.top() == "-" || st.top() == "+")) {
				st.push(ve);
			}
			else if ((ve == "*" || ve == "/") && (st.top() == "*" || st.top() == "/")) {
				while (!st.empty() && (st.top() == "*" || st.top() == "/")) {
					std::cout << st.top() << "  ";
					st.pop();
				}
				st.push(ve);
			}
			else if (ve == ")") {
				while (st.top() != "(") {
					std::cout << st.top() << "  ";
					st.pop();
				}
				st.pop();
			}
		}
	}
	while (!st.empty()) {
		std::cout << st.top() << "  ";
		st.pop();
	}
}
int main() {
	std::vector<std::string>vec;
	//vec.push_back(std::to_string(21));
	vec.push_back("a");
	vec.push_back("+");
	vec.push_back("b");
	vec.push_back("*");
	vec.push_back("c");
	vec.push_back("-");
	vec.push_back("d");
	Return(vec);
	return 0;
}