#pragma once

#include "scene.h"
#include "partsys.h"
#include "text.h"
#include "rototext.h"

constexpr float stage_duration = 3.0f;

enum INTRO_STAGES {
    OVERSEER_CLOSE_EYES,
	SHOW_ARROWS,
	GAME
};

struct SceneMain : Scene {
	INTRO_STAGES curr_stage;
	float time_until_next_stage = stage_duration;
	Text close_eyes_text;

	Text textTime;
	bool gameover;
	
	float gametime;
	RotoText rotoText;

	int num_goals;

	SceneMain();

	void EnterScene() override;
	void ExitScene() override;
	void Update(float dt) override;
	void Draw() override;

	void SpawnCity();
	void BPS(veci min, veci max, int level);
};
