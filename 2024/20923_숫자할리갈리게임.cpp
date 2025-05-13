#include<iostream>
#include<deque>

using namespace std;

void cardDown(deque<int>& ground, deque<int>& player) {
	// 카드 내려놓기
	ground.push_back(player.back());
	player.pop_back();
}

void getGroundCard(deque<int>& ground, deque<int>& player) {
	// 그라운드에서 카드 가져오기
	while (!ground.empty()) {
		player.push_front(ground.front());
		ground.pop_front();
	}
}

string playNumHalli(deque<int>& dodo, deque<int>& suyeon, int limit_play_num) {
	//수연과 도도의 그라운드
	deque<int> dodo_ground;
	deque<int> suyeon_ground;

	bool turn_check = true; //true : dodo, false : suyeon
	int cnt_game = 1; //진행된 게임 횟수

	while (true) {

		// 카드 내려놓기
		if (turn_check) {
			cardDown(dodo_ground, dodo);
		}
		else {
			cardDown(suyeon_ground, suyeon);
		}

		// 만약 도도나 수연의 카드가 없다면 게임 종료 및 우승자 리턴
		if (dodo.empty()) {
			return "su";
		}
		else if (suyeon.empty()) {
			return "do";
		}

		// 그라운드 카드의 합이 5이면 수연이가 카드 가져오기
		if (!dodo_ground.empty() && !suyeon_ground.empty() && dodo_ground.back() + suyeon_ground.back() == 5) {
			getGroundCard(dodo_ground, suyeon);
			getGroundCard(suyeon_ground, suyeon);
		}
		//어느 한쪽의 그라운드가 5이면 도도가 카드 가져오기
		else if (!dodo_ground.empty() && dodo_ground.back() == 5 || !suyeon_ground.empty() && suyeon_ground.back() == 5) {
			getGroundCard(suyeon_ground, dodo);
			getGroundCard(dodo_ground, dodo);
		}

		//게임이 진행된 횟수가 제한에 다다르면 누가 이겼는지 남은 카드 수를 기준으로 판단
		if (cnt_game == limit_play_num) {
			if (dodo.size() < suyeon.size()) 
			{
				return "su";
			}
			else if( dodo.size() > suyeon.size()) 
			{
				return "do";
			}
			else {
				return "dosu";
			}
			break;
		}

		cnt_game++; //게임 진행횟수 +1
		turn_check = !turn_check; //게임 순서 바꿔주기
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	deque<int> dodo(n, 0);
	deque<int> suyeon(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> dodo[i] >> suyeon[i];
	}

	cout << playNumHalli(dodo, suyeon, m);
	
	return 0;
}