#include "graphUI.hpp"

graphUI::graphUI() {}

void graphUI::OperationLoop(void) {
	while (1) {
		cout << "--------------------------------------graph-------------------------------------\n"
			<< "Action :\n"
			<< "r    - read data\n"
			<< "w    - write data\n"
			<< "i    - insert place\n"
			<< "d    - delete place\n"
			<< "a    - add way\n"
			<< "dw   - delete way\n"
			<< "f    - find shortest way\n"
			<< "g    - get place num\n"
			// << "gm   - get place max num\n"
			// << "s    - set place num\n"
			// << "sm   - set place max num\n"
			// << "sr   - show road matrix\n"
			// << "ss   - show sideway matrix\n"
			<< "si   - show info\n"
			<< "q    - quit graph\n"
			<< "--------------------------------------------------------------------------------\n"
			<< "\ngraph :~$ ";
		string op;
		getline(cin, op);
		if (op == "r")
			cout << "\n[read data] " << handleError(myGraph.readData()) << "!\n\n";
		else if (op == "w")
			cout << "\n[write data] " << handleError(myGraph.writeData()) << "!\n\n";
		else if (op == "i") {
			cout << "\n[insert place] [place name]\n"
				<< "[insert place] ";
			string in;
			getline(cin, in);
			stringstream ins(in);
			string a;
			ins >> a;
			cout << "[insert place] " << handleError(myGraph.insertPlace(a)) << "!\n\n";
		}
		else if (op == "d") {
			cout << "\n[delete place] [place name]\n"
				<< "[delete place] ";
			string in;
			getline(cin, in);
			stringstream ins(in);
			string a;
			ins >> a;
			cout << "[delete place] " << handleError(myGraph.deletePlace(a)) << "!\n\n";
		}
		else if (op == "a") {
			cout << "\n[add way] [length of the way] [origin] [destination] [kind of the way]\n"
				<< "[add way] ";
			string in;
			getline(cin, in);
			stringstream ins(in);
			int a;
			string b, c;
			kindOftheWay d;
			ins >> a >> b >> c >> (int&)d;
			cout << "[add way] " << handleError(myGraph.addWay(a, b, c, d)) << "!\n\n";
		}
		else if (op == "dw") {
			cout << "\n[delete way] [origin] [destination]\n"
				<< "[delete way] ";
			string in;
			getline(cin, in);
			stringstream ins(in);
			string a, b;
			ins >> a >> b;
			cout << "[delete way] " << handleError(myGraph.deleteWay(a, b)) << "!\n\n";
		}
		else if (op == "f") {
			cout << "\n[find shortest way] [origin] [destination] [kind of the way]\n"
				<< "[find shortest way] ";
			string in;
			getline(cin, in);
			stringstream ins(in);
			string a, b;
			kindOftheWay c;
			ins >> a >> b >> (int&)c;
			cout << "[find shortest way] " << handleError(myGraph.findShortestWay(a, b, c)) << "!\n\n";
		}
		else if (op == "g")
			cout << "\n[get place num] " << myGraph.getPlaceNum() << "\n\n";
		else if (op == "gm")
			cout << "\n[get place max num] " << myGraph.getPlaceMaxNum() << "\n\n";
		else if (op == "s") {
			cout << "\n[set place num] [place num]\n"
				<< "[set place num] ";
			string in;
			getline(cin, in);
			stringstream ins(in);
			int a;
			ins >> a;
			cout << "[set place num] ";
			myGraph.setPlaceNum(a);
			cout << "!\n\n";
		}
		else if (op == "sm") {
			cout << "\n[set place max num] [place num]\n"
				<< "[set place max num] ";
			string in;
			getline(cin, in);
			stringstream ins(in);
			int a;
			ins >> a;
			cout << "[set place max num] ";
			myGraph.setPlaceMaxNum(a);
			cout << "!\n\n";
		}
		else if (op == "sr") {
			cout << "\n[show road matrix]\n";
			myGraph.showRoadMatrix();
			cout << "\n\n";
		}
		else if (op == "ss") {
			cout << "\n[show sideway matrix]\n";
			myGraph.showSideWayMatrix();
			cout << "\n\n";
		}
		else if (op == "si") {
			cout << "\n[show info] [place name]\n"
				<< "[show info] ";
			string in;
			getline(cin, in);
			stringstream ins(in);
			string a;
			ins >> a;
			cout << "[show info] " << handleError(myGraph.showInfo(a)) << "!\n\n";
		}
		else if (op == "q")
			break;
		else
			cout << "No command '" << op << "' found\n\n";
	}
}

string graphUI::handleError(kindOfError reason) {
	switch (reason) {
	case 0:
		return "Success";
	case 1:
		return "FileError";
	case 2:
		return "MemoryError";
	case 3:
		return "PlaceUndefined";
	case 4:
		return "WayUndefined";
	case 5:
		return "InvalidDistance";
	case 6:
		return "KindOfTheWayUndefined";
	default:
		return "";
	}
}