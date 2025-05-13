#include<iostream>
#include<deque>

using namespace std;

void cardDown(deque<int>& ground, deque<int>& player) {
	// ī�� ��������
	ground.push_back(player.back());
	player.pop_back();
}

void getGroundCard(deque<int>& ground, deque<int>& player) {
	// �׶��忡�� ī�� ��������
	while (!ground.empty()) {
		player.push_front(ground.front());
		ground.pop_front();
	}
}

string playNumHalli(deque<int>& dodo, deque<int>& suyeon, int limit_play_num) {
	//������ ������ �׶���
	deque<int> dodo_ground;
	deque<int> suyeon_ground;

	bool turn_check = true; //true : dodo, false : suyeon
	int cnt_game = 1; //����� ���� Ƚ��

	while (true) {

		// ī�� ��������
		if (turn_check) {
			cardDown(dodo_ground, dodo);
		}
		else {
			cardDown(suyeon_ground, suyeon);
		}

		// ���� ������ ������ ī�尡 ���ٸ� ���� ���� �� ����� ����
		if (dodo.empty()) {
			return "su";
		}
		else if (suyeon.empty()) {
			return "do";
		}

		// �׶��� ī���� ���� 5�̸� �����̰� ī�� ��������
		if (!dodo_ground.empty() && !suyeon_ground.empty() && dodo_ground.back() + suyeon_ground.back() == 5) {
			getGroundCard(dodo_ground, suyeon);
			getGroundCard(suyeon_ground, suyeon);
		}
		//��� ������ �׶��尡 5�̸� ������ ī�� ��������
		else if (!dodo_ground.empty() && dodo_ground.back() == 5 || !suyeon_ground.empty() && suyeon_ground.back() == 5) {
			getGroundCard(suyeon_ground, dodo);
			getGroundCard(dodo_ground, dodo);
		}

		//������ ����� Ƚ���� ���ѿ� �ٴٸ��� ���� �̰���� ���� ī�� ���� �������� �Ǵ�
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

		cnt_game++; //���� ����Ƚ�� +1
		turn_check = !turn_check; //���� ���� �ٲ��ֱ�
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