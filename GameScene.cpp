#include "GameScene.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {

	delete model_;
	delete baseEnemy_;
}

class BaseEnemy;

void GameScene::Initialze() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources/cube/cube.jpg");

	// 3Dモデルの生成
	model_ = Model::Create();

	// カメラの初期化
	camera_.Initialize();

	if (timer <= 100) {
		for (uint32_t i = 0; i < 300; i++) {

			baseEnemy_ = new BaseEnemy();
			baseEnemy_->Initialize(model_, textureHandle_, {(float)i * 18, 20, 0}, &camera_);
			enemies_.push_back(baseEnemy_);
			
		}
	}
}
	
void GameScene::Update() {

	timer++;
	// 自キャラの更新
	for (BaseEnemy* enemy_ : enemies_) {

		enemy_->Update();
	}
	
	if (timer >= 110) {

		timer = 0;
	}
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);
	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	// 自キャラの描画
	if (timer <= 100) {
		for (BaseEnemy* enemy_ : enemies_) {

			enemy_->Draw();
		}
	}
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);
	// スプライト描画後処理
	Sprite::PostDraw();
}
