#pragma once
#include "BaseEnemy.h"
#include <KamataEngine.h>

using namespace KamataEngine;

class BaseEnemy;

class GameScene {
public:
	// コンストラクタ
	GameScene();
	// デストラクタ
	~GameScene();

	// 初期化
	void Initialze();

	// 毎フレーム処理
	void Update();

	// 描画
	void Draw();

	// メンバ変数
	int timer = 0;

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// モデル
	Model* model_ = nullptr;

	// ビュープロ(カメラ)
	Camera camera_;

	// プレイヤー
	std::list<BaseEnemy*> enemies_;
	BaseEnemy* baseEnemy_ = nullptr;

};