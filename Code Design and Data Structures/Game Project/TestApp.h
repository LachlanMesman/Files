#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <glm\vec2.hpp>

class TestApp : public aie::Application {
public:

	TestApp();
	virtual ~TestApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_ship;
	aie::Texture*		m_circle;
	glm::vec2*			m_shipPos;
	glm::vec2*			m_circlePos;
	float playerAngle;
	bool shoot = false;
	bool space = false;
	float m_timer;
	int i;
};