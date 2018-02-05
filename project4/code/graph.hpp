#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
#define Infinity 1000000
using namespace std;
const int MAXN = 100;

struct place
{
	string placeName;
	string info;
	int key;
};

enum kindOftheWay  {road = 0 , sideway = 1};
enum kindOfError {success = 0, fileError = 1, memoryError = 2, placeUndefined = 3, wayUndefined = 4, invalidDistance = 5, kindOftheWayUndefined = 6};

class graph{
    public:
        graph();
        kindOfError readData();
		kindOfError writeData();
		kindOfError insertPlace(string placeName);
		kindOfError deletePlace(string placeName);
		kindOfError addWay(int lengthOftheWay, string origin, string destination, kindOftheWay kind);
		kindOfError deleteWay(string origin, string destination);
		kindOfError findShortestWay(string origin, string destination, kindOftheWay kind);
		int getPlaceNum();
		int getPlaceMaxNum();
		void setPlaceNum(int placeNum);
		void setPlaceMaxNum(int placeMaxNum);
		void showRoadMatrix();
		void showSideWayMatrix();
		kindOfError showInfo(string placeName);

	private:
		void dijstra_road(int origin,int destination);
		void dijstra_sideway(int origin,int destination);
		//vector<vector<int> > dijstra_route;
		// vector <int> road[MAXN];
		// // bool visited[MAXN];
		// set <int> s;
		// // int dijstra_result[MAXN];
		// int dis[MAXN];
		int findIndexOfthePlace(string placeName);
		string findNameOfthePlace(int placeIndex);
		int placeNum;
		int placeMaxNum;
		vector<place> places;
        int roadMatrix[MAXN][MAXN];
        int sidewayMatrix[MAXN][MAXN];
};