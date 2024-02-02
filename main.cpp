#include <Novice.h>
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneClear.h"
#include "SceneGameover.h"

enum SceneNo {
	TITLE,
	GAME,
	CLEAR,
	GAMEOVER
};

int sceneNo = SceneNo(TITLE);

const char kWindowTitle[] = "LC1B_18_ナガトモイチゴ_評価課題2_クラス化確認し隊";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//宣言
	SceneTitle *title = new SceneTitle();
	SceneGame *game = new SceneGame();
	SceneClear *clear = new SceneClear();
	SceneGameover *gameover = new SceneGameover();

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// 各シーンの更新
		switch (sceneNo) {
			///================================================================================================
			///Title
			///================================================================================================
			case TITLE:
				game->Init();
				clear->Init();
				gameover->Init();
				title->Update(keys , preKeys);

				if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
					sceneNo = GAME;
				}
				break;

			///================================================================================================
			///Game
			///================================================================================================
			case GAME:
				title->Init();
				game->Update(keys , preKeys);

				if (!game->GetEnemyIsAlive()) {
					sceneNo = CLEAR;
				} else if (!game->GetPlayerIsAlive()) {
					sceneNo = GAMEOVER;
				}
				break;

			///================================================================================================
			///Clear
			///================================================================================================
			case CLEAR:
				clear->Update(keys , preKeys);

				if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
					sceneNo = TITLE;
				}
				break;

			///================================================================================================
			///Gameover
			///================================================================================================
			case GAMEOVER:
				gameover->Update(keys , preKeys);

				if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
					sceneNo = TITLE;
				}
				break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 各シーンの描画
		switch (sceneNo) {
			case TITLE:
				title->Draw();

				break;

			case GAME:
				game->Draw();

				break;

			case CLEAR:
				clear->Draw();

				break;

			case GAMEOVER:
				gameover->Draw();

				break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete title;
	delete game;
	delete clear;
	delete gameover;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
