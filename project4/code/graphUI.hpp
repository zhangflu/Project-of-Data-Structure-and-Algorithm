/*
*	Copyright (C) 1998-2017 by Zhang Jiqi. All Rights Reserved.
*/

/**
	This class implements an interaction surface for graph objects.

	Example usage of graphUI:

	This is the basic source file "main.cpp" that the graphUI creates within the given program:

		#include "graphUI.hpp"

		int main() {
			graphUI myGraphUI;
			myGraphUI.OperationLoop();
			return 0;
		}

*/

#ifndef GRAPHUI_H
#define GRAPHUI_H

#include <iostream>
#include <sstream>
#include <string>
#include "graph.hpp"

using namespace std;

class graphUI {
public:
	graphUI();
	void OperationLoop(void);

private:
	graph myGraph;
	string handleError(kindOfError reason);
};

#endif