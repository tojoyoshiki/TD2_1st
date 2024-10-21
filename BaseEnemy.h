#pragma once
#include <3d/Model.h>
#include <3d/WorldTransform.h>
#include <input/Input.h>
#include <3d/Camera.h>
#include "GameScene.h"

class BaseEnemy {

public:
	void Initialize(KamataEngine::Model* model, uint32_t textureHandle, KamataEngine::Vector3 position, KamataEngine::Camera* camera);
	void Update();
	void Draw();
	// データ取得設定
	const KamataEngine::WorldTransform& GetWorldTransform() { return worldTransform_; }

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	// キー入力
	KamataEngine::Input* input_ = nullptr;

	KamataEngine::Camera* camara_ = nullptr;

	//GameScene& gameScene_;
};