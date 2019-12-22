#include <iostream>
#include <vector>
#include <fstream>

#define GOAL_OUTPUT 19690720

using namespace std;

// Func declarations
void loadOpcodes(vector<int>&);
void execute(vector<int>&);
void reset(vector<int>&, int, int);

int main() {
	// init program memory 
	vector<int> memory;
	// test values of N, M until match is found
	bool found = false;
	for (int N = 0; N <= 99 && !found; N++) {
		for (int V = 0; V <= 99 && !found; V++) {
			reset(memory, N, V);
			execute(memory);
			if ((found = (memory[0] == GOAL_OUTPUT))) {
				cout << "N: " << N << ", V: " << V << "\n";
				cout << "100N + V: " << 100 * N + V << "\n";
			}
		}
	}
	return 0;
}

// reset "program memory"
void reset(vector<int>& memory, int N, int V) {
	memory.clear();
	loadOpcodes(memory);
	memory[1] = N;
	memory[2] = V;
}

// load opcodes into memory
void loadOpcodes(vector<int>& memory) {
	ifstream file;
	file.open("input");
	int opcode;
	while (file >> opcode) {
		memory.push_back(opcode);
	}
}

// execute instructions currently in memory
void execute(vector<int>& memory) {
	for (int code = 0; code < memory.size(); code += 4) {
		// break out instruction components
		int instruc = memory[code];
		int argOne = memory[code + 1];
		int argTwo = memory[code + 2];
		int dest = memory[code + 3];
		// check for halt code
		if (instruc == 99)
			break;
		// addition or subtraction
		memory[dest] = (instruc == 1) ? memory[argOne] + memory[argTwo] :
		memory[argOne] * memory[argTwo];
	}
}
