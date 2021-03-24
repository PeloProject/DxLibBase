#pragma once
class SceneBase
{

public:
	// デフォルトコンストラクタ
	SceneBase() {}

	// デストラクタ
	virtual ~SceneBase() {}

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

