#include "BaseEnemy.h"
#include "Affin.h"
#include "MathUtility.h"
#include "imgui.h"
#include "math/Vector3.h"
#include <cassert>
#include "GameScene.h"

void BaseEnemy::Initialize(KamataEngine::Model* model, uint32_t textureHandle, Vector3 position, 
	KamataEngine::Camera* camera) {
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;
	camara_ = camera;
	//gameScene_ = gameScene;

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	// シングルトンインスタンスを取得
	input_ = KamataEngine::Input::GetInstance();
}

void BaseEnemy::Update() {
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();

	// キャラクターの移動ベクトル
	Vector3 move = {0, 0, 0};

	// キャラクターの移動速度
	const float kCharacterSpeed = 0.2f;
	move.x -= kCharacterSpeed;

//	if (gameScene_.timer <= 100) {
//
//		move.x -= kCharacterSpeed;
//	}
//	if (gameScene_.timer >= 100) {
//
//		move.y -= kCharacterSpeed;
////	}

	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_

	);

	// 移動
	worldTransform_.translation_ += move;
}

void BaseEnemy::Draw() { model_->Draw(worldTransform_, *camara_, textureHandle_); }
