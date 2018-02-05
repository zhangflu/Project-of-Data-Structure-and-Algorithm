#include "graph.hpp"
#include <fstream>
graph::graph(){
	placeNum = 0;
	for(int i = 0;i<MAXN;i++){
		for(int j = 0;j<MAXN;j++){
			roadMatrix[i][j] = Infinity;
			sidewayMatrix[i][j] = Infinity;
		}
	}
}

kindOfError graph::readData()
{
	ifstream rPlacefile("placeData.txt");
	int number;
	rPlacefile >> number;
	placeMaxNum = number;
	string placeName,info;
	place newPlace;
	while(rPlacefile >> placeName >> info){
		//cout << placeName << info << endl;
		newPlace.placeName = placeName;
		newPlace.info = info;
		newPlace.key = getPlaceNum();
		places.push_back(newPlace);
		setPlaceNum(getPlaceNum()+1);
	}
	rPlacefile.close();

	ifstream rWayFile("wayData.txt");
	int origin,destination,distance,kindOfWay;
	while(rWayFile >> origin >> destination >> distance >> kindOfWay){
		if(kindOfWay == 0){
			roadMatrix[origin][destination] = distance;
			roadMatrix[destination][origin] = distance;
			sidewayMatrix[origin][destination] = distance;
			sidewayMatrix[destination][origin] = distance;
		}
		else if(kindOfWay == 1){
			sidewayMatrix[origin][destination] = distance;
			sidewayMatrix[destination][origin] = distance;
		}
		else{
			return kindOftheWayUndefined;
		}
	}
	rWayFile.close();
	return success;
}

kindOfError graph::writeData()
{
	ofstream wPlacefile("placeData.txt");
	wPlacefile << placeMaxNum << endl;
	for(int i = 0;i<places.size();i++){
		wPlacefile << places[i].placeName << " " << places[i].info<<endl;
	}
	wPlacefile.close();

	ofstream wWayfile("wayData.txt");
	for(int i = 0;i<placeMaxNum;i++){
		for(int j = i;j<placeMaxNum;j++){
			if(sidewayMatrix[i][j] < Infinity && roadMatrix[i][j] < Infinity){
				wWayfile << i << " " << j << " " << sidewayMatrix[i][j] << " "<< "0"<<endl;
			}
			else if(sidewayMatrix[i][j] < Infinity){
				wWayfile << i << " " << j << " " << sidewayMatrix[i][j] << " "<<"1"<<endl;
			}
		}
	}
	wWayfile.close();
	return success;
}

kindOfError graph::insertPlace(string placeName)
{
	place newPlace;
	string info;
	cout <<"Please input the infomation of the place" << endl;
	cin >> info;
	newPlace.placeName = placeName;
	newPlace.info = info;
	newPlace.key = getPlaceMaxNum();
	places.push_back(newPlace);
	setPlaceNum(getPlaceNum()+1);
	setPlaceMaxNum(getPlaceMaxNum()+1);
	return success;
}
kindOfError graph::deletePlace(string placeName)
{
	int key = -1;
	for(vector<place>::iterator it = places.begin();it!=places.end();){
		if(it->placeName == placeName){
			key = it->key;
			it = places.erase(it);
			setPlaceNum(getPlaceNum()-1);
		}
		else{
			it++;
		}
	}
	if(key == -1){
		return placeUndefined;
	}
	else{
		for(int i = 0;i<getPlaceMaxNum();i++){
			for(int j = 0;j<getPlaceMaxNum();j++){
				if(i==key || j==key){
					roadMatrix[i][j] = Infinity;
					sidewayMatrix[i][j] = Infinity;
				}
			}
		}
	}
	return success;
}
kindOfError graph::addWay(int distance, string originName, string destinationName, kindOftheWay kind)
{
	if(distance < 0){
		return invalidDistance;
	}
	int origin = findIndexOfthePlace(originName);
	int destination = findIndexOfthePlace(destinationName);
	if(origin == -1 || destination == -1){
		return placeUndefined;
	}
	if(kind == 0){
		roadMatrix[origin][destination] = distance;
		roadMatrix[destination][origin] = distance;
		sidewayMatrix[origin][destination] = distance;
		sidewayMatrix[destination][origin] = distance;
	}
	else if(kind == 1){
		sidewayMatrix[origin][destination] = distance;
		sidewayMatrix[origin][destination] = distance;
	}
	else{
		return kindOftheWayUndefined;
	}
	return success;
}
kindOfError graph::deleteWay(string originName, string destinationName)
{
	int origin = findIndexOfthePlace(originName);
	int destination = findIndexOfthePlace(destinationName);
	if(origin == -1 || destination == -1){
		return placeUndefined;
	}
	
	if(roadMatrix[origin][destination] >= Infinity || sidewayMatrix[origin][destination] >= Infinity){
		return wayUndefined;
	}
	roadMatrix[origin][destination] = Infinity;
	sidewayMatrix[origin][destination] = Infinity;
	roadMatrix[destination][origin] = Infinity;
	sidewayMatrix[destination][origin] = Infinity;
	return success;
}
int pair_comp_func(pair <int, int> a, pair <int, int> b) {
	return a.second < b.second;
}

kindOfError graph::findShortestWay(string originName, string destinationName, kindOftheWay kind)
{
	int origin = findIndexOfthePlace(originName);
	int destination = findIndexOfthePlace(destinationName);
	if(origin == -1 || destination == -1){
		return placeUndefined;
	}
	if(kind == road){
		dijstra_sideway(origin,destination);
	}
	else if(kind == sideway){
		dijstra_road(origin,destination);
	}
	else{
		return kindOftheWayUndefined;
	}
	return success;
}

void graph::dijstra_road(int aim, int to){
	set <int> s;
	int dis[MAXN] = {};
	for (int i = 0; i < placeMaxNum; i++) {
		dis[i] = Infinity;
	}
	vector <int> road[MAXN];
	road[aim].push_back(aim);
	dis[aim] = 0;
	int now = aim;
	while (s.size() < placeMaxNum) {
		for (int i = 0; i < placeMaxNum; i++) {
			if (roadMatrix[now][i] && dis[now] + roadMatrix[now][i] < dis[i]) {
				dis[i] = roadMatrix[now][i] + dis[now];
				road[i] = road[now];
				road[i].push_back(i);
			}
		}
		s.insert(now);
		pair <int, int>  comper[MAXN];
		for (int i = 0; i < placeMaxNum; i++) {
			comper[i].first = i + 1;
			comper[i].second = dis[i + 1];
		}
		sort(comper, comper + placeMaxNum, pair_comp_func);
		for (int i = 0; i < placeMaxNum; i++) {
			if (!s.count(comper[i].first)) {
				now = comper[i].first;
				break;
			}
		}
	}
    if(dis[to] == Infinity){
        cout << "找不到路径\n";
    }
    else{
        cout << "长度:" << dis[to] << endl;
        cout << "路径:" << endl;
        for (int i = 0; i < road[to].size(); i++) {
            if (i)
                cout << "->";
            cout << findNameOfthePlace(road[to][i]);
        }
        cout << endl;
    }
}

void graph::dijstra_sideway(int aim, int to){
	set <int> s;
	int dis[MAXN] = {};
	for (int i = 0; i < placeMaxNum; i++) {
		dis[i] = Infinity;
	}
	vector <int> road[MAXN];
	road[aim].push_back(aim);
	dis[aim] = 0;
	int now = aim;
	while (s.size() < placeMaxNum) {
		for (int i = 0; i < placeMaxNum; i++) {
			if (sidewayMatrix[now][i] && dis[now] + sidewayMatrix[now][i] < dis[i]) {
				dis[i] = sidewayMatrix[now][i] + dis[now];
				road[i] = road[now];
				road[i].push_back(i);
			}
		}
		s.insert(now);
		pair <int, int>  comper[MAXN];
		for (int i = 0; i < placeMaxNum; i++) {
			comper[i].first = i + 1;
			comper[i].second = dis[i + 1];
		}
		sort(comper, comper + placeMaxNum, pair_comp_func);
		for (int i = 0; i < placeMaxNum; i++) {
			if (!s.count(comper[i].first)) {
				now = comper[i].first;
				break;
			}
		}
	}
    if(dis[to] == Infinity){
        cout << "找不到路径\n";
    }
    else{
        cout << "长度:" << dis[to] << endl;
        cout << "路径:" << endl;
        for (int i = 0; i < road[to].size(); i++) {
            if (i)
                cout << "->";
            cout << findNameOfthePlace(road[to][i]);
        }
        cout << endl;
    }
}
// void graph::dijstra_sideway(int origin){
// 	for(int i = 0;i<MAXN;i++){
// 		visited[i] = false;
// 	}
// 	for(int i = 0;i<placeMaxNum;i++){
// 		for(int j = 0;j<placeMaxNum;j++){
// 			if(sidewayMatrix[i][j] == 0){
// 				sidewayMatrix[i][j] = Infinity;
// 			}
// 		}
// 	}
// 	visited[origin] = true;
// 	for(int i = 0;i<placeMaxNum;i++){
// 		if(origin == i){
// 			dijstra_result[i] = Infinity;
// 		}
// 		else if(sidewayMatrix[origin][i] == 0){
// 			dijstra_result[i] = Infinity;
// 		}
// 		else{
// 			dijstra_result[i] = sidewayMatrix[origin][i];
// 		}
// 	}
// 	// cout << "test"<<endl;
// 	// for(int i = 0;i<placeMaxNum;i++){
// 	// 	cout << dijstra_result[i] << endl;
// 	// }
// 	// cout << "end" <<endl;
// 	for(int i = 0;i<placeMaxNum;i++){
// 		vector<int> onepath;
// 		onepath.push_back(origin);
// 		dijstra_route.push_back(onepath);
// 	}
// 	for(int num = 0;num < placeMaxNum;num++){
// 		int min = Infinity;
// 		int temp = 0;
// 		for(int i = 0;i<placeMaxNum;i++){
// 			if(visited[i] == false && dijstra_result[i] < min){
// 				min = dijstra_result[i];
// 				temp = i;
// 			}
// 		}
// 		// cout << "temp = "<< temp <<endl;


// 		dijstra_route[temp].push_back(temp);
// 		visited[temp] = true;
// 		for(int i = 0;i<placeMaxNum;i++){
// 			if(visited[i] == false && dijstra_result[temp] + sidewayMatrix[temp][i] < dijstra_result[i]){
// 				dijstra_result[i] = dijstra_result[temp] + sidewayMatrix[temp][i];
// 				// dijstra_route[i-1].push_back(temp);
// 				for(int k = 1;k<dijstra_route[temp].size();k++){
// 					dijstra_route[i].push_back(dijstra_route[temp][k]);
// 				}
// 			}
// 		}
// 		// cout << "test"<<endl;
// 		// for(int i = 0;i<placeMaxNum;i++){
// 		// 	cout << dijstra_result[i] << endl;
// 		// }
// 		// cout << "end" <<endl;
// 	}
// }

// void graph::dijstra_road(int origin){
// 	for(int i = 0;i<MAXN;i++){
// 		visited[i] = false;
// 	}
// 	for(int i = 0;i<placeMaxNum;i++){
// 		for(int j = 0;j<placeMaxNum;j++){
// 			if(roadMatrix[i][j] == 0){
// 				roadMatrix[i][j] = Infinity;
// 			}
// 		}
// 	}
// 	visited[origin] = true;
// 	for(int i = 0;i<placeMaxNum;i++){
// 		if(origin == i){
// 			dijstra_result[i] = Infinity;
// 		}
// 		else if(roadMatrix[origin][i] == 0){
// 			dijstra_result[i] = Infinity;
// 		}
// 		else{
// 			dijstra_result[i] = roadMatrix[origin][i];
// 		}
// 	}
// 	// cout << "test"<<endl;
// 	// for(int i = 0;i<placeMaxNum;i++){
// 	// 	cout << dijstra_result[i] << endl;
// 	// }
// 	// cout << "end" <<endl;
// 	for(int i = 0;i<placeMaxNum;i++){
// 		vector<int> onepath;
// 		onepath.push_back(origin);
// 		dijstra_route.push_back(onepath);
// 	}
// 	for(int num = 0;num < placeMaxNum;num++){
// 		int min = Infinity;
// 		int temp = 0;
// 		for(int i = 0;i<placeMaxNum;i++){
// 			if(visited[i] == false && dijstra_result[i] < min){
// 				min = dijstra_result[i];
// 				temp = i;
// 			}
// 		}
// 		// cout << "temp = "<< temp <<endl;


// 		dijstra_route[temp].push_back(temp);
// 		visited[temp] = true;
// 		for(int i = 0;i<placeMaxNum;i++){
// 			if(visited[i] == false && dijstra_result[temp] + roadMatrix[temp][i] < dijstra_result[i]){
// 				dijstra_result[i] = dijstra_result[temp] + roadMatrix[temp][i];
// 				// dijstra_route[i-1].push_back(temp);
// 				for(int k = 1;k<dijstra_route[temp].size();k++){
// 					dijstra_route[i].push_back(dijstra_route[temp][k]);
// 				}
// 			}
// 		}
// 		// cout << "test"<<endl;
// 		// for(int i = 0;i<placeMaxNum;i++){
// 		// 	cout << dijstra_result[i] << endl;
// 		// }
// 		// cout << "end" <<endl;
// 	}
// }
int graph::getPlaceNum()
{
	return placeNum;
}

void graph::setPlaceNum(int placeNum){
	this->placeNum = placeNum;
}

void graph::showRoadMatrix(){
	cout << "ROAD:" <<endl;
	for(int i = 0;i<getPlaceMaxNum();i++){
		for(int j = 0;j<getPlaceMaxNum();j++){
			if(j == getPlaceMaxNum()-1){
				cout << roadMatrix[i][j] << endl;
			}
			else{
				cout << roadMatrix[i][j] << "\t";
			}
		}
	}
}

void graph::showSideWayMatrix(){
	cout << "SIDEWAY" <<endl;
	for(int i = 0;i<getPlaceMaxNum();i++){
		for(int j = 0;j<getPlaceMaxNum();j++){
			if(j == getPlaceMaxNum()-1){
				cout << sidewayMatrix[i][j] << endl;
			}
			else{
				cout << sidewayMatrix[i][j] << "\t";
			}
		}
	}
}

int graph::getPlaceMaxNum(){
	return placeMaxNum;
}

void graph:: setPlaceMaxNum(int placeMaxNum){
	this->placeMaxNum = placeMaxNum;
}

kindOfError graph::showInfo(string placeName){
	for(int i = 0;i<places.size();i++){
		if(places[i].placeName == placeName){
			cout << places[i].info <<endl;
			return success;
		}
	}
	return placeUndefined;
}


int graph::findIndexOfthePlace(string placeName){
	for(int i = 0;i<places.size();i++){
		if(places[i].placeName == placeName){
			return places[i].key;
		}
	}
	return -1;
}

string graph::findNameOfthePlace(int placeIndex){
	string result = "";
	for(int i = 0;i<places.size();i++){
		if(places[i].key == placeIndex){
			return places[i].placeName;
		}
	}
	return result;
}